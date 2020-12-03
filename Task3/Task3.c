#include <stdio.h>
#include <stdlib.h>

#define arr_size 5
#define count 50


void siftDown(int* numbers, int root, int bottom)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
		{
			maxChild = root * 2;
		}

		else if (numbers[root * 2] > numbers[root * 2 + 1])
		{
			maxChild = root * 2;
		}

		else
		{
			maxChild = root * 2 + 1;
		}

		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}

		else
		{
			done = 1;
		}
	}
}

void heapSort(int* numbers, int size)
{

	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		siftDown(numbers, i, size - 1);
	}

	for (int i = size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}
int main()
{
	int arr[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = rand() % count - arr_size;
	}

	for (int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	heapSort(arr, arr_size);

	for (int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}