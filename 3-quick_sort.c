#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *swap2 - des
 *@array: array
 *@x: array element
 *@y: array element
 */
void swap2(int *array, ssize_t x, ssize_t y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}
/**
 *lomuto_partition - des
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap2(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap2(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - des
 *@array: array
 *@lim_left: first array element
 *@lim_right: last array element
 *@size: array size
 */
void qs(int *array, ssize_t lim_left, ssize_t lim_right, int size)
{
	ssize_t pivot = 0;


	if (lim_left < lim_right)
	{
		pivot = lomuto_partition(array, lim_left, lim_right, size);

		qs(array, lim_left, pivot - 1, size);
		qs(array, pivot + 1, lim_right, size);
	}
}
/**
 *quick_sort - des
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
