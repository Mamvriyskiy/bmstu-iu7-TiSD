#ifndef _PRINT_DATA_H_
#define _PRINT_DATA_H_

#include "main.h"

void print_table();
void print_header_for_cars();
void print_car(cars_t car);
void print_all_cars_by_keys(cars_t *cars, cars_key_t *keys, size_t size);
void print_header_for_keys();
void print_all_keys(cars_key_t *keys, size_t size);
void print_key(cars_key_t *keys);

#endif
