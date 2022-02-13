#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap_node- swaps nodes.
 *
 * @head: the head of the list.
 * @node_1:left node.
 * @node_2:right node.
 *
 */
void swap_node(listint_t **head, listint_t *node_1, listint_t *node_2)
{
	if (node_1->prev == NULL && node_2->next == NULL)
	{
		node_2->prev = NULL;
		node_2->next = node_1;
		node_1->next = NULL;
		node_1->prev = node_2;
		*head = node_2;
	}
	else if (node_1->prev == NULL)
	{
		node_2->prev = NULL;
		node_2->next->prev = node_1;
		node_1->next = node_2->next;
		node_2->next = node_1;
		*head = node_2;
		node_1->prev = node_2;
	}
	else if (node_2->next == NULL)
	{
		node_2->prev = node_1->prev;
		node_1->prev->next = node_2;
		node_1->prev = node_2;
		node_1->next = NULL;
		node_2->next = node_1;
	}
	else
	{
		node_2->prev = node_1->prev;
		node_1->prev->next = node_2;
		node_1->prev = node_2;
		node_2->next->prev = node_1;
		node_1->next = node_2->next;
		node_2->next = node_1;
	}
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *  in ascending order
 *
 * @list: the doubly linked list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1 = (*list), *tmp2 = (*list);

	if (list == NULL || (*list)->next == NULL)
		return;

	while (tmp1->next != NULL)
	{
		if (tmp1->n > tmp1->next->n)
		{
			swap_node(list, tmp1, tmp1->next);
			print_list(*list);
			tmp2 = tmp1->prev;
			while (tmp2->prev != NULL)
			{
				if (tmp2->n < tmp2->prev->n)
				{
					swap_node(list, tmp2->prev, tmp2);
					print_list(*list);
				}
				else
					tmp2 = tmp2->prev;
			}
		}
		else
			tmp1 = tmp1->next;
	}
}
