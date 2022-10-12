#include <stdio.h>
#include "sort.h"

//Cортировка пузырьком таблицы ключе по цене
void bubble_sorted_keys(cars_key_t *keys, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (keys[j].price > keys[j + 1].price)
                swap_el_keys(keys + j, keys + j + 1);
        }
    }
}

//Cортировка пузырьком таблицы машин по цене
void bubble_sorted_cars(cars_t *cars, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (cars[j].price > cars[j + 1].price)
                swap_el_cars(cars + j, cars + j + 1);
        }
    }
}

//Сортировка вставками таблицы ключе по цене
void inserts_sorted_keys(cars_key_t *keys, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (keys[j - 1].price > keys[j].price)
                swap_el_keys(keys + j - 1, keys + j);
            else 
                break;
        }
    } 
}

//Сортировка вставками таблицы машин по цене
void inserts_sorted_cars(cars_t *cars, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (cars[j - 1].price > cars[j].price)
                swap_el_cars(cars + j - 1, cars + j);
            else 
                break;
        }
    } 
}

//Смена местами элементов структур
void swap_el_keys(cars_key_t *first, cars_key_t *second)
{
    cars_key_t buf = *first;
    *first = *second;
    *second = buf;
}

//Смена местами элементов структур
void swap_el_cars(cars_t *first, cars_t *second)
{
    cars_t buf = *first;
    *first = *second;
    *second = buf;
}
