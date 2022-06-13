#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using Shell sort algorithm (knuth sequence)
 *
 * @array: the array of integers
 * @size: array's size
 */
void shell_sort(int *array, size_t size)
{
	int i, j, k, incr;
	long int n;

	if (array && size > 1)
	{
		n = size;
		incr = 1;
		/* while (incr <= (n - 1) / 9)*/
		incr = 3 * incr + 1;

		while (incr >= 1)
		{
			for (i = incr; i < n; i++)
			{
				k = array[i];
				for (j = i - incr; j >= 0 && k < array[j]; j = j - incr)
					array[j + incr] = array[j];
				array[j + incr] = k;
			}
			incr = incr / 3;
			print_array(array, size);
		}
	}
}
