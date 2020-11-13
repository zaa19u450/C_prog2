#include "remove_duplicates.h"

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    //list is not empty
    if (*head)
    {
        node_t *previous = *head;
        node_t *cur = NULL;

        //checking that source data is sorted
        while (previous && previous->next)
        {
            cur = previous->next;
            if (comparator(previous->data, cur->data) > 0)
                return;
            previous = previous->next;
        }

        //removing duplicates
        previous = *head;
        while (previous && previous->next)
        {
            cur = previous->next;
            //found duplicate
            if (comparator(previous->data, cur->data) == 0)
            {
                previous->next = cur->next;
                cur->next = NULL;
                free(cur);
            }
            else
                previous = previous->next;
        }
    }
}
