#ifndef _SORT_H_
#define _SORT_H_

#include "main.h"

void bubble_sorted_keys(cars_key_t *keys, size_t size);
void qsort_sorted_keys(cars_key_t *keys, int first, int last);
void qsort_sorted_cars(cars_t *cars, int first, int last);
void bubble_sorted_cars(cars_t *cars, size_t size);
void swap_el_keys(cars_key_t *first, cars_key_t *second);
void swap_el_cars(cars_t *first, cars_t *second);

#endif
