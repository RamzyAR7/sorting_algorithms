#include "sort.h"
#include <unistd.h>
/**
 * quick_sort_hoare - sorts an array using quick sort algorithm
 * @array: array
 * @size: length of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (array == NULL || size < 2)
		return;
	QuickSort_Haore(array, start, end, size);
}
/**
 * Haore_Partition - parts the array base on the order of its values
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
 * Return: Index of partition
*/
int Haore_Partition(int *arr, int start, int end, int size)
{
	int pivot;
	int iterate_back, iterate_front, temp;

	pivot = arr[end];
	iterate_back = start;
	iterate_front = end;
	while (1)
	{
		while (arr[iterate_back] < pivot && iterate_back < end)
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
 * QuickSort_Haore - sorts an array using quick sort based on haore method
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
*/
void QuickSort_Haore(int *arr, int start, int end, int size)
{
	int pi;

	if (start < end && start >= 0 && end >= 0)
	{
		pi = Haore_Partition(arr, start, end, size);
		QuickSort_Haore(arr, start, (pi - 1), size);
		QuickSort_Haore(arr, pi, end, size);
	}
}
