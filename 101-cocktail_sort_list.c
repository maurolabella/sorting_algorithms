#include "sort.h"

/**
 * swap_contig_from_left - swap nodes under a criteria
 *
 * @head: head
 * @left: pointer to left sided node
 */
void swap_contig_from_left(listint_t **head, listint_t **left)
{
	listint_t *t_next = (*left)->next;
	listint_t *t_prev = (*left)->prev;

	if (*head == NULL || (*left)->next == NULL || *left == NULL)
		return;

	if ((*left)->prev)
		(*left)->prev->next = t_next;
	else
		*head = t_next;
	if (t_next->next)
		(t_next)->next->prev = *left;

	(*left)->next = t_next->next;
	(*left)->prev = t_next;
	t_next->next = *left;
	t_next->prev = t_prev;
}

/**
 * swap_contig_from_right - swap nodes under a criteria
 *
 * @head: head
 * @right: pointer to left sided node
 */
void swap_contig_from_right(listint_t **head, listint_t **right)
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
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: list's header
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int to_ordr = 1;

	if (list && *list)
		current = *list;
	while (to_ordr)
	{
		to_ordr = 0;
		/**loop from left to right*/
		while (current)
		{
			if (current->prev && ((current->prev->n) > current->n))
			{
				swap_contig_from_right(list, &current);
				print_list(*list);
				to_ordr = 1;
				current = current->next;
			}
			if (current->next)
				current = current->next;
			else
				break;
		}
		/* if nothing moved (swapped), then the array is sorted*/
		if (!to_ordr)
			break;
		to_ordr = 0;
		current = current->prev;
		while (current->prev)
		{
			if ((current->prev->n) > current->n)
			{
				swap_contig_from_right(list, &current);
				print_list(*list);
				to_ordr = 1;
			}
			else
				current = current->prev;
		}
	}
}
