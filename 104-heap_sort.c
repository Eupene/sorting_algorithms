#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sift_down - sift-down operation
 *
 * @array: pointer to the array
 * @size: size
 * @root: Index of root 
 * @end: Index of last elem
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max_child, child;
    int temp;

    while ((child = 2 * root + 1) <= end)
    {
        max_child = child;

        if (child + 1 <= end && array[child] < array[child + 1])
            max_child = child + 1;

        if (array[root] < array[max_child])
        {
            temp = array[root];
            array[root] = array[max_child];
            array[max_child] = temp;
            print_array(array, size);
        }
        else
        {
            break;
        }

        root = max_child;
    }
}

/**
 * heap_sort - sort an array of int
 *
 * @array: pointer to array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        sift_down(array, size, i - 1, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        print_array(array, size);
        sift_down(array, size, 0, i - 1);
    }
}
