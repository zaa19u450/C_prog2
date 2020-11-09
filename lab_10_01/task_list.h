#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "task.h"

void free_task_list(node_t *head);
node_t* task_list_read(FILE *f);

#endif // TASK_LIST_H
