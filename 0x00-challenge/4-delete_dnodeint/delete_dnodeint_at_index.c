#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp; 
    unsigned int i;

    if (*head == NULL) 
    {
        return (-1);
    }

    saved_head = *head;
    i = 0;

    while (i < index && *head != NULL) 
    {
        *head = (*head)->next;
        i++;
    }

    if (i != index) 
    {
        *head = saved_head;
        return (-1);
    }

    if (index == 0)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        (*head)->next->prev = (*head)->prev;
        free(*head);
        *head = (*head)->next;
    }
    
    return (1);
}