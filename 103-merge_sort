#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges subarrays
 *
 * @array: Pointer to original array
 * @left: Pointer to left subarray
 * @left_size: Size of left subarray
 * @right: Pointer to right subarray
 * @right_size: Size of right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp_array;

    temp_array = malloc(sizeof(int) * (left_size + right_size));
    if (temp_array == NULL)
        return;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            temp_array[k++] = left[i++];
        else
            temp_array[k++] = right[j++];
    }

    while (i < left_size)
        temp_array[k++] = left[i++];

    while (j < right_size)
        temp_array[k++] = right[j++];

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp_array[i];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(temp_array);
}

/**
 * merge_sort - Sorts an array of integers
 *
 * @array: Pointer to array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;
        size_t left_size = mid;
        size_t right_size = size - mid;

        printf("Splitting...\n");
        printf("[left]: ");
        print_array(left, left_size);
        printf("[right]: ");
        print_array(right, right_size);

        merge_sort(left, left_size);
        merge_sort(right, right_size);
        merge(array, left, left_size, right, right_size);
    }
}
