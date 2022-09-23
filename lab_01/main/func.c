#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#include "main.h"
#include "error.h"

//Рапсредление числа по структурам
void accumulation_struct_number(number_t *struct_number, char *number, int *mantissa_i, int *order_i, int *k) 
{
    int i = 0;
    int flag = 0;
    int last_flag = 0;
    int flag_i = 0;
    while (*number)
    {

        if (i == 0 && *number == '-') //Запись в структуру + или -, стоящих до числа
            struct_number->first_sign_number = -1;
        else if (i == 0 && *number == '+')
            struct_number->first_sign_number = 1;
        else if (i == 0)
            struct_number->first_sign_number = 0;

        if (last_flag == 1) //Запись в структуру + или -, стоящих после экспоненты
        {
            if (*number == '-')
                struct_number->second_sign_number = -1;
            else 
                struct_number->second_sign_number = 1;
            flag = 1;
            last_flag = 0;
        }

        if (*number == '.') //Запись в струкутру позиции точки
        {
            struct_number->power_position = i;
            flag_i = 1;
        }
        else if (*number == 'e') //Запись в структуру позиции экспоненты
        {
            last_flag = 1;
            flag = 1;
            struct_number->exp_position = i;
        }
        else if (flag == 0 && *number != '\n' && *number != '-' && *number != '+') //Запись в структуру мантиссы
        {
            // printf("=%c=", *number);
            struct_number->mantissa[*mantissa_i] = (*number - '0');
            if (flag_i == 0)
                i++;
            *mantissa_i += 1;
        }
        else if (flag == 1 && *number != '\n' && *number != '-' && *number != '+') //Запись в структуру порядка
        {
            struct_number->order[*order_i] = (*number - '0');
            *order_i += 1; 
        }
        number++;
    }
    *k = i;
}

int division_number(int *first_number, int *second_number, \
    int first_mantissa, int second_mantissa, int *result_number, int *count)
{
    unsigned long b = create_number(second_number, second_mantissa);
    size_t c = create_number(first_number, first_mantissa);
    if (c == 0)
    {
        printf("+0.e0");
        return -1;
    }
    if (b == 0)
    {
        printf("No division zero");
        return -1;
    }
    int div = 0, i = 0, k = 10, a = 0, last_num = 0, stop = 1;
    while (1)
    {
        div = a / b;
        printf("\n=%d %d %lu=\n", div, a, b);
        if (div == 0 && i < first_mantissa)
        {
            // printf("1");
            a = a * k + first_number[i];
            i++;
        }
        else if (div == 0 && i >= first_mantissa)
        {
            // printf("2");
            a *= 10;
            result_number[*count] = 0;
            *count += 1;
        }
        else if (div != 0 && i < first_mantissa)
        {
            // printf("3");
            result_number[*count] = div;
            *count += 1;
            a -= b * div;
            a = a * k + first_number[i];
            i++;
        }
        else if (div != 0 && i >= first_mantissa)
        {
            // printf("4");
            result_number[*count] = div;
            a -= div * b;
            a *= 10;
            *count += 1;
        }

        if (*count > 30)
        {
            if (div == 0)
            {
                a *= 10;
                div = a / b;
            }
            // printf("=5=");
            // printf("%d", div);
            last_num = div;
            break;
        }
        
    }
    return last_num;
}

int rounding(int *array, int lenl)
{
    int k = 0;
    int el = 0;
    array[lenl - 1] = 0;
    for (int i = lenl; i - 1 >= 0; i--)
    {
        el = array[i] + 1;
        if (el >= 10)
            array[i] = el - 10;
        if (array[i] == 0)
            k++;
    }
    return k;
}

double create_number(int *array, int lenl_array)
{
    double number = 0;
    for (int i = 0; i < lenl_array; i++)
    {
        number = number / 10 + array[i];
        printf("%f\n", number);
    }
    return number;
}

int make_result_number(number_t *first_number, number_t *second_number, number_t *result_number, \
    int lenl_order_first, int lenl_order_second, int k_1, int k_2, int lenl_mantissa)
{
    int first_order = create_number(first_number->order, lenl_order_first);
    int second_order = create_number(second_number->order, lenl_order_second);
    int order = 0;

    if (result_number->mantissa[0] == '0')
        order = lenl_mantissa - abs(first_order - second_order);
    else
        order = first_order - second_order;
    
    if (order > 99999 || order < -99999)
        return NEGATIVE_INPUT_NUMBER;

    result_number->order[0] = order;
    result_number->first_sign_number = first_number->first_sign_number * second_number->first_sign_number;
    result_number->second_sign_number = first_number->second_sign_number * second_number->second_sign_number;
    return OK;
}

void output_result(number_t *result_number, int lenl_mantissa)
{
    if (result_number->first_sign_number == - 1)
        printf("-");
    else 
        printf("+");
    
    if (result_number->mantissa[0] == 0)
    {
        printf("0.");
        print(result_number->mantissa, 1, lenl_mantissa);
    }
    else
    {
        printf("0.");
        print(result_number->mantissa, 0, lenl_mantissa);
    }
        
    printf("e");

    int a = result_number->order[0];
    printf("%d", a);
}

void print(int *array, int i, int lenl)
{
    for (; i < lenl; i ++)
    {
        printf("%d", array[i]);
    }
}

void without_zero(int *array, int *lenl)
{
    for (int i = *lenl - 1; i > 0; i--)
    {
        if (array[i] == 0)
            *lenl -= 1;
        else
            break;
    }
}
