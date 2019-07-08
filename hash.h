#include "utils.h"

#ifndef HASH_H
#define HASH_H

#include <time.h>

void print_bits(uint32_t key);

uint32_t murmur(const void *, size_t, uint32_t);
uint32_t fnv1s(const void *, size_t);

int get_bucket(uint32_t, int);

#endif
