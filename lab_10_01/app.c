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
    data_t *data_delete = NULL;
    node_t **nodes_to_delete = NULL;

    if ((argc != 5) || ((data_add.diff = atoi(argv[4])) <= 0))
        rc = ERRPARAM;
    else
    {
        data_add.name = argv[3];
        f = fopen(argv[1], "r");
        if (f)
        {
           head = task_list_read(f);
           fclose(f);
           if (head)
           {
               head = sort(head, my_comparator);
               node_t *elem = task_create_node(data_add.name, data_add.diff);
               if (elem)
               {
                   task_list_insert_sorted(&head, elem, my_comparator);
                   nodes_to_delete = create_deletion_list(head);
                   //
                   for (int i = 0; nodes_to_delete[i]; i++)
                       printf("%p\n", nodes_to_delete);

                   if (nodes_to_delete)
                   {
                       remove_duplicates(&head, my_comparator);
                       data_delete = pop_front(&head);

                       f = fopen(argv[2], "w");
                       if (f)
                       {
                           fprintf(f, "Too simple:\n");
                           fprintf(f, "%s\n", data_delete->name);
                           fprintf(f, "%d\n", data_delete->diff);
                           task_list_print(f, head);
                           fclose(f);
                       }
                       else
                           rc = ERROPEN;
                       free_deletion_list(nodes_to_delete);
                   }
                   else
                       rc = ERRMEM;
               }
               else
                   rc = ERRMEM;
           }
           else
               rc = ERRVALUE;
        }
        else
            rc = ERROPEN;
    }
    return rc;
}
