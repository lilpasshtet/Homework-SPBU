#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void createArray(int *arrayOfElement, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		arrayOfElement[i] = -50 + rand() % 101;
	}
}

void printArray(int *arrayOfElement, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", arrayOfElement[i]);
	}
	printf("\n");
}

void splitIntoTwo(int *arrayOfElements, const int leftElementIndex, const int rightElementIndex)
{
	if (arrayOfElements == NULL)
	{
		return;
	}
	int leftPointer = leftElementIndex;
	int rightPointer = rightElementIndex;
	const int currentElement = arrayOfElements[0];
	do
	{
		while (arrayOfElements[leftPointer] < currentElement)
		{
			leftPointer++;
		}
		while (arrayOfElements[rightPointer] > currentElement)
		{
			rightPointer--;
		}
		if (leftPointer <= rightPointer)
		{
			int temp = arrayOfElements[leftPointer];
			arrayOfElements[leftPointer] = arrayOfElements[rightPointer];
			arrayOfElements[rightPointer] = temp;
			leftPointer++;
			rightPointer--;
		}
	} while (leftPointer <= rightPointer);
}

bool isCorrectSplit(int *startArray, int *endArray, const int sizeOfArray)
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
	int sizeOfArray = 10;
	int startArray[10] = { -20, 36, -22, -17, -32, -21, 1, 41, 36, -3 };
	int endArray[10] = { -21, -32, -22, -17, 36, -20, 1, 41, 36, -3 };

	splitIntoTwo(startArray, 0, sizeOfArray - 1);

	return isCorrectSplit(startArray, endArray, sizeOfArray);
}

bool testIncorrectCase() 
{
	int sizeOfArray = 10;
	splitIntoTwo(NULL, 0, sizeOfArray - 1);
	return true;
}

int main()
{
	if (!testCorrectCase() || !testIncorrectCase())
	{
		printf("ERROR");
		return 2;
	}

	int sizeOfArray = 0;
	printf("Enter the size of array\n");
	scanf("%d", &sizeOfArray);

	if (sizeOfArray < 0) 
	{
		printf("ERROR");
		return 1;
	}

	srand(time(NULL));
	int *arrayOfElements = malloc(sizeOfArray * sizeof(int));

	createArray(arrayOfElements, sizeOfArray);

	printArray(arrayOfElements, sizeOfArray);

	splitIntoTwo(arrayOfElements, 0, sizeOfArray - 1);

	printf("Split array :\n");
	printArray(arrayOfElements, sizeOfArray);

	free(arrayOfElements);
	return 0;
}