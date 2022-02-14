#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void qs(int*array, int lim_left, int lim_right)
{
	int pivot = array[lim_left];
	int left = lim_left + 1, right = lim_right;

	while (left < right)
	{
		while (array[right] > pivot && right > left)
			right--;
		while (array[left] < pivot && left < right)
			left++;


		if (left < right)
		{
			swap(&array[left], &array[right]);
			print_array(array, 10);
		}

	}
	if (right >= lim_left && array[right] < array[lim_left])
	{
		swap(&array[left], &array[lim_left]);
		print_array(array, 10);
	}
	if (lim_left < right)
	{
		qs(array, lim_left, right - 1);
	}
	if (lim_right > left)
	{
		qs(array, left, lim_right);
	}
}
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1);
}
