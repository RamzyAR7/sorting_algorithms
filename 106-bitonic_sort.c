#include "sort.h"
#include <stdio.h>
/**
 * print_range - Print a range of elements in an array.
 * @array: The array to print.
 * @start: The starting index of the range.
 * @end: The ending index of the range.
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * swap1 - Swap two elements in an array.
 * @array: The array containing the elements.
 * @i: The index of the first element to swap.
 * @x: The index of the second element to swap.
 * @dir: The direction of the swap.
 */
void swap1(int *array, int i, int x, int dir)
{
	int tmp;

	if (dir == (array[i] > array[x]))
	{
		tmp = array[i];
		array[i] = array[x];
		array[x] = tmp;
	}
}
/**
 * merge - Merge two subarrays in a bitonic sequence.
 * @array: The array to merge.
 * @low: The starting index of the first subarray.
 * @size: The size of each subarray.
 * @dir: The direction of the merge.
 * @array_size: The size of the original array.
 */
void merge(int *array, int low, int size, int dir, const int array_size)
{
	int k = size, i = low;

	if (size > 1)
	{
		k = size / 2;

		for (i = low; i < low + k; i++)
			swap1(array, i, i + k, dir);

		merge(array, low, k, dir, array_size);
		merge(array, low + k, k, dir, array_size);
	}
}
/**
 * _sort - Sorts a subarray in bitonic order.
 * @array: The array to sort.
 * @low: The starting index of the subarray.
 * @size: The size of the subarray.
 * @dir: The direction of the sort.
 * @array_size: The size of the original array.
 */
void _sort(int *array, int low, int size, int dir, const int array_size)
{
	int i = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, array_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, array_size);
		print_range(array, low, low + i - 1);

		i = size / 2;
		_sort(array, low, i, 1, array_size);

		_sort(array, low + i, i, 0, array_size);

		merge(array, low, size, dir, array_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, array_size);
			print_range(array, low, low + 2 * i - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, array_size);
			print_range(array, low, low + 2 * i - 1);
		}
	}
}
/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}
