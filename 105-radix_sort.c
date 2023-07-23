#include <stdlib.h>
#include "sort.h"

/**
 * counting_sortt - performs counting sort
 * @array: array
 * @size: size of array
 * @exp: current exponent
 */
void counting_sortt(int *array, size_t size, int exp);

/**
 * radix_sort - Sorts an array
 * @array: array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max_value = 0, exp = 1;
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    while (max_value / exp > 0)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
        exp *= 10;
    }
}

/**
 * counting_sortt - counting sort
 * @array: The array of int
 * @size: size of array
 * @exp: current exponent
 */
void counting_sortt(int *array, size_t size, int exp)
{
    int *count, *output;
    size_t i;
    int max_value = 10;

    count = malloc(sizeof(int) * max_value);
    output = malloc(sizeof(int) * size);

    if (count == NULL || output == NULL)
    {
        free(count);
        free(output);
        return;
    }

    for (i = 0; i < max_value; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < max_value; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < (size_t)-1; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
