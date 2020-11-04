#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void hairbrushSort(int* arrayElements, const int sizeArray)
{
	if (arrayElements == NULL)
	{
		return;
	}

	int stepSort = sizeArray - 1;
	float factorDecreases = 1.2473309;
	
	while (stepSort > 0)
	{
		for (int i = 0; i + stepSort < sizeArray; i++)
		{
			if (arrayElements[i] > arrayElements[i + stepSort])
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[i + stepSort];
				arrayElements[i + stepSort] = temp;
			}
		}
		stepSort /= factorDecreases;
	}
}

bool isSimilar(int startArray[], int endArray[], const int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		if (startArray[i] != endArray[i])
		{
			return false;
		}
	}
	return true;
}

bool testCorrectCase()
{
	int startArray[10] = { 37, 35, -30, -32, -28, -25, 49, 50, 8, 39 };
	int endArray[10] = { -32, -30, -28, -25, 8, 35, 37, 39, 49, 50 };
	hairbrushSort(startArray, 10);

	return isSimilar(startArray, endArray, 10);
}

bool testNullCase()
{
	hairbrushSort(NULL, 10);
	return true;
}

int main()
{
	if (!testCorrectCase() || !testNullCase())
	{
		printf("ERROR!");
		return 1;
	}

	printf("Enter size array:\n");
	int sizeArray = 0;
	scanf("%d", &sizeArray);
	if (sizeArray <= 0)
	{
		printf("Size must be positive :(");
		return 2;
	}

	// Create array
	int* arrayElements = malloc(sizeArray * sizeof(int));
	srand(time(NULL));

	printf("Start array:\n");
	for (int i = 0; i < sizeArray; i++)
	{
		arrayElements[i] = -50 + rand() % 101;
		printf("%d ", arrayElements[i]);
	}

	printf("\n");

	hairbrushSort(arrayElements, sizeArray);

	printf("End array:\n");
	for (int i = 0; i < sizeArray; i++)
	{
		printf("%d ", arrayElements[i]);
	}

	free(arrayElements);
	return 0;
}