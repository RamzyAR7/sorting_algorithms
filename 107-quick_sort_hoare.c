#include "sort.h"
#include <unistd.h>
/**
 * quick_sort_hoare - sorts an array using quick sort algorithm
 * @array: array
 * @size: length of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_haore(array, 0, (size - 1), size);
}
/**
 * haore_partition - parts the array base on the order of its values
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
 * Return: Index of partition
*/
int haore_partition(int *arr, int start, int end, int size)
{
	int pivot;
	int iterate_back, iterate_front, temp, test_a, test_b;

	pivot = arr[end];
	test_a = iterate_back = start;
	test_b = iterate_front = end;
	while (1)
	{
		if (arr[iterate_back] == arr[iterate_front])
		{
			while (arr[test_a] == arr[test_b])
			{
				test_a++;
				test_b--;
				if (test_a >= test_b)
					return (-1);
			}
		}
		while (arr[iterate_back] < pivot)
		{
			iterate_back++;
		}
		while (arr[iterate_front] > pivot)
		{
			iterate_front--;
		}
		if (iterate_back >= iterate_front)
		{
			return (iterate_front);
		}
		else
		{
			temp = arr[iterate_back];
			arr[iterate_back] = arr[iterate_front];
			arr[iterate_front] = temp;
			print_array(arr, size);
		}
	}
}
/**
 * quicksort_haore - sorts an array using quick sort based on haore method
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
*/
void quicksort_haore(int *arr, int start, int end, int size)
{
	int pi;

	if (start < end)
	{
		pi = haore_partition(arr, start, end, size);
		if (pi == -1)
			return;
		quicksort_haore(arr, start, (pi - 1), size);
		quicksort_haore(arr, pi, end, size);
	}
}
