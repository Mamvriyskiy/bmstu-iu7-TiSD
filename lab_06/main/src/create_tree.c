#include <stdio.h>
#include <stdlib.h>
#include "create_tree.h"
#include "main.h"
#include "errors.h"

int create_tree_ex(tree_t **head)
{
    printf("\nВведите имя файла: ");

    char name_file[25];

    if (scanf("%s", name_file) != SCANF_ONE_EL_OK)
        return NEGATIVE_SCANF;

    FILE *file = fopen(name_file, "r");
    if (!file)
    {
        printf("\nФайл не найден!\n");
        return NO_OPEN_FILE;
    }
    else
        printf("\nФайл открыт!\n");

    create_tree(file, head);

    fclose(file);

    return OK;
}

int create_tree(FILE *file, tree_t **head)
{
    int error = OK;
    while (error == OK && !feof(file))
    {
        int num;
        if (fscanf(file, "%d", &num) != SCANF_ONE_EL_OK)
            return NEGATIVE_SCANF;

        tree_t *tmp = create_el_tree(num);
        if (!tmp)
            return NEAGTIVE_ALLOC;

        if (*head != NULL)
            push_in_tree(*head, tmp);
        else
            *head = tmp;

        break;
    }

    // print_tree(*head);
    return OK;
}

void push_in_tree(tree_t *head, tree_t *tmp)
{
    if (tmp->data < head->data)
    {
        if (head->left == NULL)
            head->left = tmp;
        else
            push_in_tree(head->left, tmp);
    }
    else
    {
        if (head->right == NULL)
            head->right = tmp;
        else
            push_in_tree(head->right, tmp);
    }
}

void print_tree(tree_t *head)
{
    if (head->left != NULL)
    {
        printf("%d\n", head->data);
        print_tree(head->left);
    }
        if (head->right != NULL)
    {
        printf("%d\n", head->data);
        print_tree(head->left);
    }


}

tree_t *create_el_tree(int num)
{
    tree_t *tmp = malloc(sizeof(tree_t));
    if (!tmp)
        return NULL;

    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}


