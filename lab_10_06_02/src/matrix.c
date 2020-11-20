#include "matrix.h"
#include "main_header.h"

node_t *matrix_read(FILE *f)
{
    int rc = OK;
    int n_tmp, m_tmp;
    int value;
    node_t *node = NULL;
    node_t *head = NULL;

    if ((fscanf(f, "%d", &n_tmp) == 1) && (n_tmp > 0) &&
            (fscanf(f, "%d", &m_tmp) == 1) && (m_tmp > 0))
    {
        for (int i = 0; (i < n_tmp) && (rc == OK); i++)
            for (int j = 0; (j < m_tmp) && (rc == OK); j++)
            {
                if (fscanf(f, "%d", &value) == 1)
                {
                    if (value != 0)
                    {
                        node = node_create(i, j, value);
                        if (node)
                        {
                            head = matrix_insert_end(head, node);
                        }
                        else
                            rc = ERRMEM;
                    }
                }
                else
                    rc = ERRVALUE;
            }
        if (rc != OK)
        {
            matrix_free(head);
            head = NULL;
        }
    }
    return head;
}

void matrix_free(node_t *head)
{
    node_t *next = NULL;

    for (node_t *cur = head; cur; cur = next)
    {
        next = cur->next;
        node_free(cur);
    }
}

node_t *matrix_insert_end(node_t *head, node_t *node)
{
    if (head)
    {
        node_t *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
    else
        head = node;
    return head;
}

void matrix_print(FILE *f, node_t *head)
{
    for (node_t *cur = head; cur; cur = cur->next)
        node_print(f, cur);
}

node_t *matrix_add(node_t *head1, node_t *head2)
{
    node_t *cur1 = head1;
    node_t *cur2 = head2;

    node_t *head_sum = NULL;
    node_t *cur_sum;

    while (cur1 || cur2)
    {
        cur_sum = NULL;
        //CREATE CUR_SUM
        //both unemty
        if (cur1 && cur2)
        {
            //i1<i2
            if (cur1->i < cur2->i)
            {
                cur_sum = node_create(cur1->i, cur1->j, cur1->value);
                cur1 = cur1->next;
            }
            //i1>i2
            else if (cur1->i > cur2->i)
            {
                cur_sum = node_create(cur2->i, cur2->j, cur2->value);
                cur2 = cur2->next;
            }
            //i1=i2
            else
            {
                //j1<j2
                if (cur1->j < cur2->j)
                {
                    cur_sum = node_create(cur1->i, cur1->j, cur1->value);
                    cur1 = cur1->next;
                }
                //j1>j2
                else if (cur1->j > cur2->j)
                {
                    cur_sum = node_create(cur2->i, cur2->j, cur2->value);
                    cur2 = cur2->next;
                }
                //j1=i2 - need to sum
                else
                {
                    cur_sum = node_create(cur1->i, cur1->j, cur1->value + cur2->value);
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
            }
        }
        //only head1 unempty
        else if (cur1)
        {
            cur_sum = node_create(cur1->i, cur1->j, cur1->value);
            cur1 = cur1->next;
        }
        //only head2 unempty
        else
        {
            cur_sum = node_create(cur2->i, cur2->j, cur2->value);
            cur2 = cur2->next;
        }
        //INSERT CUR_SUM
        //element was created
        if (cur_sum)
        {
            //and it is nonnull
            if (cur_sum->value != 0)
                head_sum = matrix_insert_end(head_sum, cur_sum);
            else
                node_free(cur_sum);
        }
        //memory error
        else
        {
            matrix_free(head_sum);
            return NULL;
        }
    }
    return head_sum;
}

node_t *matrix_mul(node_t *head1, node_t *head2)
{
    //if there is no some row (i) or col (j) then in the result matrix's
    //element [i][j] will be null. So its unneccessary to go through them
    node_t *cur1;
    cur1 = head1;
    node_t *cur2;
    node_t *row_node;


    int value_mul;
    node_t *node_mul;
    node_t *head_mul = NULL;

    int col_amount = -1;
    for (node_t *node = head2; node; node = node->next, col_amount++);

    //all rows of matrix 1
    for (int i = 0; cur1; i++)
    {
        //row i of m1 is unempty
        if (cur1->i == i)
        {
            //all columns of matrix 2//all columns of matrix 2
            for (int j = 0; j <= col_amount; j++)
            {
                //mult i row by j col
                row_node = cur1;
                value_mul = 0;
                node_mul = NULL;
                cur2 = head2;
                while ((row_node) && (row_node->i == i) && cur2)
                {
                    //find elements from j col
                    if (cur2->j != j)
                    {
                        cur2 = cur2->next;
                    }
                    else
                    {
                        //no matches found for element row
                        if (cur2->i > row_node->j)
                        {
                            row_node = row_node->next;
                        }
                        //match!
                        else if (cur2->i == row_node->j)
                        {
                            value_mul += ((cur2->value) * (row_node->value));
                            row_node = row_node->next;
                            cur2 = cur2->next;
                        }
                        // no match
                        else
                            cur2 = cur2->next;
                    }
                }
                //result of multing i row by j col is nonnull
                if (value_mul)
                {
                    node_mul = node_create(i, j, value_mul);
                    if (node_mul)
                        head_mul = matrix_insert_end(head_mul, node_mul);
                    //memory error
                    else
                    {
                        matrix_free(head_mul);
                        return NULL;
                    }
                }
            }
        }
        while ((cur1) && (cur1->i == i))
            cur1 = cur1->next;
    }
    return head_mul;
}

int matrix_find_row_with_max(node_t *head)
{
    int row = head->i;
    int max = head->value;
    for (node_t *cur = head; cur; cur = cur->next)
        if (cur->value > max)
        {
            max = cur->value;
            row = cur->i;
        }
    return row;
}

node_t *matrix_delete_row_with_max(node_t *head)
{
    int row = matrix_find_row_with_max(head);
    node_t *new_head;
    node_t *next;

    if (row == head->i)
    {
        while ((head) && (head->i == row))
        {
            next = head->next;
            node_free(head);
            head = next;
        }
        new_head = head;

        for (node_t *cur = new_head; cur != NULL; (cur->i)--, cur = cur->next);
    }
    else
    {
        new_head = head;
        node_t *middle;
        while ((head->next)->i < row)
            head = head->next;
        middle = head;
        head = head->next;
        while ((head) && (head->i == row))
        {
            next = head->next;
            node_free(head);
            head = next;
        }
        middle->next = head;
        for (node_t *cur = head; cur; (cur->i)--, cur = cur->next);
    }
    return new_head;
}
