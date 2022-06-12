#include "sort.h"

/**
 * quick_sort_under - sorts an array of integers in ascending
 * order using the Quick sort recursively
 *
 * @array: integer's array
 * @first_index: initial index for recursive purposes
 * @last_index: final index for recursive purposes
 */
void quick_sort_under(int *array, size_t first_index,
											size_t last_index, size_t size)
{
	/* declaring index variables */
	size_t pivotIndex, temp, index_a, index_b;

	if (first_index < last_index)
	{
		/* assigning first element index as pivot element */
		pivotIndex = first_index;
		index_a = first_index;
		index_b = last_index;

		/* Sorting in Ascending order with quick sort */

		while (index_a < index_b)
		{
			while (array[index_a] <= array[pivotIndex] && index_a < last_index)
			{
				index_a++;
			}
			while (array[index_b] > array[pivotIndex])
			{
				index_b--;
			}
			if (index_a < index_b)
			{
				/* Swapping operation */
				temp = array[index_a];
				array[index_a] = array[index_b];
				array[index_b] = temp;
				print_array(array, size);
			}
		}
		/* At the end of first iteration, swap pivot element with index_a element */
		temp = array[pivotIndex];
		array[pivotIndex] = array[index_b];
		array[index_b] = temp;

		/* Recursive call for quick sort, with partitioning */
		quick_sort_under(array, first_index, (index_b - 1), size);
		quick_sort_under(array, (index_b + 1), last_index, size);
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
	quick_sort_under(array, 0, (size - 1), size);
}
