#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int *arrayElement, const int leftElementIndex, const int rightElementIndex)
{
	for (int i = leftElementIndex + 1; i <= rightElementIndex; i++)
	{
		int currentElement = arrayElement[i];
		for (int j = i - 1; j >= leftElementIndex; j--)
		{
			if (arrayElement[j] < currentElement)
			{
				break;
			}
			arrayElement[j + 1] = arrayElement[j];
			arrayElement[j] = currentElement;
		}
	}
}

void ownQuickSort(int *arrayElement, const int leftElementIndex, const int rightElementIndex)
{
	if (arrayElement == NULL) 
	{
		return;
	}
	if (rightElementIndex - leftElementIndex < 10)
	{
		insertionSort(arrayElement, leftElementIndex, rightElementIndex);
		return;
	}
	int leftPointer = leftElementIndex;
	int rightPointer = rightElementIndex;
	const int middleElement = arrayElement[(leftPointer + rightPointer) / 2];
	do
	{
		while (arrayElement[leftPointer] < middleElement)
		{
			leftPointer++;
		}
		while (arrayElement[rightPointer] > middleElement)
		{
			rightPointer--;
		}
		if (leftPointer <= rightPointer)
		{
			int temp = arrayElement[leftPointer];
			arrayElement[leftPointer] = arrayElement[rightPointer];
			arrayElement[rightPointer] = temp;
			leftPointer++;
			rightPointer--;
		}
	} while (leftPointer <= rightPointer);
	ownQuickSort(arrayElement, leftElementIndex, rightPointer);
	ownQuickSort(arrayElement, leftPointer, rightElementIndex);
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

bool testCorrectCase()
{
	int startArray[21] = { -42, 38, -24, -2, -16, 41, -5, -26, -7, 13, 2, -34, 38, -32, -6, 19, 19, -34, -10, -32, 2 };
	int endArray[21] = { -42, -34, -34, -32, -32, -26, -24, -16, -10, -7, -6, -5, -2, 2, 2, 13, 19, 19, 38, 38, 41 };

	ownQuickSort(startArray, 0, 20);

	return isCorrectSort(startArray, endArray, 21);
}

bool testHardCorrectCase()
{
	int startArray[25] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int endArray[25] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	ownQuickSort(startArray, 0, 24);

	return isCorrectSort(startArray, endArray, 24);
}

bool testIncorrectCase()
{
	int startArray[14] = { 1, 5, 2, 10, -20, 15, 82, 4, -54, 12, -1, 0, -12, 5 };

	ownQuickSort(NULL, 0, 13);

	return true;
}

int main()
{
	if (!testCorrectCase() || !testHardCorrectCase() || !testIncorrectCase())
	{
		printf("Test Failed!");
		return 1;
	}

	printf("Enter the n\n");
	int n = 0;
	scanf_s("%d", &n);

	int *arrayOfElement = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		arrayOfElement[i] = -50 + rand() % 101;
		printf("%d ", arrayOfElement[i]);
	}
	printf("\n");

	ownQuickSort(arrayOfElement, 0, n - 1);
	printf("Sorted array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrayOfElement[i]);
	}

	free(arrayOfElement);
	return 0;
}