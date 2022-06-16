#include "sort.h"

/**
 * max_value - calculates max value
 *
 * @array: received array
 * @size: total number of elements
 * Return: integer returned as max value
 */
int max_value(int *array, size_t size)
{
	int i, len, max = 0;

	if (array && *array && size)
	{
		len = size;
		for (i = 0; i < len; i++)
		{
			if (array[i] > max)
				max = array[i];
		}
		return (max);
	}
	return (0);
}

/**
 * min_value - calculates max value
 *
 * @array: received array
 * @size: total number of elements
 * Return: integer returned as max value
 */
int min_value(int *array, size_t size)
{
	int i, len, min = 0;

	if (array && *array && size)
	{
		len = size;
		for (i = 0; i < len; i++)
		{
			if (array[i] < min)
				min = array[i];
		}
		if (min < 0)
			return (min);
		else
			return (0);
	}
	return (0);
}

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: the array of integers
 * @size: array's size
 */
void counting_sort(int *array, size_t size)
{
	int j, max, min, range, *count, *output;
	size_t i;

	max = max_value(array, size);
	if (max)
	{
		min = min_value(array, size);
		range = max - min + 1;

		count = malloc(sizeof(int) * range);
		output = malloc(sizeof(int) * size);
		if (!count || !output)
			return;
		if (!count)
			return;
		for (i = 0; i < size; i++)
			count[array[i] - min]++;
		for (j = 1; j < range; j++)
			count[j] += count[j - 1];
		print_array(count, range);
		for (j = size - 1; j >= 0; j--)
		{
			output[count[array[j] - min] - 1] = array[j];
			count[array[j] - min]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		free(count);
		free(output);
	}
}
