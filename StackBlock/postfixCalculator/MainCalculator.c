#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "AdditionalModule.h"

struct Stack* fromStringToNumber(struct Stack* Stack, char* stringNumber)
{
	int lenString = strlen(stringNumber);
	int currentNumber = 0;
	for (int i = 0; i < lenString; i++)
	{
		int temp = (int)stringNumber[i];
		if (temp >= 48 && temp <= 57)
		{
			currentNumber = currentNumber * 10 + (temp - 48);
		}
		else
		{
			return NULL;
		}
	}
	push(&Stack, currentNumber);
	return Stack;
}

int sumElements(int a, int b)
{
	return a + b;
}

int minusElements(int a, int b)
{
	return a - b;
}

int multiplicationElements(int a, int b)
{
	return a * b;
}

int separateElements(int a, int b)
{
	if (a == 0) {
		return NULL;
	}
	return a / b;
}

struct Stack* actionElement(struct Stack* Stack, int(*actionNumbers)(int, int))
{
	int firstElement = pop(&Stack);
	int secondElement = pop(&Stack);
	if (secondElement == NULL)
	{
		return NULL;
	}
	int newElementUpdate = actionNumbers(secondElement, firstElement);
	push(&Stack, newElementUpdate);
	return Stack;
}

int postfixCalculator(char* buffer)
{
	if (buffer == NULL)
	{
		return NULL;
	}

	struct Stack* Stack = createStack();

	char* currentElement = strtok(buffer, " ");

	while (currentElement != NULL)
	{
		if (strcmp(currentElement, "+") == 0) // Сумма
		{
			Stack = actionElement(Stack, sumElements);
		}
		else if (strcmp(currentElement, "-") == 0) // Разность
		{
			Stack = actionElement(Stack, minusElements);
		}
		else if (strcmp(currentElement, "*") == 0) // Умножение
		{
			Stack = actionElement(Stack, multiplicationElements);
		}
		else if (strcmp(currentElement, "/") == 0) // Деление
		{
			Stack = actionElement(Stack, separateElements);
		}
		else // Добавляю новый элемент
		{
			Stack = fromStringToNumber(Stack, currentElement);
			if (Stack == NULL)
			{
				return NULL;
			}
		}
		currentElement = strtok(NULL, " ");
	}

	int answerOnProgramm = pop(&Stack);
	free(Stack);
	return answerOnProgramm;
}

bool isCorrectCase()
{
	char buffer[20] = "9 6 - 1 2 + *";
	return postfixCalculator(buffer) == 9;
}

bool isNullCase()
{
	postfixCalculator(NULL);
	return true;
}

int main()
{
	if (!isCorrectAdd() || !isCorrectPop() || !isCorrectCase() || !isNullCase()) 
	{
		printf("ERROR");
		return 1;
	}

	char buffer[100] = "";
	scanf("%[^\n]", &buffer);

	int answer = postfixCalculator(buffer);

	if (answer == NULL)
	{
		printf("Wrong! =(");
	}
	else
	{
		printf("%d", answer);
	}

	return 0;
}