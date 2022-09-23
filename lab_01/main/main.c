#include <stdio.h>
#include "main.h"
#include "error.h"
#include "check_number.h"
#include "func.h"

int main()
{
    number_t first_number = STRUCT_INIT;
    number_t second_number = STRUCT_INIT;
    number_t result_number = STRUCT_INIT;
    int error = OK;
    char first_str_number[LEN_NUMBER];
    fgets(first_str_number, sizeof(first_str_number), stdin);
    error = check_number(first_str_number);
    if (error != OK)
        return error;

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
    int k_1 = 0, k_2 = 0;

    accumulation_struct_number(&first_number, first_str_number, &lenl_mantissa_first, &lenl_order_first, &k_1);  
    accumulation_struct_number(&second_number, second_str_number, &lenl_mantissa_second, &lenl_order_second, &k_2); 

    // printf("\n=%d=\n", k_1);
    // printf("\n=%d=\n", k_2);

    // printf("\n");
    // for (int i = 0; i < lenl_mantissa_first; i++)
    //     printf("%d", first_number.mantissa[i]);
    // printf("\n");

    // printf("\n");
    // for (int i = 0; i < lenl_mantissa_second; i++)
    //     printf("%d", second_number.mantissa[i]);
    // printf("\n");

    // Деление чисел
    int lenl_mantissa_result = 0;
    int last_num = division_number(first_number.mantissa, second_number.mantissa, \
        lenl_mantissa_first, lenl_mantissa_second, result_number.mantissa, &lenl_mantissa_result);

    int k = 0;
    // printf("%d", lenl_mantissa_result);
    // if (lenl_mantissa_result > 30)
    // {
    //     k = rounding(result_number.mantissa, lenl_mantissa_result);
    // }
    if (last_num < 0)
        return OK;
    without_zero(result_number.mantissa, &lenl_mantissa_result);

    error = make_result_number(&first_number, &second_number, &result_number, lenl_order_first, lenl_order_second, k_1, k_2, lenl_mantissa_result);

    // if (first_number.power_position == 0)
    //     first_number.order[0] += lenl_mantissa_first;
    // if (second_number.power_position == 0)
    //     second_number.order[0] += lenl_mantissa_second;

    // result_number.order[0] = (first_number.order[0] - second_number.order[0]);

    // printf("%d", first_number.order[0]);
    // printf("%d", second_number.first_sign_number);
    result_number.first_sign_number = first_number.first_sign_number * second_number.first_sign_number;

    if (error == OK)
        output_result(&result_number, lenl_mantissa_result);
    else 
        printf("Невозможно подсчитать");
    return error;
}





