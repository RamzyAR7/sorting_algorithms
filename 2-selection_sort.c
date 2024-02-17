#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, x, tmp, min;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		min = i;
		for (x = i + 1; x < size; x++)
		{
			if (array[min] > array[x])
			{
				min = x;
			}
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
