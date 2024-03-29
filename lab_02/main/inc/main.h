#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_STR_LEN_BRAND 26
#define MAX_STR_LEN_COUNTRY 26
#define MAX_STR_LEN_COLOR 26
#define CARS_COUNT_MAX 100

//Состояние машины - новая, старая
typedef enum 
{
    NEW, 
    OLD
} car_type_t;

//Гарантия, если машина новая 
typedef struct 
{
    int garanty;
} new_car_t;


//Данные, елси машина старая
typedef struct 
{
    int year;
    int mileage;
    int count_repair;
    int count_owner;
} old_car_t;

//общая структура 
typedef struct 
{
    char brand[MAX_STR_LEN_BRAND];
    char country[MAX_STR_LEN_COUNTRY];
    int price;
    char color[MAX_STR_LEN_COLOR];
    car_type_t type;
    union
    {
       new_car_t new_car;
       old_car_t old_car;
    } car_type; 
} cars_t;

//Стурктура ключей и цен
typedef struct 
{
    size_t index;
    int price;
} cars_key_t;

#endif
