#ifndef _CREATE_TREE_H_
#define _CREATE_TREE_H_


#include "main.h"

int create_tree_ex(tree_t **head);
int create_tree(FILE *file, tree_t **head);
tree_t *create_el_tree(int num);
void push_in_tree(tree_t *head, tree_t *tmp);

void print_tree(tree_t *head);

#endif
