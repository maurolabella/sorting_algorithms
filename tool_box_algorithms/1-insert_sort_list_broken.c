#include "sort.h"

/**
 * swap_contiguous_nodes - swap nodes under a criteria
 *
 * @head: head
 * @left: pointer to right sided node
 * @right: pointer to left sided node
 */
void swap_contiguous_nodes(listint_t **head, listint_t **left,
													 listint_t **right)
{
	listint_t *tmp1 = (*right)->next;
	listint_t *tmp2 = (*left)->prev;

	if (*left == *right || *head == NULL || *left == NULL || *right == NULL)
		return;

	if ((*left)->prev)
		(*left)->prev->next = *right;
	else
		*head = tmp2;
	if ((*right)->next)
		(*right)->next->prev = *left;

	(*right)->next = *left;
	(*right)->prev = tmp2;
	(*left)->next = tmp1;
	(*left)->prev = *right;
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
	listint_t *out = *list, *in = *list;

	while (out)
	{
		in = out;
		while (in->prev && ((in->prev->n) > (in->n)))
		{
			swap_contiguous_nodes(list, &(in->prev), &in);
			print_list(*list);
			in = in->prev;
		}
		out = out->next;
	}
}
