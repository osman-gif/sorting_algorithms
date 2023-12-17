#include "sort.h"

/**
 * bubble_sort - This function sorts an array using
 * bubble sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t __attribute__((unused))i, j;
	int swapped;

	if (size >= 2)
	{
		swapped = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (swapped == 1)
			{
				swapped = 0;
				for (j = 0; j < size - (i + 1); j++)
				{
					if (array[j] > array[j + 1])
					{
						swap(array, j);
						swapped = 1;
						print_array(array, size);
					}
				}
			}
		}
	}

}

/**
 * swap - This funtion swaps 2 contiguous elements of
 * an array
 * @array: The array
 * @idx: Index of the first element, from which we will
 * also calculate the index of the other element(idx + 1)
 */

void swap(int *array, int idx)
{
	int tmp;

	tmp = array[idx];
	array[idx] = array[idx + 1];
	array[idx + 1] = tmp;
}
