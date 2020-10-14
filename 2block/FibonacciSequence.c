#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int recursionOfFibonacci(int indexOfSequence)
{
	if (indexOfSequence <= 0) 
	{
		return 0;
	}
	if (indexOfSequence == 1)
	{
		return 0;
	}
	else if (indexOfSequence <= 3)
	{
		return 1;
	}
	else
	{
		return recursionOfFibonacci(indexOfSequence - 1) + recursionOfFibonacci(indexOfSequence - 2);
	}
}

int iterativeOfFibonacci(int indexOfSequence)
{
	int firstElement = 0;
	int secondElement = 0;
	int answerOfFibonacci = 0;
	if (indexOfSequence > 1) 
	{
		secondElement = 1;
	}
	for (int i = 3; i <= indexOfSequence; i++)
	{
		answerOfFibonacci = firstElement + secondElement;
		firstElement = secondElement;
		secondElement = answerOfFibonacci;
	}
	return secondElement;
}

bool testCorrectCase() 
{
	return recursionOfFibonacci(10) == iterativeOfFibonacci(10) && iterativeOfFibonacci(10) == 34;
}

bool testIncorrectCase() 
{
	return recursionOfFibonacci(-5) == iterativeOfFibonacci(-5) && iterativeOfFibonacci(-5) == 0;
}

int main()
{
	if (!testCorrectCase() || !testIncorrectCase())
	{
		printf("ERROR");
		return 1;
	}

	printf("Enter the index of Fibonacci: \n");
	int n = 0;
	scanf("%d", &n);

	if (n <=0 ) 
	{
		printf("ERROR!");
		return 0;
	}

	clock_t timeOfWorking = clock();

	int answer = recursionOfFibonacci(n);
	timeOfWorking = clock() - timeOfWorking;
	printf("%d - time: %f\n", answer, (double)timeOfWorking / CLOCKS_PER_SEC);

	timeOfWorking = clock();
	answer = iterativeOfFibonacci(n);
	timeOfWorking = clock() - timeOfWorking;
	printf("%d - time: %f", answer, (double)timeOfWorking / CLOCKS_PER_SEC);

	return 0;
}