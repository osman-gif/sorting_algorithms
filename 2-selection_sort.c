#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort
 * @array: Pointer to the array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	/* int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}; */

	size_t __attribute__((unused)) i, j;
	int small, tmp;

	for (i = 0; i < size - 1; i++)
	{
		small = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[small] > array[j])
			{
				small = j;
			}
		}

		if (array[i] > array[small])
		{
			tmp = array[i];
			array[i] = array[small];
			array[small] = tmp;
		}

		print_array(array, size);
	}
}
