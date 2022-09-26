#include <stdio.h>
#include "division.h"
#include "error.h"
#include "main.h"

void division(int *num_1, int *num_2, int *result, int lenl_1, int lenl_2, int *exp)
{ 
    int size = 33;
    if (lenl_1 > lenl_2)
    {
        aligment(num_1, 0, lenl_1);
        aligment(num_2, lenl_1 - lenl_2, lenl_2);
    }
    else
    {
        aligment(num_2, 0, lenl_2);
        aligment(num_1, 0, lenl_1);
    }


    check_ten(num_1, num_2, 33, exp);

    int current_pos = 0;
    int equal, counter, flag, flag_zero;
    int last_digit = -25;
    int beggining_flag = 1; // used to

    flag_zero = 1;
    while (current_pos < N_MAX + 1)
    {
        equal = comparison(num_1, num_2, size);

        if (equal == 0) //Два числа равны
        {
            result[current_pos] = 1;
            break;
        }

        else if (equal == 1) //Первое число больше
        {

            flag_zero = 0;
            counter = 0;
            //пока первое чиcло больше второго
            while ((flag = comparison(num_1, num_2, size)) != -1)
            {
                if (flag == 0)
                {
                    counter++;
                    break;
                }
                subtract(num_1, num_2, size);
                counter++;
            }

            if (current_pos == N_MAX) //Переполнение мантиссы
            {
                rounding(result, N_MAX, counter);
                break;
            }
            else
            {
                result[current_pos] = counter;
                current_pos++;
                beggining_flag = 0;
                if (flag == 0)
                    break;
            }
        }
        else //Первое число меньше
        {
            if (flag_zero)
            {
                if (beggining_flag)
                {
                    (*exp)--;
                }
                else
                {
                    result[current_pos] = 0;
                    current_pos++;
                }
            }
            flag_zero = 1;
            move_digits(num_1, size);
        }
    }
}

//Перемещение числа в конец массива
void aligment(int *a, int size_zero, int lenl)
{
    int i = lenl - 1;
    int k = 32 - size_zero;
    while (i >= 0)
    {
        a[k] = a[i];
        a[i] = 0;
        i--;
        k--;
    }
}

//Округление числа
void rounding(int *arr, int size, int last_digit)
{
    int k = 0;
    if (last_digit >= 5)
    {
        arr[size-1]++;
        for (int i = size - 1; i >= 0; i--)
        {
            if (arr[i] == 10)
            {
                arr[i] -= 10;
                arr[i-1]++;
            }
            else
                break;
            k += 1;
        }
    }
}

//Определяет какое из чисел больше по значению
int comparison(int *a, int *b, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > b[i])
        {
            res = 1;
            break;
        }
        else if (a[i] < b[i])
        {
            res = -1;
            break;
        }
    }
    return res;
}

//Производит вычитание
void subtract(int *a, int *b, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (a[i] >= b[i])
            a[i] -= b[i];
        else
        {
            a[i] += 10 - b[i];
            a[i-1]--;
        }
    }
}

//Перемещение чисел в массиве на 1 влево
void move_digits(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1];
    for (int i = size - 1; i < size; i++)
        arr[i] = 0;
}

void print_array(const int *array, int array_size)
{
    printf("\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

}

void check_ten(int *a, int *b, int size, int *exp)
{
    int count = 0;
    int equal;

    while (comparison(a, b, size) == 1 && count < 10)
        count++;

    if (count == 10)
    {
        move_digits(b, size);
        (*exp)++;
    }
}