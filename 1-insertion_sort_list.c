#include "sort.h"

/**
 * swap_contiguous_nodes - swap nodes under a criteria
 *
 * @head: head
 * @right: pointer to left sided node
 */
void swap_contiguous_nodes(listint_t **head, listint_t **right)
{
	listint_t *tmp1 = (*right)->next;
	listint_t *t_izq = (*right)->prev;

	if (*head == NULL || t_izq == NULL || *right == NULL)
		return;

	if ((t_izq)->prev)
		(t_izq)->prev->next = *right;
	else
		*head = *right;
	if ((*right)->next)
		(*right)->next->prev = t_izq;

	(*right)->next = t_izq;
	(*right)->prev = t_izq->prev;
	(t_izq)->next = tmp1;
	(t_izq)->prev = *right;
}

/**
 * sortedInsert - creates an ordered list given nodes one by
 * one with an unique head
 *
 * @head: unique head to the sorted new list
 * @newNode: receivied new node to incorporate sorted
 */
void sortedInsert(listint_t **head, listint_t *newNode)
{
	listint_t *current;

	if (*head == NULL)
		*head = newNode;
	else if ((*head)->n >= newNode->n)
	{
		(*head)->prev = newNode;
		newNode->next = (*head);
		(*head) = newNode;
	}
	else
	{
		current = *head;
		while (current->next && (current->next->n < newNode->n))
			current = current->next;
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next)
			newNode->next->prev = newNode;
		current->next = newNode;
	}
}

/**
 * insertion_sort_list -  order double linked
 * list by the insertion method
 *
 * @list: head to double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *out, *in;

	if (list && *list)
	{
		out = *list;
		in = *list;
	}

	while (out)
	{
		in = out;

		while (in->prev && ((in->prev->n) > (in->n)))
		{
			swap_contiguous_nodes(list, &in);
			print_list(*list);
		}
		out = out->next;
	}
}
