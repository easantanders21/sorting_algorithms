#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void lomuto_partition(int *array, int lim_left, int lim_right, size_t size)
{
	int pivot = lim_right, min = lim_left, max = lim_left;

	while ()
	{
		
	}
}

void qs(int*array, int lim_left, int lim_right, size_t size)
{
	int index_pivot = lomuto_partition(array, lim_left, lim_right, size);
}
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
