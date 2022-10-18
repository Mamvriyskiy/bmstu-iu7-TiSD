#ifndef _STAT_H_
#define _STAT_H_

#include "main.h"

void print_stat(cars_t *cars, cars_key_t *keys, size_t cars_count, size_t cars_size, size_t keys_size);
void cp_cars_array(cars_t *a, cars_t *b, cars_t *c, size_t size);
void cp_keys_array(cars_key_t *a, cars_key_t *b, cars_key_t *c, size_t size);

#endif

