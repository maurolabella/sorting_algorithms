#include "sort.h"

/**
 * swap - interchange values from two pointers
 *
 * @array: array received
 * @a: first pointer
 * @b: second pointer
 * @size: size of the array
 */
void swap(int *array, int *a, int *b, size_t size)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * quick_sort_under - sorts an array of integers in ascending
 * order using the Quick sort recursively
 *
 * @array: integer's array
 * @first_index: initial index for recursive purposes
 * @last_index: final index for recursive purposes
 * @size: size of the array
 */
void quick_sort_under(int *array, size_t first_index,
											size_t last_index, size_t size)
{
	/* declaring index variables */
	size_t pivotIndex, runner, swapper;
	int flag = 0;

	if (first_index < last_index)
	{
		/* assigning last element index as pivot element */
		pivotIndex = last_index;
		runner = first_index;
		swapper = first_index;
		/* Sorting in Ascending order with quick sort */
		for (runner = first_index; runner < last_index; runner++)
		{
			if (array[runner] < array[pivotIndex])
			{
				if (flag == 1)
					swapper++;
				else
					flag = 1;
				swap(array, &array[runner], &array[swapper], size);
			}
		}
		/* Out of loop swapping operation */
		if (flag == 1)
			swapper++;
		swap(array, &array[swapper], &array[pivotIndex], size);
		/* Recursive call for quick sort, with partitioning */
		if (flag == 1)
		{
			quick_sort_under(array, first_index, (swapper - 1), size);
			quick_sort_under(array, (swapper + 1), last_index, size);
		}
		else
		{
			quick_sort_under(array, first_index, swapper, size);
			quick_sort_under(array, swapper, last_index, size);
		}
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending
 * order calling quick_sort_under recursively
 *
 * @array: an array of integers
 * @size: array's size
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 0)
		quick_sort_under(array, 0, (size - 1), size);
}
