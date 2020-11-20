#include <stdio.h>
#include <string.h>
#include "main_header.h"
#include "node.h"
#include "matrix.h"

int main(void)
{
    int rc = OK;
    char command[COMMANDLEN + 1];
    node_t *matrix1 = NULL;
    node_t *matrix2 = NULL;
    node_t *matrix3 = NULL;

    if ((fgets(command, COMMANDLEN + 1, stdin) != NULL) &&
        (fgetc(stdin) == '\n') &&
        (!strncmp(command, "out", COMMANDLEN) || !strncmp(command, "add", COMMANDLEN) || !strncmp(command, "mul", COMMANDLEN) || !strncmp(command, "lin", COMMANDLEN)))
    {
        //read first matrix
        matrix1 = matrix_read(stdin);
        if (matrix1)
        {
            //out
            if (!strncmp(command, "out", COMMANDLEN))
            {
                matrix_print(stdout, matrix1);
            }
            //lin
            else if (!strncmp(command, "lin", COMMANDLEN))
            {
                matrix1 = matrix_delete_row_with_max(matrix1);
                if (matrix1)
                    matrix_print(stdout, matrix1);
                else
                    rc = ERREMPTY;
            }
            else
            {
                //read second matrix
                matrix2 = matrix_read(stdin);
                if (matrix2)
                {
                    //add
                    if (!strncmp(command, "add", COMMANDLEN))
                    {
                        matrix3 = matrix_add(matrix1, matrix2);
                        if (matrix3)
                        {
                            matrix_print(stdout, matrix3);
                        }
                        else
                            rc = ERREMPTY;
                    }
                    //mul
                    else if (!strncmp(command, "mul", COMMANDLEN))
                    {
                        matrix3 = matrix_mul(matrix1, matrix2);
                        if (matrix3)
                        {
                            matrix_print(stdout, matrix3);
                        }
                        else
                            rc = ERREMPTY;
                    }
                }
                else
                    rc = ERRREADING;
            }
        }
        else
            rc = ERRREADING;
    }
    else
        rc = ERRCOMMAND;
    matrix_free(matrix1);
    matrix_free(matrix2);
    matrix_free(matrix3);
    return rc;
}
