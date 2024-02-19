#include "sort.h"

/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	for (i=0; i < size-1; i++)
	{
		for (j=0; j<size-i-1; j++)
		{
			if (array[j] > array[j+1])
			{
				swapp(&array[j], &array[j+1]);
				print_array(array, size);
			}
		}
	}
}

void swapp(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
