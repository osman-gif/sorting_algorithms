#include "sort.h"

/**
 * swapp - Swaps the elements in the index a,
 * with the element in the index b
 * @array: The array
 * @a: An index of the array
 * @b: An index of the array
 * @size: Size of the array
 */

void swapp(int *array, size_t size, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partitions the array
 * @array: Array to be partitioned
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 * Return: Returns the index of the pivot
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int j, i;

	pivot = array[high];
	/* printf("pivot: %d, hight %d, low %d\n", pivot, high, low); */
	i = low - 1;

	for (j = low; j < high; j++)
	{
		/* printf("j = %d, i = %d, low = %d\n", j, i, (int)low - 1); */
		/* printf("for loop\n"); */

		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swapp(array, size, i, j);
			}
		}
	}

	if (array[i + 1] > pivot)
	{
		swapp(array, size, i + 1, high);
	}

	return (i + 1);
}

/**
 * recursive_partition - calls the partition function
 * recursively
 * @array: The array
 * @low: The start of the array
 * @high: The end of the array
 * @size: size of the array
 */

void recursive_partition(int *array, int low, int high, size_t size)
{
	int __attribute__((unused))pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		recursive_partition(array, low, pivot_index - 1, size);
		recursive_partition(array, pivot_index + 1, high, size);
	}
}


/**
 * quick_sort - Sort an array of ints using quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	recursive_partition(array, 0, (int)size - 1, size);
}
