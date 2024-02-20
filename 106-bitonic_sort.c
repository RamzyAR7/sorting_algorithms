#include "sort.h"

/**
 * swap1 - Swaps two elements in an array.
 * @array: The array containing the elements.
 * @i: The index of the first element to swap.
 * @x: The index of the second element to swap.
 * @dir: The direction of the sorting (1 for ascending, 0 for descending).
 */
void swap1(int *array, size_t i, size_t x, size_t dir)
{
	int tmp = 0;

	if (dir == (array[i] > array[x]))
	{
		tmp = array[i];
		array[i] = array[x];
		array[x] = tmp;
	}
}

/**
 * merge - Merges two subarrays of an array.
 * @array: The array containing the subarrays to merge.
 * @low: The starting index of the first subarray.
 * @size: The size of the subarrays to merge.
 * @dir: The direction of the sorting (1 for ascending, 0 for descending).
 */
void merge(int *array, size_t low, size_t size, size_t dir)
{
	size_t i = 0, x = 0;

	if (size > 1)
	{
		i = size / 2;
		x = low;
		while (x < low + i)
			swap1(array, x, x + i, dir), x++;
		merge(array, low, i, dir);
		merge(array, low + i, i, dir);
	}
}

/**
 * sort_the_array - Sorts a subarray of an array in a specified direction.
 * @array: The array to sort.
 * @low: The starting index of the subarray.
 * @size: The size of the subarray.
 * @dir: The direction of the sorting (1 for ascending, 0 for descending).
 * @len: The length of the original array.
 */
void sort_the_array(int *array, size_t low,
size_t size, size_t dir, size_t len)
{
	size_t i = 0;
	int *ptr = NULL;

	if (size > 1)
	{
		i = size / 2;
		if (i > 1)
		{
			printf("Merging [%li/%li] (UP):\n", i, len);
			ptr = &array[low];
			print_array(ptr, i);
		}
		sort_the_array(array, low, i, 1, len);
		if (i > 1)
		{
			printf("Result [%li/%li] (UP):\n", i, len);
			print_array(ptr, i);
			printf("Merging [%li/%li] (DOWN):\n", i, len);
			ptr = &array[low + i];
			print_array(ptr, i);
		}
		sort_the_array(array, low + i, i, 0, len);
		if (i > 1)
		{
			printf("Result [%li/%li] (DOWN):\n", i, len);
			print_array(ptr, i);
		}
		merge(array, low, size, dir);
	}
}

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	size_t i = 1;

	while (i < size)
		i <<= 1;
	if (size < 2 || (i ^ size) != 0)
		return;
	printf("Mergin [%li/%li] (UP):\n", size, size);
	print_array(array, size);
	sort_the_array(array, 0, size, 1, size);
	printf("Result [%li/%li] (UP):\n", size, size);
	print_array(array, size);
}
