#include "sort.h"

/*
 * Bubble sort
 * Worst case performance: O(n^2)
 * Best case performance: O(n)
 * Average performance: O(n^2)
 * Worst case space complexity: O(1)
 */

/**
 * bubble_sort - ordering function based on
 * the Bubble sort technique
 *
 * @array: array received
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	unsigned int temp;

	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] > array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
