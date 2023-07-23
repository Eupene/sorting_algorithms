#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list
 *
 * @n: int stored in the node
 * @prev: Pointer to the previous
 * @next: Pointer to the next
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void merge_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void radix_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
