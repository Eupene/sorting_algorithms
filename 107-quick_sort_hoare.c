#include "sort.h"
#include <stdio.h>

/**
 * print_array - Print an array of int
 * @array: array
 * @size: size of array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * quick_sort_hoare - sort an array
 * @array: The array
 * @size: The size
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_partition(array, size, 0, size - 1);
}

/**
 * hoare_partition - Partitions the array
 * @array: The array
 * @size: The size
 * @low: The lower index
 * @high: The higher index
 *
 * Return: The partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_int(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * swap_int - swap two int
 * @a: first int
 * @b: second int
 */
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
