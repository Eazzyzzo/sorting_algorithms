#include "sort.h"

/**
  * quick_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_func(array, 0, size - 1, size);
}

/**
  * quick_sort_func - ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void quick_sort_func(int *array, int lower, int higher, size_t size)
{
	int lp = 0;

	if (lower < higher)
	{
		lp = lomuto(array, lower, higher, size);
		quick_sort_func(array, lower, lp - 1, size);
		quick_sort_func(array, lp + 1, higher, size);
	}
}

/**
  * lomuto- ...
  * @array: ...
  * @lower: ...
  * @higher: ...
  * @size: ...
  *
  * Return: Nothing!
  */
int lomuto(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, temp = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (temp != array[i])
				print_array(array, size);

			++i;
		}
	}

	temp = array[i];
	array[i] = array[higher];
	array[higher] = temp;

	if (temp != array[i])
		print_array(array, size);

	return (i);
}

