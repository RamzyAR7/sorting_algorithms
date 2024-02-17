#include "sort.h"
/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = (size - 1);

	QuickSort(array, start, end, size);
}
/**
 * Lomuto_Partition - parts the array base on the order of its values
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
 * Return: Index of partition
*/
int Lomuto_Partition(int *arr, int start, int end, int size)
{
	int pivot;
	int current, iterate, temp, swap_flag = 0;

	pivot = arr[end];
	current = start;
	for (iterate = start; iterate <= end - 1; iterate++)
	{

		if (arr[iterate] <= pivot)
		{
			temp = arr[current];
			arr[current] = arr[iterate];
			arr[iterate] = temp;
			current++;
			if (swap_flag == 1)
			{
				print_array(arr, size);
			}
		}
		else
			swap_flag = 1;
	}
	temp = arr[current];
	arr[current] = arr[iterate];
	arr[iterate] = temp;
	if (swap_flag == 1)
	{
		print_array(arr, size);
	}
	return (current);
}
/**
 * QuickSort - sorts an array using quick sort algorithm based on Lomuto method
 * @arr: array
 * @start: start of array
 * @end: end of array
 * @size: size of array
*/
void QuickSort(int *arr, int start, int end, int size)
{
	int pi;

	if (start < end)
	{
		pi = Lomuto_Partition(arr, start, end, size);
		QuickSort(arr, start, (pi - 1), size);
		QuickSort(arr, (pi + 1), end, size);
	}
}
