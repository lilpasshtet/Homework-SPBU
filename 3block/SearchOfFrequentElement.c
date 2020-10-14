#include <stdio.h>
#include <stdbool.h>

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
	int arrayOfElement[] = { 3, 8, 2, 4, 6, 9, 6, 5, 6, 4, 6, 5, 6, 8, 6 };
	return searchOfMaxCount(arrayOfElement, 15) == 6;
}

bool testIncorrectCases() 
{
	int arrayOfElement[] = { 8, 9, 3, 1, 3, 5, 4, 3, 3, 9 ,6 };
	return searchOfMaxCount(NULL, 11) == 6;
}

int main() 
{
	if (!testCorrectCase() || testIncorrectCases()) 
	{
		printf("Test Failed!");
		return 1;
	}

	srand(time(NULL));
	printf("Enter n\n");
	int n = 0;
	scanf("%d", &n);

	int *arrayOfElement = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arrayOfElement[i] = -20 + rand() % 41;
		printf("%d ", arrayOfElement[i]);
	}

	printf("\nAnswer is %d", searchOfMaxCount(arrayOfElement, n));

	free(arrayOfElement);
	return 0;
}