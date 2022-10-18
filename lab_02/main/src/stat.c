#include <stdio.h>
#include <time.h>
#include <string.h>
#include "stat.h"
#include "print_data.h"
#include "sort.h"


void print_stat(cars_t *cars, cars_key_t *keys, size_t cars_count, size_t cars_size, size_t keys_size)
{
    clock_t start, end;
    double bubble_sort_cars, bubble_sort_keys, q_sort_cars, q_sort_keys;

    cars_t array_a_cars[CARS_COUNT_MAX];
    cars_t array_b_cars[CARS_COUNT_MAX];
    cp_cars_array(cars, array_a_cars, array_b_cars, cars_count);
    
    start = clock(); //замерка bubble сортировки таблицы
    bubble_sorted_cars(array_a_cars, cars_count);
    end = clock();
    bubble_sort_cars = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время bubble сортировки таблицы: %fc\n", bubble_sort_cars);

    start = clock(); //замерка быстрой сортировки таблицы
    qsort_sorted_cars(array_b_cars, 0, cars_count - 1);
    end = clock();
    q_sort_cars = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время быстрой сортировки таблицы: %fc\n", q_sort_cars);

    cars_key_t array_a_keys[CARS_COUNT_MAX];
    cars_key_t array_b_keys[CARS_COUNT_MAX];
    cp_keys_array(keys, array_a_keys, array_b_keys, cars_count);

    start = clock(); //замерка bubble сортировки ключей
    bubble_sorted_keys(array_a_keys, cars_count);
    end = clock();
    bubble_sort_keys = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время bubble сортировки ключей: %fc\n", bubble_sort_keys);

    start = clock(); //замерка быстрой сортировки ключей
    qsort_sorted_keys(array_b_keys, 0, cars_count - 1);
    end = clock();
    q_sort_keys = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время быстрой сортировки ключей: %fc\n", q_sort_keys);

    printf("\n");
    printf("Отношение bubble сортировок: %f%%\n", (bubble_sort_cars - bubble_sort_keys) / bubble_sort_keys * 100);
    printf("Отношение быстрой сортировок: %f%%\n", (q_sort_cars - q_sort_keys) / q_sort_keys * 100);
    printf("Отношение bubble quick по таблице: %f%%\n",  (bubble_sort_cars - q_sort_cars) / q_sort_cars * 100);
    printf("Отношение bubble quick по ключу: %f%%\n", (bubble_sort_keys - q_sort_keys) / q_sort_keys * 100);
    printf("\n");
    printf("Обьем исходной таблицы: %zu\n", cars_size);
    printf("Обьем таблицы ключей: %zu\n", keys_size);
}

void cp_cars_array(cars_t *a, cars_t *b, cars_t *c, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        strcpy(b[i].brand, a[i].brand); //копирование бренда
        strcpy(c[i].brand, a[i].brand);
        strcpy(b[i].country, a[i].country); //копирование страны
        strcpy(c[i].country, a[i].country);
        b[i].price = a[i].price; //копирование цены
        c[i].price = a[i].price;
        strcpy(b[i].color, a[i].color); //копирование цвета
        strcpy(c[i].color, a[i].color);
        b[i].type = a[i].type; //копирование типа
        c[i].type = a[i].type;
        if (a[i].type == NEW)
        {
            b[i].car_type.new_car.garanty = a[i].car_type.new_car.garanty;
            c[i].car_type.new_car.garanty = a[i].car_type.new_car.garanty;
        }
        else
        {
            b[i].car_type.old_car.year = a[i].car_type.old_car.year; //копирование года
            c[i].car_type.old_car.year = a[i].car_type.old_car.year;
            b[i].car_type.old_car.mileage = a[i].car_type.old_car.mileage; //копирование пробега
            c[i].car_type.old_car.mileage = a[i].car_type.old_car.mileage;
            b[i].car_type.old_car.count_repair = a[i].car_type.old_car.count_repair; //копирование количества ремонтов
            c[i].car_type.old_car.count_repair = a[i].car_type.old_car.count_repair; 
            b[i].car_type.old_car.count_owner = a[i].car_type.old_car.count_owner; //копирование количества владельцев
            c[i].car_type.old_car.count_owner = a[i].car_type.old_car.count_owner;
        }
    }
}

void cp_keys_array(cars_key_t *a, cars_key_t *b, cars_key_t *c, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        b[i].index = a[i].index; //копирование индекса
        c[i].index = a[i].index;
        b[i].price = a[i].price; //копирование цены
        c[i].price = a[i].price;
    }
}

