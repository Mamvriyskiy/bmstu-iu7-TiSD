#include <stdio.h>
#include <time.h>
#include "main.h"
#include "text.h"
#include "print_data.h"
#include "read_file.h"
#include "filter.h"
#include "sort.h"

int main()
{
    FILE *file = fopen("data.txt", "r"); //открытие файла с проверкой 
    if (!file)
    {
        printf("Ошибка в открытии файла.");
        return -1;
    }

    print_rules(); //Вывод правил

    size_t cars_count = 0;
    if (fscanf(file, "%zu", &cars_count) != 1) //считывнаие количесвта структур из файла с проверкой
    {
        printf("Неверное количесвто машин.");
        return -1;
    }
    
    if (cars_count <= 0 || cars_count > 50)
    {
        printf("Неверное количесвто машин.");
        return -1;
    }

    cars_t cars[CARS_COUNT_MAX];
    cars_key_t keys[CARS_COUNT_MAX];

    if (read_data(file, cars_count, cars, keys) != 0) //чтение структур в массив структур 
        return -1;

    int exite_code = 0;

    print_menu();
    printf("\nВыберите номер операции: ");
    scanf("%d", &exite_code);

    clock_t start, end;

    while (exite_code) //цикл программы
    {
        switch (exite_code)
        {
            case 1:
                start = clock();
                bubble_sorted_cars(cars, cars_count);
                end = clock();
                printf("Время сортировки: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            case 2:
                start = clock();
                bubble_sorted_keys(keys, cars_count);
                end = clock();
                printf("Время сортировки: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            case 3:
                start = clock();
                inserts_sorted_cars(cars, cars_count);
                end = clock();
                printf("Время сортировки: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            case 4:
                start = clock();
                inserts_sorted_keys(keys, cars_count);
                end = clock();
                printf("Время сортировки: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            case 5:
                if (cars_count + 1 > 50)
                {
                    printf("Нелья добавить информацию. (Максимальное количество 50).");
                    break;
                }
                if (add_new_struct(cars, keys, &cars_count) != 0)
                {
                    cars_count--;
                    printf("Данные о новой машине введены неверно");
                }
                break;
            case 6:
                printf("Введите номер строки таблицы для удаления: ");
                size_t position = 0;
                if (scanf("%zu", &position) != 1)
                {
                    printf("Данные введены неверно");
                    continue;
                }
                if (position >= cars_count)
                {
                    printf("Указаная позиция больше количества строк таблицы");
                    continue;
                }
                delete_cars(cars, keys, position, &cars_count);
                break;
            case 7:
                print_table(cars, cars_count);
                break;
            case 8:
                print_all_keys(keys, cars_count);
                break;
            case 9:
                print_all_cars_by_keys(cars, keys, cars_count);
                break;
            case 10:
                printf("\n");
                unsigned int a = 0;
                unsigned int b = 0;
                char brand[MAX_STR_LEN_BRAND];
                if (read_price(&a, &b) != 0)
                    break;
                printf("\nВведите название бренда: ");
                if (scanf("%s", brand) != 1)
                    break;
                filter_search_car(cars, a, b, brand, cars_count);
                break;
            case 11:
                print_rules();
                printf("\n");
                break;
            default: 
                printf("\nДанные введены неверно\n");
                break;
        }
        print_menu();
        printf("\nВыберите номер операции: ");
        if (scanf("%d", &exite_code) != 1)
        {
            exite_code = 0;
            printf("\nДанные введены неверно");
        }
    }
    return 0;
}
