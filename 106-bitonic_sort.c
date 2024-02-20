#include "sort.h"

/**
 * merge - Merges two subarrays of given array in given direction
 * @array: The array to be sorted
 * @start: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @dir: Direction of sorting (UP or DOWN)
 */
void merge(int *array, size_t start, size_t count, int dir)
{
	size_t i;

	if (count > 1)
	{
		size_t k = count / 2;

		for (i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
				printf("Result [%lu/%lu] (%s):\n"
				, count, count * 2, dir == 1 ? "UP" : "DOWN");
				print_array(array, count * 2);
			}
		}
		merge(array, start, k, dir);
		merge(array, start + k, k, dir);
	}
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence in given direction
 * @array: The array to be sorted
 * @start: Starting index of the sequence to be sorted
 * @count: Number of elements in the sequence
 * @dir: Direction of sorting (UP or DOWN)
 */
void bitonic_merge(int *array, size_t start, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n",
		count, count * 2, dir == 1 ? "UP" : "DOWN");
		print_array(array + start, count * 2);
		bitonic_merge(array, start, k, 1);
		bitonic_merge(array, start + k, k, 0);
		merge(array + start, start, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
	{
		return;
	}
	else
	{
		bitonic_merge(array, 0, size, 1);
	}
}
