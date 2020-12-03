#include <stdio.h>
#include<time.h>
#include<stdlib.h>

#define size 5
#define count 10

int main()
{
	int arr[size];
	int i;
	int j;
	int q;

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % count;
		printf("%d ", arr[i]);
	}

	printf("\n\n");

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				q = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = q;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}