#include <stdio.h>
#include "main.h"
#include "errors.h"
#include "menu.h"
#include "create_tree.h"

int main()
{
    int error = OK;
    int num = -1;
    tree_t *head;

    while (error == OK)
    {
        menu();

        printf("\nВведите комманду: ");
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }

        switch(num)
        {
            case 0:
                printf("\nПрограмма завершила работу!\n\n");
                return OK;
            case 1:
                create_tree_ex(&head);
                break;
        }  
    }
}
