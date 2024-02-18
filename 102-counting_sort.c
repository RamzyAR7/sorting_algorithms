#include "sort.h"
/**
 * find_max_element - Find the maximum element in an array.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum element in the array.
 */
int find_max_element(int *array, size_t size)
{
	size_t i;
	int max_element = array[0];

	for (i = 1; i < size; i++)
	{
		if (max_element < array[i])
		{
			max_element = array[i];
		}
	}

	return (max_element);
}
/**
 * count_array_sort - Sorts an array using counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @max_element: The maximum element in the array.
 *
 * Return: A pointer to the sorted array.
 */
int *count_array_sort(int *array, size_t size, int max_element)
{
	int *count_array, *new_count_array;
	size_t x, y;

	count_array = calloc((max_element + 1), sizeof(int));
	if (!count_array)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		count_array[array[x]] += 1;
	}
	new_count_array = malloc((max_element + 1) * sizeof(int));
	if (!new_count_array)
	{
		free(count_array);
		return (NULL);
	}
	for (y = 0; y <= (size_t)max_element; y++)
	{
		if (y == 0)
		{
			new_count_array[y] = count_array[y];
		}
		else
		{
			new_count_array[y] = new_count_array[y - 1] + count_array[y];
		}
	}
	print_array(new_count_array, max_element + 1);
	free(count_array);
	return (new_count_array);
}
/**
 * counting_sort - Sorts an array using counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, x;
	int max_element;
	int *new_count_array, *output_array;

	if (!array || !size || size < 2)
	{
		return;
	}

	max_element = find_max_element(array, size);

	new_count_array = count_array_sort(array, size, max_element);

	output_array = malloc(sizeof(int) * size);
	if (!output_array)
	{
		free(new_count_array);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output_array[new_count_array[array[i - 1]] - 1] = array[i - 1];
		new_count_array[array[i - 1]] -= 1;
	}
	for (x = 0; x < size; x++)
	{
		array[x] = output_array[x];
	}
	free(new_count_array);
	free(output_array);
}
