#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int Lomuto_Partition(int *arr, int low, int high, int size);
void QuickSort(int *arr, int low, int high, int size);
void cocktail_sort_list(listint_t **list);
int bubble_larger_to_right(listint_t **iterate, listint_t **list);
int bubble_smaller_to_left(listint_t **iterate, listint_t **list);
void merge_sort(int *array, size_t size);
void top_down_split_and_merge(int *array, int start, int end, int *array_b);
int *duplicate_array(int *array, int size);
void top_down_merge(int *arr, int start, int midpoint, int end, int *arr_b);
void shell_sort(int *array, size_t size);
size_t get_gap(size_t size);

#endif
