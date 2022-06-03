#include "lists.h"

/**
 * check_cycle - checks if a singly linked list
 * loops into itself
 * @list: pointer to the list
 * Return: 0 if there is no cycle,
 * 1 if there is a loop
 */

int check_cycle(listint_t *list)
{
    listint_t *node1;
    listint_t *node2;

    node1 = list;
    node2 = list;

    while (list && node1 && node1->next)
    {
        list = list->next;
        node1 = node1->next->next;

        if (list == node1)
        {
            list = node2;
            node2 = node1;
            while (1)
            {
                node1 = node2;
                while (node1->next != list && node1->next != node2)
                {
                    node1 = node1->next;
                }
                if (node1->next == list)
                    break;

                list = list->next;
            }
            return (1);
        }
    }
    return (0);
}
