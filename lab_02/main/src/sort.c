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
void qsort_sorted_keys(cars_key_t *keys, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = keys[(left + right) / 2].price;
        do
        {
            while (keys[left].price < middle)
                left++;
            while (keys[right].price > middle)
                right--;
            if (left <= right)
            {
                cars_key_t buf = keys[left];
                keys[left] = keys[right];
                keys[right] = buf;
                left++;
                right--;
            }
        } while (left <= right);
        qsort_sorted_keys(keys, first, right);
        qsort_sorted_keys(keys, left, last);
    }
}

//Сортировка вставками таблицы машин по цене
void qsort_sorted_cars(cars_t *cars, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = cars[(left + right) / 2].price;
        do
        {
            while (cars[left].price < middle)
                left++;
            while (cars[right].price > middle)
                right--;
            if (left <= right)
            {
                cars_t buf = cars[left];
                cars[left] = cars[right];
                cars[right] = buf;
                left++;
                right--;
            }
        } while (left <= right);
        qsort_sorted_cars(cars, first, right);
        qsort_sorted_cars(cars, left, last);
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
