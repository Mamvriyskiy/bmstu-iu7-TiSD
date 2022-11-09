#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "matrix_free.h"

void free_vector(vector_matrix_t *a)
{
    free(a->ja);
    free(a->a);
}

void free_special_matrix(special_matrix_t *a)
{
    free(a->a);
    free(a->ja);
    free(a->ia);
}

void free_usuale_matrix(usuale_matrix_t *a)
{
    for (int i = 0; i < a->n; i++)
        free(a->data[i]);
    free(a->data);
}
