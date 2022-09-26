#include <stdio.h>
#include <string.h>
#include <math.h>
#include "check_number.h"
#include "error.h"

//Проверка числа на корректность
int check_number(char *number)
{
    lower_str(number); //Преобразование в нижний регистр

    if (check_other_symbol(number) != OK) //Проверка на посторонние символы
    {
        printf("Result: Посторонние символы.\n");
        return UNRIGHT_NUMBER;
    }

    int count_power = check_symbol(number, '.');
    if (count_power > 1) //Проверка на количество введенных точек
    {
        printf("Result: Введено неверное количество '.'.\n");
        return UNRIGHT_NUMBER;
    }

    int count_e = check_symbol(number, 'e');
    if (count_e > 1) //Проверка на количество введенных e или E
    {
        printf("Result: Введено неверное количество 'e'.\n");
        return UNRIGHT_NUMBER;
    }

    int count_minus = check_symbol(number, '-'); //Проверка на количество -
    if (count_minus > 2)
    {
        printf("Result: Введено неверное количество '-'.\n");
        return UNRIGHT_NUMBER;
    }
    
    int count_plus = check_symbol(number, '+'); //Проверка на количество +
    if (count_plus > 2)
    {
        printf("Result: Введено неверное количество '+'.\n");
        return UNRIGHT_NUMBER;
    }

    if (count_minus + count_plus > 2) //Проверка на общее количество + и -
    {
        printf("Result: Неверное количество '+-'.");
        return UNRIGHT_NUMBER;
    }

    int position_power = el_position(number, '.');
    if (check_len_number(number) > MAX_LEN_M_N) //Проверка длины введенного числа
    {
        printf("Result: Неверная длина числа (m + n > 30).\n");
        return UNRIGHT_LEN_NUMBER;
    }

    int position_e = el_position(number, 'e'); //Определение позиции элемента
    if (position_e < position_power && count_power != 0)
    {
        printf("Result: Неверное расположение 'e' по отношению к '.'.\n");
        return UNRIGHT_NUMBER;
    }

    int count_sign = count_minus + count_plus;
    if (count_sign == 2) //Проверка на расположение + и - 
    {
        if (position_sign(number, '+', '-', count_sign) - position_e != 1)
        {
            printf("Result: Неверное расположение знаков '+' или '-'.");
            return UNRIGHT_NUMBER;
        }

    }

    if (count_sign == 1) 
    {
        if (number[0] != '-' && number[0] != '+' && position_sign(number, '+', '-', count_sign) - position_e != 1)
        {
            printf("Result: Неверное расположение знаков '+' или '-'.");
            return UNRIGHT_NUMBER;
        }
    }

    int star_position_order = position_e + 3;
    if (count_sign >= 1) //Проверка порядка
    {
        int len_order = check_len_order(number, star_position_order);
        if (len_order > 5) //Проверка на количесвто элементов
        {
            printf("Result: Количество элементов в порядке больше 5.");
            return UNRIGHT_LEN_NUMBER;
        }
        else 
        {
            
            int a = char_to_int_order(number, star_position_order - 1, len_order); //Проверка на принадлежность отрезку
            if (a > 999999 || a < -99999)
                return UNRIGHT_NUMBER;
        }
    }
    return OK;
}

//Определение расположения + и -
int position_sign(char *number, char symbol_plus, char symbol_minus, int k)
{
    int count = 0, flag = 0;
    while (*number)
    {
        if (*number == symbol_plus || *number == symbol_minus)
        {
            flag++;
            if (flag > k - 1)
                break;
        }
        count++;
        number++;
    }
    return count;
}

//Проверка порядка на попадание в промежуток от -99999 до +99999
int char_to_int_order(char *number, int start_position, int len_order)
{
    int element = 0;
    number += start_position;
    while (*number)
    {   
        element += (*number - '0') * pow(10, len_order);
        len_order -= 1;
        number++;
    }
    return element;
}

//Определение длины порядка
int check_len_order(char *number, int start_position)
{
    int count = 0;
    number += start_position;
    while (*number)
    {
        number++;
        count++;
    }
    return count;
}

//Проверка количества элементов в числе
int check_len_number(char *number)
{
    int count = 0;
    while (*number && *number != 'e')
    {
        if (*number != '.' && *number != '+' && *number != '-')
            count++;
        number++;
    }
    return count;
}

//Преобразование числа в нижний регистр
void lower_str(char *number)
{
    while (*number)
    {
        if ((*number >= 'A') && (*number <= 'Z'))
			*number += 'a' - 'A';
		number++;
    }
}

//Проверка числа на посторонние элементы
int check_other_symbol(char *number)
{
    char str_sym[LEN_SYMBOL_ARRAY + 4] = ".e1234567890-+ \n";
    while (*number) 
    {
        if (!check_right_element(str_sym, number))
            return UNRIGHT_NUMBER;
        number++;
    }
    return OK;
}

//Проверка элемента на правильность ввода
int check_right_element(char *el, char *num)
{
    int flag = 0;
    while (*el && flag == 0)
    {
        if (*el == *num)
            flag = 1;
        el++;
    }
    return flag;
}

//Определеение позиции элемента
int el_position(char *number, char symbol)
{
    int i = 0;
    while (*number)
    {
        if (*number == symbol)
            break;
        number++;
        i++;
    }
    return i;
}

//Проверка числа на количество элементов
int check_symbol(char *number, char symbol)
{
    int k = 0;
    while (*number)
    {
        if (*number == symbol)
        {
            k++;
            if (k > 1)
                break;
        }
        number++;
    }
    return k;
}

int check_zero(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            return OK;
    }
    return 1;
}


