#include "sort.h"
/**
 * swap - Swaps two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int swp;

	swp = *x;
	*x = *y;
	*y = swp;
}
/**
 * sift_down - Performs the sift down operation in a heap.
 * @array: The array representing the heap.
 * @size: The size of the array.
 * @idx: The index of the element to sift down.
 * @max_num: The maximum number of elements to consider in the heap.
 */
void sift_down(int *array, size_t size, size_t idx, size_t max_num)
{
	size_t root = idx;
	size_t left = 2 * idx + 1;
	size_t right = 2 * idx + 2;
	size_t largest;

	if (left < max_num && array[left] > array[root])
		largest = left;
	else
		largest = root;

	if (right < max_num && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, max_num);
	}
}
/**
 * heap_sort - Sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, x;

	if (!array || !size || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Heap sort */
	for (x = size - 1; x > 0; x--)
	{
		swap(&array[0], &array[x]);
		print_array(array, size);
		sift_down(array, size, 0, x);
	}
}
