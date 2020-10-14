#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AdditionalModule.h"

int searchOfMaxCount(int *arrayOfElement, int n)
{
	if (arrayOfElement == NULL)
	{
		return 1;
	}
	ownQuickSort(arrayOfElement, 0, n - 1);

	int maxCountElement = arrayOfElement[0];
	int countOfMaxCountElement = 1;
	int currentCounter = 1;

	for (int i = 1; i < n; i++)
	{
		if (arrayOfElement[i] == arrayOfElement[i - 1])
		{
			currentCounter++;
			if (currentCounter > countOfMaxCountElement)
			{
				maxCountElement = arrayOfElement[i];
				countOfMaxCountElement = currentCounter;
			}
		}
		else
		{
			if (currentCounter > countOfMaxCountElement)
			{
				maxCountElement = arrayOfElement[i];
				countOfMaxCountElement = currentCounter;
			}
			currentCounter = 1;
		}
	}

	return maxCountElement;
}

bool testCorrectCase() 
{
	char inputFile[] = "correctCase.txt";
	int sizeOfArray = sizeArray(inputFile);
	int *arrayOfElements = malloc(sizeOfArray * sizeof(int));
	createArray(arrayOfElements, sizeOfArray, inputFile);
	return searchOfMaxCount(arrayOfElements, sizeOfArray) == 6;
}

bool testIncorrectCase() 
{
	char inputFile[] = "incorrectCase.txt";
	int sizeOfArray = sizeArray(inputFile);
	int *arrayOfElements = malloc(sizeOfArray * sizeof(int));
	createArray(arrayOfElements, sizeOfArray, inputFile);
	return searchOfMaxCount(arrayOfElements, sizeOfArray) == 6;
}

int main() 
{
	if (!testCorrectCase() || testIncorrectCase())
	{
		printf("ERROR");
		return 1;
	}

	char inputFile[] = "text.txt";
	int sizeOfArray = sizeArray(inputFile);

	int *arrayOfElements = malloc(sizeOfArray * sizeof(int));
	
	createArray(arrayOfElements, sizeOfArray, inputFile);

	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", arrayOfElements[i]);
	}

	printf("\nAnswer is : %d", searchOfMaxCount(arrayOfElements, sizeOfArray));

	free(arrayOfElements);

	return 0;
}