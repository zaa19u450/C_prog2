#include "task.h"

node_t* task_create_node(char *name, int diff)
{
    node_t *node = NULL;
    data_t *data_tmp = NULL;
    node = malloc(sizeof(node_t));
    if (node)
    {
        data_tmp = malloc(sizeof(data_t));
        if (data_tmp)
        {
            data_tmp->name = name;
            data_tmp->diff = diff;
            node->data = data_tmp;
            node->next = NULL;
        }
        else
        {
            free(node);
            node = NULL;
        }
    }
    return node;
}

int my_comparator(const void *x, const void *y)
{
    data_t *data_x = (data_t *) x;
    data_t *data_y = (data_t *) y;

    if (data_x->diff > data_y->diff)
        return 1;
    if (data_x->diff < data_y->diff)
        return -1;
    if (strcmp(data_x->name, data_y->name) > 0)
        return 1;
    if (strcmp(data_x->name, data_y->name) < 0)
        return -1;
    return 0;
}

int task_read(FILE *f, node_t **node)
{
    int rc = OK;

    char *name = NULL;
    int diff = 0;

    size_t len = 0;

    if ((rc = my_getdelim(&name, &len, '\n', f)) == OK)
    {
        if ((fscanf(f, "%d", &diff) == 1) && (diff >= MINDIFF)
                && ((fgetc(f) == '\n') || (feof(f))))
        {
            *node = task_create_node(name, diff);
            if (*node == NULL)
                rc = ERRMEM;
        }
        else
            rc = ERRVALUE;
    }
    free(name);

    return rc;
}

