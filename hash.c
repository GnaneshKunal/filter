#include "hash.h"

void print_bits(uint32_t key) {;
  for (int i = 30; i >= 0; i--) {
    if (key & (1 << i)) printf("1");
    else printf("0");
  }
  puts("");
}

int get_bucket(uint32_t hash, int buckets) {
  return hash % buckets;
}

uint32_t fnv1s(const void *key, size_t len) {
  const uint64_t FNV_offset_basis =  0xcbf29ce484222325;

  const uint64_t FNV_prime = 0x100000001b3;

  uint64_t hash = FNV_offset_basis;

  const unsigned char *data = (unsigned char *)key;

  for (int i = 0; i < len; i++) {
    hash ^= data[i];
    hash *= FNV_prime;
  }

  return hash;
}

uint32_t murmur(const void *key, size_t len, uint32_t seed) {

  const unsigned int m = 0xc6a4a793;

  const int r = 16;

  unsigned int h = seed ^ (len * m);
  const unsigned char *data = (const unsigned char *)key;

  while (len >= 4) {

    unsigned int k = *data;

    h += k;

    h *= m;

    h ^= h >> r;

    data += 4;
    len -= 4;
  }

  switch(len) {
  case 3:
    h += data[2] << 16;
  case 2:
    h += data[1] << 8;
  case 1:
    h += data[0];
    h *= m;
    h ^= h >> r;
  };

  h *= m;
  h ^= h >> 10;
  h *= m;
  h ^= h >> 17;

  return h;
}
