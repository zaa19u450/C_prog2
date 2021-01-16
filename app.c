//пример
//#include <stdio.h>
//#include <stdlib.h>

//#define OK 0
//#define ERRMEM -1
//#define ERRINPUT -2

//int input_array(int **arr, int *n, FILE *f);
//int find_min_i(int *arr, int n);
//void change(int *arr, int i, int j);
//void print_arr(int *arr, int n, FILE *f);

//int input_array(int **arr, int *n, FILE *f)
//{
//    int rc = OK;
//    int *arr_tmp = NULL;
//    int n_tmp;

//    if ((fscanf(f, "%d", &n_tmp) == 1) && (n_tmp > 0))
//    {
//        arr_tmp = malloc(n_tmp * sizeof(int));
//        if (arr_tmp)
//        {
//            for (int i = 0; (i < n_tmp) && (rc == OK); i++)
//            {
//                if (fscanf(f, "%d", &arr_tmp[i]) != 1)
//                {
//                    printf("Input error");
//                    rc = ERRINPUT;
//                }
//            }
//            if (rc == OK)
//            {
//                *arr = arr_tmp;
//                *n = n_tmp;
//            }
//            else
//                free(arr_tmp);
//        }
//        else
//            rc = ERRMEM;
//    }
//    else
//    {
//        printf("Input error");
//        rc = ERRINPUT;
//    }
//    return rc;
//}

//int find_min_i(int *arr, int n)
//{
//    int min_i = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (arr[i] < arr[min_i])
//        {
//            min_i = i;
//        }
//    }
//    return min_i;
//}

//void change(int *arr, int i, int j)
//{
//    int tmp = arr[i];
//    arr[i] = arr[j];
//    arr[j] = tmp;
//}

//void print_arr(int *arr, int n, FILE *f)
//{
//    for (int i = 0; i < n; i++)
//        fprintf(f, "%d ", arr[i]);
//}

//int main(void)
//{
//    int rc = OK;
//    int *arr;
//    int n;

//    rc = input_array(&arr, &n, stdin);
//    if (rc == OK)
//    {
//        change(arr, 0, find_min_i(arr, n));
//        print_arr(arr, n, stdout);
//        free(arr);
//    }
//    else if (rc == ERRMEM)
//        printf("Memory allocation error");

//    return rc;
//}


//вариант 1
#define OK 0
#define ERRMEM -1
#define ERRINPUT -2
typedef struct node node_t;

struct node
{
    int val;
    node_t *next;
};

#include <stdio.h>
#include <stdlib.h>

void free_list(node_t *head)
{
    node_t *next;
    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }

}
node_t *node_create(int n)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->val = n;
        node->next = NULL;
    }
    return node;
}
node_t *node_insert_beg(node_t *head, node_t *node)
{
    node->next = head;
    return node;
}


int input_number(node_t **head, int *minus, FILE *f)
{
    int num;
    if (fscanf(f, "%d", &num) != 1)
        return ERRINPUT;
    if (num < 0)
    {
        num *= -1;
        *minus = 1;
    }
    else
        minus = 0;
    node_t *node;
    while (num)
    {
        node = node_create(num % 10);
        if (node)
        {
            *head = node_insert_beg(*head, node);
        }
        else
        {
            free_list(*head);
            return ERRMEM;
        }
        num /= 10;
    }
    return OK;
}

void list_print(node_t *head, int minus, FILE *f)
{
    if (minus)
        fprintf(f, "- ");
    while (head)
    {
        fprintf(f, "%d ", head->val);
        head = head->next;
    }
}
int add(int a, int b)
{
    return a+b;
}
int main(void)
{
    int (*p1)(int, int) = add;
    void *p2;
    p2 = (void *)p1;
    int rc;
    int minus = 0;
    node_t *head = NULL;

    rc = input_number(&head, &minus, stdin);
    if (rc == OK)
    {
        list_print(head, minus, stdout);
        free_list(head);
    }
    else
    {
        if (rc == ERRINPUT)
            printf("Input error");
        else
            printf("Memory allocation error");
    }
    return rc;
}




//#include "main_header.h"
//#include <stdio.h>

//int main(void)
//{
//    int *matrix = NULL;
//    int **ptrs = NULL;
//    int n = 10, m = 5;
//    int rc = OK;

//    rc = allocate_matrix1(&matrix, n, m);
//    if (rc == OK)
//    {
//        printf("Way1\n");
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//                printf("%d ", matrix[m * i + j]);
//            printf("\n");
//        }
//        printf("\n\n");
//        free_matrix1(matrix);
//    }
//    else
//        return ERRMEM;

//    rc = allocate_matrix2(&ptrs, n, m);
//    if (rc == OK)
//    {
//        printf("Way2\n");
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//                printf("%d ", ptrs[i][j]);
//            printf("\n");
//        }
//        printf("\n\n");
//        free_matrix2(ptrs, n);
//    }
//    else
//        return ERRMEM;

//    rc = allocate_matrix3(&ptrs, n, m);
//    if (rc == OK)
//    {
//        printf("Way3\n");
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//                printf("%d ", ptrs[i][j]);
//            printf("\n");
//        }
//        printf("\n\n");
//        free_matrix3(ptrs);
//    }
//    else
//        return ERRMEM;

//    rc = allocate_matrix4(&ptrs, n, m);
//    if (rc == OK)
//    {
//        printf("Way4\n");
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                *(((char *) ptrs) + n * sizeof(int *) + i * m + j) = i * m + j;
//                printf("%d ", *(((char *) ptrs) + n * sizeof(int *) + i * m + j));
//            }
//            printf("\n");
//        }
//        printf("\n\n");
//        free_matrix4(ptrs);
//    }
//    else
//        return ERRMEM;

//}
