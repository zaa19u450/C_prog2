#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#define OK 0
#define ERRMEM -1

//Матрица как одномерный массив
//Возможность использовать как одномерный массив.
//Нужно писать i * m + j, где m – число столбцов.
int allocate_matrix1(int **data, int n, int m);
void free_matrix1(int *data);

//Матрица как массив указателей
//Возможность обмена строки через обмен указателей.
int allocate_matrix2(int ***ptrs, int n, int m);
void free_matrix2(int **data, int n);

//Объединение подходов (1) - массив указателей, а сама матрица - одномерный массив
//следить за первым!
//Возможность использовать как одномерный массив.
//Перестановка строк через обмен указателей. но следить!!!
int allocate_matrix3(int ***ptrs, int n, int m);
void free_matrix3(int **ptrs);

//Объединение подходов (2) - как (1) только одним блоком
//следить за первым!
//Возможность использовать как одномерный массив.
//Перестановка строк через обмен указателей.но следить!!!
int allocate_matrix4(int ***ptrs, int n, int m);
void free_matrix4(int **ptrs);

#endif // MAIN_HEADER_H
