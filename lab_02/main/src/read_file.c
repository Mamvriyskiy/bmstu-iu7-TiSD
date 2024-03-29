#include <stdio.h>
#include "read_file.h"

//заполнение массива структур чтением из файла
int read_data(FILE *file, size_t cars_count, cars_t *cars, cars_key_t *keys)
{
    for (size_t i = 0; i < cars_count; i++)
    {
        keys[i].index = i;
        if (fscanf(file, "%s\n", cars[i].brand) != 1) //считывание бренда машины
            return -1;
        if (fscanf(file, "%s\n", cars[i].country) != 1) //считывание страны
            return -1;
        if (fscanf(file, "%d\n", &cars[i].price) != 1 || cars[i].price < 0) // считывание цены
            return -1;
        keys[i].price = cars[i].price;
        if (fscanf(file, "%s\n", cars[i].color) != 1) // считывание цвета
            return -1;
        int type_car = 0; 
        if (fscanf(file, "%d", &type_car) != 1)
            return -1;
        if (type_car == 0)
        {
            cars[i].type = NEW;
            if (fscanf(file, "%d\n", &cars[i].car_type.new_car.garanty) != 1 || cars[i].car_type.new_car.garanty < 0) //Гарантия
                return -1;
        }
        else
        {
            cars[i].type = OLD;
            if (fscanf(file, "%d\n", &cars[i].car_type.old_car.year) != 1 || cars[i].car_type.old_car.year < 0) //год выпуска
                return -1;
            if (fscanf(file, "%d\n", &cars[i].car_type.old_car.mileage) != 1 || cars[i].car_type.old_car.mileage < 0) //пробег
                return -1;
            if (fscanf(file, "%d\n", &cars[i].car_type.old_car.count_repair) != 1 || cars[i].car_type.old_car.count_repair < 0) //количество ремонтов
                return -1;
            if (fscanf(file, "%d\n", &cars[i].car_type.old_car.count_owner) != 1 || cars[i].car_type.old_car.count_owner < 0) //количесвто владельцев
                return -1;
        }
    }
    return 0;
}

//Ввод диапазона цены
int read_price(int *a, int *b)
{
    printf("Введите диапазон цены.\n");
    printf("Значение a: ");
    if (scanf("%u", a) != 1 || *a < 0)
    {
        printf("Данные введены неверно.\n");
        return -1;
    }
    printf("Значение b: ");
    if (scanf("%u", b) != 1 || *b < 0)
    {
        printf("Данные введены неверно.\n");
        return -1;
    }
    
    if (*a >= *b)
    {
        printf("Введен неверный диапазон.\n");
        return -1;
    }
    return 0;
}
