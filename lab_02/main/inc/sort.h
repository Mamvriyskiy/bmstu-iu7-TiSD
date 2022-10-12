#ifndef _SORT_H_
#define _SORT_H_

#include "main.h"

void bubble_sorted_keys(cars_key_t *keys, size_t size);
void inserts_sorted_keys(cars_key_t *keys, size_t size);
void inserts_sorted_cars(cars_t *cars, size_t size);
void bubble_sorted_cars(cars_t *cars, size_t size);
void swap_el_keys(cars_key_t *first, cars_key_t *second);
void swap_el_cars(cars_t *first, cars_t *second);

#endif
