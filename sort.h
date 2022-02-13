#ifndef SORT_FILE
#define SORT_FILE
#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print array - print list */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *xp, int *yp);
void swap_node(listint_t **head, listint_t *node_1, listint_t *node_2);
/*task functions*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
#endif
