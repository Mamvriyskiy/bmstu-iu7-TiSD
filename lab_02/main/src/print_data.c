#include <stdio.h>
#include "print_data.h"

//Вывод таблицы без ключей
void print_table(cars_t *cars, size_t n)
{
    printf("\n");
    print_header_for_cars();
    for (size_t i = 0; i < n; i++)
    {
        printf("| %3zu ", i);
        print_car(cars[i]);
        printf("\n");
    }
}

//Вывод заголовка таблицы
void print_header_for_cars()
{
    printf("| %s ", "  №");
    printf("| %20s ", "BRAND");
    printf("| %20s ", "COUTRY");
    printf("| %10s ", "PRICE");
    printf("| %15s ", "COLOR");
    printf("| %6s ", "NEW");
    printf("| %15s ", "GARANTY");
    printf("| %20s ", "RELEASE YEAR");
    printf("| %15s ", "MILEAGE");
    printf("| %15s ", "REPAIR AMOUNT");
    printf("| %15s |", "OWNER AMOUNT");
    printf("\n");
}

//Вывод строки таблицы
void print_car(cars_t car)
{
    printf("| %20s ", car.brand);
    printf("| %20s ", car.country);
    printf("| %10d ", car.price);
    printf("| %15s ", car.color);
    if (car.type == NEW)
    {
        printf("| %6s ", "+");
        printf("| %15d ", car.car_type.new_car.garanty);
        printf("| %20s ", "-");
        printf("| %15s ", "-");
        printf("| %15s ", "-");
        printf("| %15s ", "-");
    }
    else
    {
        printf("| %6s ", "-");
        printf("| %15s ", "-");
        printf("| %20d ", car.car_type.old_car.year);
        printf("| %15d ", car.car_type.old_car.mileage);
        printf("| %15d ", car.car_type.old_car.count_repair);
        printf("| %15d |", car.car_type.old_car.count_owner);
    }
    printf("\n");
}

//Вывод заголовка таблицы ключей
void print_header_for_keys()
{
    printf("| %s ", "  №");
    printf("| %10s ", "INDEX");
    printf("| %10s |", "PRICE");
    printf("\n");
}

//Вывод таблицы машин по ключам
void print_all_cars_by_keys(cars_t *cars, cars_key_t *keys, size_t size)
{
    printf("\n");
    print_header_for_cars();
    for (size_t i = 0; i < size; i++)
    {
        printf("| %3zu", i);
        print_car(cars[keys[i].index]);
        printf("\n");
    }
}

void print_all_keys(cars_key_t *keys, size_t size)
{
    printf("\n");
    print_header_for_keys();
    for (size_t i = 0; i < size; i++)
    {
        printf("| %3zu", i);
        print_key(&keys[i]);
        printf("\n");
    }
}

//Вывод строки таблицы ключей
void print_key(cars_key_t *keys)
{
    printf("| %10zu ", keys->index);
    printf("| %10d |", keys->price);
}
