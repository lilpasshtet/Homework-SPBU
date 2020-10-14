#include "AdditionalModule.h"
#include <stdio.h>

int sizeArray(char *inputFile)
{
	FILE* file = fopen(inputFile, "r");
	if (file == NULL)
	{
		printf("ERROR");
		return;
	}

	int countRead = 0;

	while (!feof(file)) 
	{
		int currentNumber = 0;
		fscanf(file, "%d", &currentNumber);
		countRead++;
	}
	fclose(file);
	return countRead;
}

void createArray(int *arrayOfElements, const int sizeOfArray, char *inputFile)
{
	FILE* file = fopen(inputFile, "r");
	if (file == NULL)
	{
		printf("ERROR");
		return;
	}

	int i = 0;

	while (!feof(file))
	{
		fscanf(file, "%d", &arrayOfElements[i]);
		i++;
	}

	fclose(file);
}

void ownQuickSort(int *arrayElement, const int leftElementIndex, const int rightElementIndex)
{
	if (leftElementIndex >= rightElementIndex) 
	{
		return;
	}
	int leftPointer = leftElementIndex;
	int rightPointer = rightElementIndex;
	int middleElement = arrayElement[(leftPointer + rightPointer) / 2];
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