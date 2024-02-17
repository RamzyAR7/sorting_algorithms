#include "sort.h"
/**
 * copy_array - copies an array
 * @array: array
 * @array_b: array
 * @size: length of array
*/
void copy_array(int *array, int *array_b, int size)
{
	int index;

	for (index = 0; index < size; index++)
	{
		array_b[index] = array[index];
	}
}
/**
 * top_down_merge - merges two arrays based on their elements values
 * @arr: array
 * @arr_b: array
 * @start: starting index
 * @midpoint: midpoint index
 * @end: end index
*/
void top_down_merge(int *arr, int start, int midpoint, int end, int *arr_b)
{
	int back_index = start, front_index = midpoint, main_index, demo_index;

	printf("Merging...\n");
	printf("[left]: ");
	printf("%d", arr_b[start]);
	for (demo_index = (start + 1); demo_index < midpoint; demo_index++)
	{
		printf(", %d", arr_b[demo_index]);
	}
	printf("\n");
	printf("[right]: ");
	printf("%d", arr_b[midpoint]);
	for (demo_index = (midpoint + 1); demo_index < end; demo_index++)
	{
		printf(", %d", arr_b[demo_index]);
	}
	printf("\n");
	for (main_index = start; main_index < end; main_index++)
	{
		if (back_index < midpoint &&
		(front_index >= end || arr_b[front_index] > arr_b[back_index]))
		{
			arr[main_index] = arr_b[back_index];
			back_index++;
		}
		else
		{
			arr[main_index] = arr_b[front_index];
			front_index++;
		}
	}
	printf("[Done]: ");
	printf("%d", arr[start]);
	for (demo_index = (start + 1); demo_index < end; demo_index++)
	{
		printf(", %d", arr[demo_index]);
	}
	printf("\n");
}
/**
 * duplicate_array - duplicate an array
 * @array: array
 * @size: length of array
 * Return: duplication of the array
*/
int *duplicate_array(int *array, int size)
{
	int *array_b = NULL, index;

	array_b = malloc(sizeof(array));
	if (array_b == NULL)
		return (array_b);
	for (index = 0; index < size; index++)
	{
		array_b[index] = array[index];
	}
	return (array_b);
}
/**
 * top_down_split_and_merge - splits an array and merge it sorted
 * @array: array
 * @array_b: array
 * @start: start index of the array
 * @end: end index of the array
*/
void top_down_split_and_merge(int *array, int start, int end, int *array_b)
{
	int midpoint;

	if ((end - start) <= 1)
		return;
	midpoint = (start + end) / 2;
	top_down_split_and_merge(array, start, midpoint, array_b);
	top_down_split_and_merge(array, midpoint, end, array_b);
	top_down_merge(array, start, midpoint, end, array_b);
	copy_array(array, array_b, end);
}
/**
 * merge_sort - sorts an array using merge sort algorithm
 * @array: array
 * @size: length of array
*/
void merge_sort(int *array, size_t size)
{
	int *array_b = NULL;

	if (array == NULL)
		return;
	array_b = duplicate_array(array, size);
	if (array_b == NULL)
		return;
	top_down_split_and_merge(array, 0, size, array_b);
	free(array_b);
}
