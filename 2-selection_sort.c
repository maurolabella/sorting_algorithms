#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using Selection sort
 * @array: an array of integers
 * @size: array's size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, iMin, temp;

	for (j = 0; j < size - 1; j++)
	{
		iMin = j;

		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[iMin])
			{
				iMin = i;
			}
		}

		if (iMin != j)
		{
			temp = array[j];
			array[j] = array[iMin];
			array[iMin] = temp;
			print_array(array, size);
		}
	}
}
