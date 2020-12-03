#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>

#define size 5
#define count 100

int minimum(int arr[]);
int maximum(int arr[]);
double midle(int arr[]);
int mediana(int arr[]);

int main()
{
	int arr[size];

	setlocale(LC_ALL, "");

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % count;
		printf("%d ", arr[i]);
	}

	FILE* alex_noize;
	alex_noize = fopen("C:\\prikol\\alex_noize.txt", "r");

	if (alex_noize == NULL)
	{
		printf("File not found");
	}

	else
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(alex_noize, "%d ", &arr[i]);
		}

		fclose(alex_noize);
	}

	alex_noize = fopen("C:\\prikol\\alex_noize.txt", "a");


	fprintf(alex_noize, "\n\nМинимальным числом в массиве является : %d\n", minimum(arr));
	fprintf(alex_noize, "\nМаксимальным числом в массиве является : %d\n", maximum(arr));
	fprintf(alex_noize, "\nСредним арифметическим в массиве является : %.2lf\n", midle(arr));
	fprintf(alex_noize, "\nМедианой в массиве является : %d\n", mediana(arr));
}

int minimum(int arr[])
{
	int minimum = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < minimum)
		{
			minimum = arr[i];
		}
	}

	return minimum;
}

int maximum(int arr[])
{
	int maximum = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > maximum)
		{
			maximum = arr[i];
		}
	}

	return maximum;
}

double midle(int arr[])
{
	double midle = 0;

	for (int i = 0; i < size; i++)
	{
		midle = midle + arr[i];
	}

	return midle / size;
}

int mediana(int arr[])
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int i = 0; i < size - i - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] = arr[i] - arr[i + 1];
			}
		}
	}

	if (size % 2 != 0)
	{
		return arr[size / 2];
	}

	else
	{
		return (arr[size / 2] + arr[size / 2 - 1]) / 2;
	}
}