#ifndef _MAIN_H_
#define _MAIN_H_

//usuale_matrix
typedef struct
{
    int n; //количество строк
    int m; //количество столбцов
    int **data; //обычная матрица
} usuale_matrix_t;

// typedef struct 
// {
//     int *list;
// } list_t;

//special_matrix
typedef struct 
{
    int n; //количество строк
    int m; //количество столбцов
    int k; //количество ненулевых элементов

    int *a; //массив ненулевых элементов 
    int *ja; //массив с индексами по строке
    int *ia; //массив с индексами по столбцу
} special_matrix_t;

//vector-matrix
typedef struct
{
    int n; //количество элементов вектора
    int k; //количество ненулевых элементов вектора
    int *a; //массив ненулевых элементов
    int *ja; //массив с индексами строк

} vector_matrix_t;


#endif
