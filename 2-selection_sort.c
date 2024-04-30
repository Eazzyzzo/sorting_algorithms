#include "sort.h"

/**
  * selection_sort - ...
  * @array: ...
  * @size: ...
  *
  * Return: Nothing!
  */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 1, temp = 0, minimum = 0, limit = size - 1;

	if (size < 2)
		return;

	while (i < limit)
	{
		if (j == size)
		{
			if (i != minimum)
			{
				temp = array[i];
				array[i] = array[minimum];
				array[minimum] = temp;
				print_array(array, size);
			}

			++i;
			minimum = i;
			j = i + 1;
			continue;
		}

		if (array[minimum] > array[j])
			minimum = j;

		++j;
	}
}

