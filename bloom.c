#include "bloom.h"
#include "hash.h"

Bloom *bloom_init(size_t bucket_size) {
  Bloom *b = malloc(sizeof(Bloom));
  b->bucket = malloc(sizeof(int) * bucket_size);
  b->bucket_size = bucket_size;
  return b;
}

void bloom_add(Bloom * bloom, const void *key, size_t len, uint32_t seed) {
  uint32_t hash1 = murmur(key, len, seed);
  uint32_t hash2 = fnv1s(key, len);

  int bucket_size = bloom->bucket_size;

  int a = get_bucket(hash1, bucket_size);
  int b = get_bucket(hash2, bucket_size);

  bloom->bucket[a] = 1;
  bloom->bucket[b] = 1;
}

bool bloom_check(Bloom *bloom, const void *key, size_t len, uint32_t seed) {
  uint32_t hash1 = murmur(key, len, seed);
  uint32_t hash2 = fnv1s(key, len);

  int bucket_size = bloom->bucket_size;
  
  int a = get_bucket(hash1, bucket_size);
  int b = get_bucket(hash2, bucket_size);

  return (bloom->bucket[a] == 1 && bloom->bucket[b] == 1);
}
