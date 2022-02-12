#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm
 * @array: integers list
 * @size: array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
