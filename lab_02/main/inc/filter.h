#ifndef _FILTER_H_
#define _FILTER_H_

#include "main.h"

void filter_search_car(cars_t *cars, int a, int b, char *brand, size_t size);
void delete_cars(cars_t *cars, cars_key_t *keys, size_t position, size_t *size);
int add_new_struct(cars_t *cars, cars_key_t *keys, size_t *size);

#endif
