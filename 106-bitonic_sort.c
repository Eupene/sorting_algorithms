#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * swap - swap elements
 *
 * @array: pointer to array
 * @i: first element
 * @j: second element
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    printf("Swap: %d, %d\n", array[i], array[j]);
}

/**
 * bitonic_merge - recursively merge
 *
 * @array: Pointer to array
 * @low: Starting index
 * @count: Number of elements
 * @dir: direction
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        int i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k] && dir) || (array[i] < array[i + k] && !dir))
                swap(array, i, i + k);
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive
 *
 * @array: array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: direction
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array
 *
 * @array: pointer to array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
