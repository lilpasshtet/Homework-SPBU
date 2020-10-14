#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int* changeFromIntegerToBinary(int numberInInteger) 
{
	int *binaryOfNumber = malloc(8 * sizeof(int));
	for (int i = 0; i < 8; i++)
	{
		binaryOfNumber[i] = 0;
	}
	numberInInteger = abs(numberInInteger);

	for (int i = 0; i < 8; i++)
	{
		binaryOfNumber[i] = numberInInteger % 2;
		numberInInteger = numberInInteger / 2;
	}
	return binaryOfNumber;
}

int* sumOfBinaryArray(int *firstBinaryArray, int *secondBinaryArray) 
{
	int remainsFromSum = 0;
	int *resultOfBinarySum = malloc(8 * sizeof(int));
	for (int i = 0; i < 8; i++)
	{
		int currentSum = firstBinaryArray[i] + secondBinaryArray[i] + remainsFromSum;
		resultOfBinarySum[i] = currentSum % 2;
		remainsFromSum = currentSum / 2;
	}
	return resultOfBinarySum;
}

int* unpackingOfIntegerNumber(int numberInInteger) 
{
	int *binaryOfNumber = malloc(8 * sizeof(int));
	binaryOfNumber = changeFromIntegerToBinary(numberInInteger);
	if (numberInInteger >= 0) 
	{
		return binaryOfNumber;
	}

	for (int i = 0; i < 8; i++)
	{
		binaryOfNumber[i] = 1 - binaryOfNumber[i];
	}

	int *additionalArrayToSum = malloc(8 * sizeof(int));

	additionalArrayToSum = changeFromIntegerToBinary(1);

	binaryOfNumber = sumOfBinaryArray(binaryOfNumber, additionalArrayToSum);

	free(additionalArrayToSum);

	return binaryOfNumber;
}

int unpackingFromBinaryToInteger(int *binaryArray) 
{
	if (binaryArray[7] == 0) {
		int numberInInteger = 0;
		for (int i = 0; i < 8; i++)
		{
			numberInInteger = numberInInteger + binaryArray[i] * pow(2, i);
		}
		return numberInInteger;
	}

	int *additionalArrayToSum = malloc(8 * sizeof(int));

	additionalArrayToSum = unpackingOfIntegerNumber(-1);

	binaryArray = sumOfBinaryArray(binaryArray, additionalArrayToSum);

	int numberInInteger = 0;
	for (int i = 0; i < 8; i++)
	{
		binaryArray[i] = 1 - binaryArray[i];
	}

	for (int i = 0; i < 7; i++)
	{
		numberInInteger = numberInInteger + binaryArray[i] * pow(2, i);
	}

	free(additionalArrayToSum);

	return numberInInteger * (-1);
}

void printOfArray(int *arrayOfElements) 
{
	for (int i = 7; i >= 0; i--)
	{
		printf("%d ", arrayOfElements[i]);
	}
	printf("\n");
}

void resultOfWorkProgramm(int firstNumberInInteger, int secondNumberInInteger) 
{
	int *firstNumberInBinary = malloc(8 * sizeof(int));
	int *secondNumberInBinary = malloc(8 * sizeof(int));
	int *resultOfSumInBinary = malloc(8 * sizeof(int));

	printf("Первое число в двоичной сс\n");
	firstNumberInBinary = unpackingOfIntegerNumber(firstNumberInInteger);
	printOfArray(firstNumberInBinary);

	printf("Второе число в двоичной сс\n");
	secondNumberInBinary = unpackingOfIntegerNumber(secondNumberInInteger);
	printOfArray(secondNumberInBinary);

	printf("Сумма двух чисел в двоичной сс\n");
	resultOfSumInBinary = sumOfBinaryArray(firstNumberInBinary, secondNumberInBinary);
	printOfArray(resultOfSumInBinary);

	printf("Сумма в десятичной сс\n");
	printf("%d", unpackingFromBinaryToInteger(resultOfSumInBinary));
}

bool correctCase() 
{
	return unpackingFromBinaryToInteger(sumOfBinaryArray(unpackingOfIntegerNumber(3), unpackingOfIntegerNumber(10))) == 13;
}

bool caseResultNegativeNumber() 
{
	return unpackingFromBinaryToInteger(sumOfBinaryArray(unpackingOfIntegerNumber(-20), unpackingOfIntegerNumber(13))) == -7;
}

bool caseResultNegativePlusPositiveNumbers() 
{
	return unpackingFromBinaryToInteger(sumOfBinaryArray(unpackingOfIntegerNumber(-5), unpackingOfIntegerNumber(13))) == 8;
}

int main() 
{
	if (!correctCase() || !caseResultNegativeNumber() || !caseResultNegativePlusPositiveNumbers()) 
	{
		printf("ERROR");
		return 1;
	}

	printf("Введите два числа для суммирования\n");
	int firstNumber = 0;
	int secondNumber = 0;
	scanf_s("%d%d", &firstNumber, &secondNumber);
	resultOfWorkProgramm(firstNumber, secondNumber);

	return 0;
}