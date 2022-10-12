#include <stdio.h>
#include <string.h>
#include "filter.h"
#include "print_data.h"

void filter_search_car(cars_t *cars, unsigned int a, unsigned int b, char *brand, size_t size)
{
    int k = 0, flag = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(cars[i].brand, brand) != 0)
            continue;
        if (cars[i].car_type.old_car.count_owner != 1)
            continue;
        if (cars[i].car_type.old_car.count_repair != 0)
            continue;
        if (cars[i].price < a || cars[i].price > b)
            continue;
        k++;
        if (flag == 0)
        {
            flag = 1;
            print_header_for_cars();
            print_car(cars[i]);
        }

    }
    if (flag == 0)
        printf("\nМашины не найдены\n");
}

void delete_cars(cars_t *cars, cars_key_t *keys, size_t position, size_t *size)
{
    for (size_t i = position; i < *size - 1; i++)
        cars[i] = cars[i + 1];
    (*size)--;

    for (size_t j = 0; j < *size; j++)
    {
        if (j == position)
        {
            for (size_t k = position; k < *size - 1; k++)
                keys[k] = keys[k + 1];
            break;
        }
    }


}

int add_new_struct(cars_t *cars, cars_key_t *keys, size_t *size)
{
    (*size)++;
    size_t i = *size - 1;
    unsigned int price_car = 0;
    printf("\nBRAND: ");
    if (scanf("%s", cars[i].brand) != 1)
        return -1;
    printf("\nCOUTRY: ");
    if (scanf("%s", cars[i].country) != 1)
        return -1;
    printf("\nPRICE: ");
    if (scanf("%u", &price_car) != 1)
        return -1;
    else
        cars[i].price = price_car;
    printf("\nCOLOR: ");
    if (scanf("%s", cars[i].color) != 1)
        return -1;
    printf("\nNEW: ");
    int type = 0;
    if (scanf("%d", &type) != 1)
        return -1;
    if (type == 0)
    {
        printf("\nGARANTY: ");
        cars[i].type = NEW;
        if (scanf("%u", &cars[i].car_type.new_car.garanty) != 1)
            return -1;
    }
    else
    {
        printf("\nRELEASE YEAR: ");
        cars[i].type = OLD;
        if (scanf("%u", &cars[i].car_type.old_car.year) != 1)
            return -1;
        printf("\nMILEAGE: ");
        if (scanf("%u", &cars[i].car_type.old_car.mileage) != 1)
            return -1;
        printf("\nREPAIR AMOUNT: ");
        if (scanf("%u", &cars[i].car_type.old_car.count_repair) != 1)
            return -1;
        printf("\nOWNER AMOUNT: ");
        if (scanf("%u", &cars[i].car_type.old_car.count_owner) != 1)
            return -1;
    }
    
    keys[i].index = i;
    keys[i].price = price_car;


    return 0;
}
