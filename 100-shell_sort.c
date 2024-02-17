#include "sort.h"
/**
 * get_gap - Calculates the initial
 * gap for the Shell sort algorithm.
 * @size: The size of the array.
 *
 * Return: The initial gap value.
 */
size_t get_gap(size_t size)
{
	/*must be init by 1*/
	size_t gap = 1;
	/*find the max gap */
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	if (gap > size)
	{
		gap = (gap - 1) / 3;
	}

	return (gap);
}
/**
 * shell_sort - Sorts an array of integers in ascending
 * order using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, x, y, tmp, gap;

	if (!array || !size || size < 2)
	{
		return;
	}
	gap = get_gap(size);

	while (gap != 0)
	{
		for (i = gap; i < size; i++)
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
