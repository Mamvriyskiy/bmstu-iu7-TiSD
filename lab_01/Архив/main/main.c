#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "error.h"
#include "check_number.h"
#include "func.h"
#include "division.h"

int main()
{
    number_t first_number = STRUCT_INIT;
    number_t second_number = STRUCT_INIT;
    number_t result_number = STRUCT_INIT;
    int error = OK;
    char first_str_number[LEN_NUMBER];
    printf("Введите первое число:\n");
    printf("1        10        20       30 e\n");
    printf("|--------|---------|---------|-|-----|\n");
    fgets(first_str_number, sizeof(first_str_number), stdin);
    error = check_number(first_str_number);
    if (error != OK)
        return error;
    printf("Введите второе число:\n");
    printf("1        10        20       30 e\n");
    printf("|--------|---------|---------|-|-----|\n");
    char second_str_number[LEN_NUMBER];
    fgets(second_str_number, sizeof(second_str_number), stdin);
    error = check_number(second_str_number);
    if (error != OK)
        return error;

    int lenl_order_first = 0;
    int lenl_mantissa_first = 0;
    int lenl_order_second = 0;
    int lenl_mantissa_second = 0;
    //Распределение чисел по структурам
    int exp = 0;

    exp += accumulation_struct_number(&first_number, first_str_number, &lenl_mantissa_first, &lenl_order_first); 

    exp += accumulation_struct_number(&second_number, second_str_number, &lenl_mantissa_second, &lenl_order_second); 

    if (check_zero(first_number.mantissa, lenl_mantissa_first) != OK)
    {
        printf("Result: +0.0e0");
        return OK;
    } 

    if (check_zero(second_number.mantissa, lenl_mantissa_second) != OK)
    {
        printf("Result: No division by zero");
        return -1;
    }


    exp += (creat_number(first_number.order, lenl_order_first) * first_number.second_sign_number \
        - creat_number(second_number.order, lenl_order_second) * second_number.second_sign_number);

    int r = lenl_mantissa_first - lenl_mantissa_second;
    if (r > 1)
        exp += r;

    division(first_number.mantissa, second_number.mantissa, result_number.mantissa, lenl_mantissa_first, lenl_mantissa_second, &exp);

    exp += 1;
    int lenl = without_zero(result_number.mantissa);
   
    result_number.first_sign_number = first_number.first_sign_number * second_number.first_sign_number;

    if (exp > 99999 || exp < -99999)
    {
        printf("Negative order");
        return -1;
    }
    result_number.order[0] = exp;
    if (error == OK)
        output_result(&result_number, 30 - lenl);
    else 
        printf("Невозможно подсчитать");
    return error;
}


