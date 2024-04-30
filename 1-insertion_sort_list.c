#include "sort.h"

/**
  * insertion_sort_list - Sorts an doubly linked list
  * of integers in ascending order using
  * the Insertion sort algorithm.
  * @list: The doubly linked list to sort
  *
  * Return: Nothing!
  */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *temp = NULL, *temp2 = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	while (temp->next)
	{
		if (temp->n > temp->next->n)
		{
			temp->next->prev = temp->prev;
			if (temp->next->prev)
				temp->prev->next = temp->next;
			else
				*list = temp->next;

			temp->prev = temp->next;
			temp->next = temp->next->next;
			temp->prev->next = temp;
			if (temp->next)
				temp->next->prev = temp;

			temp = temp->prev;
			print_list(*list);

			if (temp->prev && temp->prev->n > temp->n)
			{
				if (!flag)
					temp2 = temp->next;
				flag = true;
				temp = temp->prev;
				continue;
			}
		}
		if (!flag)
			temp = temp->next;
		else
			temp = temp2, flag = false;
	}
}

