#ifndef CHECK_NUMBER_H
#define CHECK_NUMBER_H

#include <stdio.h>

#define LEN_SYMBOL_ARRAY 13
#define MAX_LEN_M_N 31

int check_number(char *first_number);
int check_symbol(char *number, char symbol);
void lower_str(char *number);
int el_position(char *number, char symbol);
int check_other_symbol(char *number);
int check_right_element(char *el, char *num);
int check_len_number(char *number);
int position_sign(char *number, char symbol_plus, char symbol_minus);
int check_len_order(char *number, int start_position);
int char_to_int_order(char *number, int start_position, int len_order);

#endif
