#include "main_header.h"
#include "insert.h"
#include "pop_front.h"
#include "remove_duplicates.h"
#include "sort.h"
#include "task.h"
#include "task_list.h"
#include "my_getdelim.h"


int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    FILE *f = NULL;
    node_t *head = NULL;
    data_t data_add = {NULL, 0};
    node_t node_add = {&data_add, NULL};

    if ((argc != 5) || ((data_add.diff = atoi(argv[4])) <= 0))
        rc = ERRPARAM;
    else
    {
        data_add.name = argv[3];
        node_add.data = &data_add;
        f = fopen(argv[1], "r");
        if (f)
        {
           head = task_list_read(f);
           fclose(f);
        }
        else
            rc = ERROPEN;

    }
}
