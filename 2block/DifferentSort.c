#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void createOfArray(int *arrayOfElement, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		arrayOfElement[i] = -50 + rand() % 101;
	}
}


void printOfArray(int *arrayOfElement, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", arrayOfElement[i]);
	}
	printf("\n");
}

void bubbleSort(int *arrayOfElement, const int sizeOfArray)
{
	if (arrayOfElement == NULL)
	{
		return;
	}
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 0; j < sizeOfArray - 1; j++)
		{
			if (arrayOfElement[j] > arrayOfElement[j + 1])
			{
				int temp = arrayOfElement[j];
				arrayOfElement[j] = arrayOfElement[j + 1];
				arrayOfElement[j + 1] = temp;
			}
		}
	}
}

void counterSort(int *arrayOfElement, const int sizeOfArray)
{
	if (arrayOfElement == NULL) 
	{
		return;
	}
	int maxElementInArray = arrayOfElement[0];
	int minElementInArray = arrayOfElement[0];

	for (int i = 0; i < sizeOfArray; i++)
	{
		if (arrayOfElement[i] > maxElementInArray) 
		{
			maxElementInArray = arrayOfElement[i];
		}
		if (arrayOfElement[i] < minElementInArray) 
		{
			minElementInArray = arrayOfElement[i];
		}
	}

	int sizeOfAdditionalArray = maxElementInArray - minElementInArray + 1;
	int *counterOfSort = malloc(sizeOfAdditionalArray * sizeof(int));

	for (int i = 0; i < sizeOfAdditionalArray; i++)
	{
		counterOfSort[i] = 0;
	}

	for (int i = 0; i < sizeOfArray; i++)
	{
		counterOfSort[arrayOfElement[i] - minElementInArray]++;
	}

	int currentCounter = 0;
	for (int i = 0; i < sizeOfAdditionalArray; i++)
	{
		for (int j = 0; j < counterOfSort[i]; j++)
		{
			arrayOfElement[currentCounter] = i + minElementInArray;
			currentCounter++;
		}
	}

	free(counterOfSort);
}

bool isCorrectSort(int *startArray, int *endArray, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (startArray[i] != endArray[i])
		{
			return false;
		}
	}
	return true;
}

bool isCorrectBubbleSort() 
{
	int startArray[21] = { -42, 38, -24, -2, -16, 41, -5, -26, -7, 13, 2, -34, 38, -32, -6, 19, 19, -34, -10, -32, 2 };
	int endArray[21] = { -42, -34, -34, -32, -32, -26, -24, -16, -10, -7, -6, -5, -2, 2, 2, 13, 19, 19, 38, 38, 41 };
	int sizeOfArray = 21;
	bubbleSort(startArray, sizeOfArray);
	return isCorrectSort(startArray, endArray, sizeOfArray);
}

bool isCorrectCounterSort() 
{
	int startArray[21] = { -42, 38, -24, -2, -16, 41, -5, -26, -7, 13, 2, -34, 38, -32, -6, 19, 19, -34, -10, -32, 2 };
	int endArray[21] = { -42, -34, -34, -32, -32, -26, -24, -16, -10, -7, -6, -5, -2, 2, 2, 13, 19, 19, 38, 38, 41 };
	int sizeOfArray = 21;
	counterSort(startArray, sizeOfArray);
	return isCorrectSort(startArray, endArray, sizeOfArray);
}

bool testIncorrectCase() 
{
	int sizeOfArray = 21;
	bubbleSort(NULL, sizeOfArray);
	counterSort(NULL, sizeOfArray);
	return true;
}

int main()
{
	if (!isCorrectBubbleSort() || !isCorrectCounterSort() || !testIncorrectCase())
	{
		printf("ERROR");
		return 2;
	}
	int sizeOfArray = 0;
	printf("Enter a size of array\n");
	scanf("%d", &sizeOfArray);

	if (sizeOfArray < 0)
	{
		printf("Size must be positive");
		return 2;
	}
	srand(time(NULL));
	int *arrayOfElement = malloc(sizeOfArray * sizeof(int));

	// Bubble sort
	createOfArray(arrayOfElement, sizeOfArray);

	bubbleSort(arrayOfElement, sizeOfArray);
	printf("Result of bubble sort: \n");
	printOfArray(arrayOfElement, sizeOfArray);

	// Counter sort
	createOfArray(arrayOfElement, sizeOfArray);

	counterSort(arrayOfElement, sizeOfArray);
	printf("Result of counter sort: \n");
	printOfArray(arrayOfElement, sizeOfArray);

	free(arrayOfElement);
	return 0;
}