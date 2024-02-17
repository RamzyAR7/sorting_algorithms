#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending
 * order using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, x, y, tmp;

	/*must be init by 1*/
	size_t gap = 0;

	if (!array || !size)
	{
		return;
	}
	/*find the max gap */
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap != 0)
	{
		for (i = gap - 1; i < size; i++)
		{
			y = i;
			x = i - gap;

			while (x < size && array[x] > array[y])
			{
				tmp = array[y];
				array[y] = array[x];
				array[x] = tmp;
				y = x;
				x -= gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
