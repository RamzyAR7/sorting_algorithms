#include "sort.h"

size_t sort_to_right(listint_t **current_node, listint_t **lst, size_t swapped)
{
	listint_t *next_node;
	int flag;

	while ((*current_node)->next != NULL)
	{
		flag = 0;
		next_node = (*current_node)->next;
		if ((*current_node)->n > (*current_node)->next->n)
		{
			/* Swap current node with its next node */
			if ((*current_node)->prev != NULL)
				(*current_node)->prev->next = next_node;
			else
				*lst = next_node;
			if (next_node->next != NULL)
				next_node->next->prev = *current_node;
			(*current_node)->next = next_node->next;
			next_node->prev = (*current_node)->prev;
			(*current_node)->prev = next_node;
			next_node->next = *current_node;
			swapped = 1;
			flag = 1;
			print_list(*lst);
		}
		if (flag == 0)
			*current_node = (*current_node)->next;
	}
	return (swapped);
}

size_t sort_to_left(listint_t **current_node, listint_t **lst, size_t swapped)
{
	listint_t *prev_node;
	int flag;

	while ((*current_node)->prev != NULL)
	{
		flag = 0;
		prev_node = (*current_node)->prev;
		if ((*current_node)->n < prev_node->n)
		{
			/* Swap current node with its previous node */
			if ((*current_node)->next != NULL)
				(*current_node)->next->prev = prev_node;
			if (prev_node->prev != NULL)
				prev_node->prev->next = *current_node;
			else
				*lst = *current_node;
			(*current_node)->prev = prev_node->prev;
			prev_node->next = (*current_node)->next;
			prev_node->prev = *current_node;
			(*current_node)->next = prev_node;
			swapped = 1;
			flag = 1;
			print_list(*lst);
		}
		if (flag == 0)
			*current_node = (*current_node)->prev;
	}
	return (swapped);
}

void cocktail_sort_list(listint_t **list)
{
	size_t swapped;
	listint_t *current;

	current = *list;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		swapped = sort_to_right(&current, list, swapped);
		if (!swapped)
			break;
		swapped = 0;
		swapped = sort_to_left(&current, list, swapped);
	} while (swapped);
}
