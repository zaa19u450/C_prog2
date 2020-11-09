#include "task_list.h"

void free_task_list(node_t *head)
{
    node_t *cur = head;
    data_t *data = NULL;
    node_t *tmp = NULL;
    while (cur)
    {
        tmp = cur->next;
        data = ((data_t *) (tmp->data));
        free(cur);
        free(data->name);
    }
}
node_t* task_list_read(FILE *f)
{
    int diff = 0;
    char *name = NULL;
    node_t *node = NULL;

}
