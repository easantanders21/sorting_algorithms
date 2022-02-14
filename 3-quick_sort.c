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
	int pivot = array[lim_right];
	int max = lim_left, min = lim_left, index_pivot = 0;

	while (min != lim_right)
        {
		while (1)
		{
			if (array[max] >= pivot)
				break;
			max++;
			min++;
		}
		while (array[min] >= pivot)
		{
			if (array[min] <= pivot)
				break;
			if (min < lim_right)
				min++;
		}
		if (array[max] >= array[min])
		{
			if (min == lim_right)
				index_pivot = max;
			swap(&array[min], &array[max]);
		}
		while (max < lim_right)
		{
			max++;
			if (array[max] > pivot || max == min)
				break;
		}
	}
	printf("salio del ciclo externo %d \n", index_pivot);
	if (lim_left < 10)
	{
		printf("entro a la recursion\n");
		qs(array, lim_left, index_pivot - 1);
	}
}
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1);
}
