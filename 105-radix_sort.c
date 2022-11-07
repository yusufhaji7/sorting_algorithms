#include "sort.h"
int get_max(int *array, size_t size);
int get_max_count(int *array, size_t size);
/**
 * radix_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Size of the array
 *
 * Description: Sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int *new_array, *output, count[10];
	int max, i, j, digits = 10, itter = 1, divisor = 1, try;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	while (max / digits > 0)
	{	itter++;
		digits *= 10; }
	new_array = malloc(sizeof(int) * (size));
	if (!new_array)
		return;
	output = malloc(sizeof(int) * (size));
	if (!output)
		return;
	for (try = 0; try < itter; try++, divisor *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (j = 0; j < (int) size; j++)
		{	new_array[j] = ((array[j]) / divisor) % 10;
			count[new_array[j]] += 1; }
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; (int) i >= 0; i--)
		{	output[count[new_array[i]] - 1] = array[i];
			count[new_array[i]] -= 1; }
		for (i = 0; i < (int) size; i++)
			array[i] = output[i];
		print_array(array, size); }
	free(new_array);
	free(output); }

/**
 * get_max - Maxim number in array
 * @array: Array
 * @size: Size of the array
 *
 * Return: Void
 */
int get_max(int *array, size_t size)
{
	int max = array[0], i = 1;

	while (i < (int) size)
	{
		if (array[i] > (int) max)
			max = array[i];
		i++;
	}
	return (max);
}
