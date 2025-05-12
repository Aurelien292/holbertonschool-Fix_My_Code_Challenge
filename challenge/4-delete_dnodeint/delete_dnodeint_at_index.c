#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

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
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
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
		 if ((*head)->prev != NULL)
        {
            (*head)->prev = (*head)->next;
			printf("OK");
        }
		

        if ((*head)->next != NULL)
        {
            (*head)->next = (*head)->prev;
			printf("OK");
        }
		if ((*head)->next == NULL)
        {
			(*head)->next = NULL;
			printf("OK");
			free(*head);
            return (1);
        }
		*head = saved_head;
		
	}
	
	return (1);
}
