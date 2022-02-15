#include "sort.h"

/**
 *swap - the positions of two elements into an array
 *@array: array
 *@item1: array element
 *@item2: array element
 */
void swap3(int *array, int x, int y)
{

	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */

void shell_sort(int *array, size_t size)
{
	size_t knuth = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (knuth < size / 3)
		knuth = 3 * knuth + 1;
	while (knuth >= 1)
	{
		for (i = knuth; i < size; i++)
			for (index = i; index >= knuth &&
				     (array[index] < array[index - knuth]); index -= knuth)
				swap3(array, index, index - knuth);
		print_array(array, size);
		knuth /= 3;
	}
}
