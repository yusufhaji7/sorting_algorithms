#include "sort.h"
void swap(int *array, int *left, int *right, size_t size);
void heapify(int *array, size_t start, size_t end, size_t size);
/**
 * heap_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the heap sort algorithm
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	int start, end;

	if (!array || size < 2)
		return;
	for (start = size / 2 - 1; start >= 0; start--)
		heapify(array, (size_t) start, size, size);
	for (end = size - 1; end >= 0; end--)
	{
		swap(array, &array[0], &array[end], size);
		heapify(array, 0, (size_t) end, size);
	}
}
/**
 * heapify - Find largest among root, left child and right child
 * @array: Array
 * @start: Array start
 * @end: Array end
 * @size: Pointer to the previous element of the list
 *
 * Description: Find largest among root, left child and right child
 * Return: Void
 */
void heapify(int *array, size_t start, size_t end, size_t size)
{
	int largest = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (left < (int) end && array[left] > array[largest])
		largest = left;
	if (right < (int) end && array[right] > array[largest])
		largest = right;
	if (largest != (int) start)
	{
		swap(array, &array[start], &array[largest], size);
		heapify(array, largest, end, size);
	}
}

/**
 * swap - Swaps two int values
 * @array: the integer array to sort
 * @left: address of first value
 * @right: address of second value
 * @size: the size of the array
 *
 * Return: Void
 */
void swap(int *array, int *left, int *right, size_t size)
{
	int temp;

	if (left != right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		print_array(array, size);
	}
}
