#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ownQuickSort(int *arrayElement, const int leftElementIndex, const int rightElementIndex)
{
	if (leftElementIndex >= rightElementIndex) {
		return;
	}
	int leftPointer = leftElementIndex;
	int rightPointer = rightElementIndex;
	int middleElement = arrayElement[(leftPointer + rightPointer) / 2];
	do
	{
		while (arrayElement[leftPointer] < middleElement) {
			leftPointer++;
		}
		while (arrayElement[rightPointer] > middleElement) {
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

int binarySearch(int *arrayElement, int sizeArray, int itemFound) {
	int low = 0;
	int high = sizeArray - 1;

	while (low <= high) {
		int middleElement = (low + high) / 2;
		int currentElement = arrayElement[middleElement];
		if (currentElement == itemFound) {
			return middleElement;
		}
		if (currentElement > itemFound) {
			high = middleElement - 1;
		}
		else {
			low = middleElement + 1;
		}
	}
	return -1;
}

int counterOfElement(int *arrayElements, int *arrayElementsSearch, int n, int k) {
	int counter = 0;

	ownQuickSort(arrayElements, 0, n - 1);

	for (int i = 0; i < k; i++)
	{
		if (binarySearch(arrayElements, n, arrayElementsSearch[i]) != -1) {
			counter++;
		}
	}

	return counter;
}

bool testCorrectCase() {
	int arrayElements[] = { 3, 2, 1, 4, 5 };
	int arrayElementsSearch[] = { 2, 3 };
	int n = 5;
	int k = 3;

	return counterOfElement(arrayElements, arrayElementsSearch, n, k) == 2;
}

bool testIncorrectCase() {
	int arrayElements[16] = { 1, 6, 2, -10, -20, 9, 90, 63, 25, 12, 52, 90, 2, -2, -1, -5 };
	int arrayElementsSearch[3] = { 5, 1, 9 };
	int n = 16;
	int k = 3;

	return counterOfElement(arrayElements, arrayElementsSearch, n, k) == 5;
}

int main() {
	if (!testCorrectCase() || testIncorrectCase()) {
		printf("Test Failed!");
		return 0;
	}

	srand(time(NULL));
	printf("Enter n and k\n");
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);

	int *arrayElements = malloc(n * sizeof(int));
	int *arrayElementsSearch = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		arrayElements[i] = -50 + rand() % 101;
	}

	for (int i = 0; i < k; i++)
	{
		arrayElementsSearch[i] = -50 + rand() % 101;
	}

	printf("Array of N\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrayElements[i]);
	}

	printf("\n");
	printf("Array of K \n");

	for (int i = 0; i < k; i++)
	{
		printf("%d ", arrayElementsSearch[i]);
	}
	printf("\nAnswer is %d", counterOfElement(arrayElements, arrayElementsSearch, n, k));

	free(arrayElements);
	free(arrayElementsSearch);
	return 1;
}