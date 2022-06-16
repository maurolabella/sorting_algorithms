#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1, 2, 5, 5, 2, 1, 2, 2, 2, 5, 1, 5, 5, 5, 5, -1, -1, -1, -2, -85};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	counting_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
