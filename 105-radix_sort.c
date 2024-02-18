#include "sort.h"
/**
 * empty_array - empties a double array
 * @radix_box: double array
 * @empty: value of empty
*/
void empty_array(int (*radix_box)[1000], int empty)
{
	int radix_index, radix_index_b;

	for (radix_index = 0; radix_index < 10; radix_index++)
	{
		for (radix_index_b = 0; radix_index_b < 1000; radix_index_b++)
		{
			radix_box[radix_index][radix_index_b] = empty;
		}
	}
}
/**
 * dist - distribute elements
 * @radix_box: double array
 * @arr: array
 * @sign_dgt: specifies number of interest
 * @empty: indicate empty slot
 * @size: size of array
*/
void dist(int (*radix_box)[1000], int *arr, int sign_dgt, int empty, int size)
{
	int radix_index, radix_index_b, index;

	for (radix_index = 0; radix_index < 10; radix_index++)
	{
		for (index = 0; index < size; index++)
		{
			if ((arr[index] / sign_dgt) % 10 == radix_index)
			{
				if (radix_box[radix_index][radix_index_b] == empty)
					radix_box[radix_index][radix_index_b] = arr[index];
				else
				{
					radix_index_b++;
					radix_box[radix_index][radix_index_b] = arr[index];
				}
			}
		}
	}
}
/**
 * assign - assign values to original array
 * @radix_box: double array
 * @array: array
 * @empty: indicate empty slot
*/
void assign(int (*radix_box)[1000], int *array, int empty)
{
	int radix_index, radix_index_b, index = -1;

	for (radix_index = 0; radix_index < 10; radix_index++)
	{
		for (radix_index_b = 0; radix_index_b < 1000; radix_index_b++)
		{
			if (radix_box[radix_index][radix_index_b] != empty)
			{
				index++;
				array[index] = radix_box[radix_index][radix_index_b];
			}
		}
	}
}
/**
 * radix_sort - sorts an array based on radix sort algorithm using LSD
 * @array: array
 * @size: length of array
*/
void radix_sort(int *array, size_t size)
{
	int  index = 0, sign_dgt = 1, length = size, max;
	int radix_box[10][1000], empty;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (index = 0; index < length; index++)
	{
		if (max < array[index])
			max = array[index];
	}
	empty = max + 1;
	empty_array(radix_box, empty);
	while (max > sign_dgt)
	{
		dist(radix_box, array, sign_dgt, empty, size);
		assign(radix_box, array, empty);
		empty_array(radix_box, empty);
		sign_dgt *= 10;
		print_array(array, size);
	}
}
