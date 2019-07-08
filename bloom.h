#include "utils.h"

#ifndef BLOOM_H
#define BLOOM_H

typedef struct Bloom {
  int *bucket;
  size_t bucket_size;
} Bloom;

Bloom *bloom_init(size_t);
void bloom_add(Bloom *, const void *, size_t, uint32_t);
bool bloom_check(Bloom *, const void *, size_t, uint32_t);

#endif
