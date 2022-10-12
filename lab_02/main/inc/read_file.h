#ifndef _READ_FILE_H_
#define _READ_FILE_H_

#include "main.h"

int read_data(FILE *file, size_t cars_count, cars_t *cars, cars_key_t *keys);
int read_price(unsigned int *a, unsigned int *b);

#endif
