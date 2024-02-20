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
void radix_sort(int *array, size_t size);
void empty_array(int (*radix_box)[1000], int empty);
void dist(int (*radix_box)[1000], int *arr, int sign_dgt, int empt, int size);
void assign(int (*radix_box)[1000], int *array, int empty);
void counting_sort(int *array, size_t size);
int find_max_element(int *array, size_t size);
int *count_array_sort(int *array, size_t size, int max_element);
void swap(int *x, int *y);
void sift_down(int *array, size_t size, size_t idx, size_t max_num);
void heap_sort(int *array, size_t size);
void sort_the_array(int *array, size_t low,
size_t size, size_t dir, size_t len);
void merge(int *array, size_t low, size_t size, size_t dir);
void swap1(int *array, size_t i, size_t x, size_t dir);
void bitonic_sort(int *array, size_t size);

#endif
