#include "sort.h"
/**
 * swap_element - swaps 2 elements
 * @element_a: element 1
 * @element_b: elemnet 2
 * @lst: listed to be sorted
*/
void swap_element(listint_t *element_a, listint_t *element_b, listint_t **lst)
{
	if ((element_b)->next != NULL)
		((element_b)->next)->prev = element_a;
	if ((element_a)->prev != NULL)
		((element_a)->prev)->next = element_b;
	else
		*lst = element_b;
	(element_a)->next = (element_b)->next;
	(element_b)->prev = (element_a)->prev;
	(element_a)->prev = element_b;
	(element_b)->next = element_a;
}
/**
 * bubble_smaller_to_left - bubbles smaller elemnts to left
 * @iterate: pointer to nodes iterating over them
 * @list: list of nodes to sort
 * Return: 1 if swapped and elemnt else zero
*/
int bubble_smaller_to_left(listint_t **iterate, listint_t **list)
{
	int cocktail_sort_swap = 0;

	while ((*iterate)->prev)
	{
		if ((*iterate)->n < (*iterate)->prev->n)
		{
			swap_element((*iterate)->prev, *iterate, list);
			print_list(*list);
			cocktail_sort_swap = 1;
		}
		else
			*iterate = (*iterate)->prev;
	}
	return (cocktail_sort_swap);
}
/**
 * bubble_larger_to_right - bubbles larger elemnts to right
 * @iterate: pointer to nodes iterating over them
 * @list: list of nodes to sort
 * Return: 1 if swapped and elemnt else zero
*/
int bubble_larger_to_right(listint_t **iterate, listint_t **list)
{
	int cocktail_sort_swap = 0;

	while ((*iterate)->next)
	{
		if ((*iterate)->n > ((*iterate)->next)->n)
		{
			swap_element((*iterate), (*iterate)->next, list);
			print_list(*list);
			cocktail_sort_swap = 1;
		}
		else
			*iterate = (*iterate)->next;
	}
	return (cocktail_sort_swap);
}
/**
 * cocktail_sort_list - sorts a list based on cocktailsort algorithm
 * @list: list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *iterate = *list;
	int cocktail_sort_swap = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (cocktail_sort_swap)
	{
		cocktail_sort_swap = bubble_larger_to_right(&iterate, list);
		if (cocktail_sort_swap == 0)
			break;
		cocktail_sort_swap = bubble_smaller_to_left(&iterate, list);
	}
}
