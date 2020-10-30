#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "AdditionalModule.h"

bool isCorrectBraces(char* buffer)
{
	if (buffer == NULL)
	{
		return NULL;
	}

	int lenString = strlen(buffer);

	struct Stack* Stack = createStack();

	for (int i = 0; i < lenString; i++)
	{
		if (buffer[i] == '(')
		{
			push(&Stack, 1);
		}
		else if (buffer[i] == '[')
		{
			push(&Stack, 2);
		}
		else if (buffer[i] == '{')
		{
			push(&Stack, 3);
		}
		else if (buffer[i] == ')')
		{
			int value = pop(&Stack);
			if (value != 1)
			{
				free(Stack);
				return false;
			}
		}
		else if (buffer[i] == ']')
		{
			int value = pop(&Stack);
			if (value != 2)
			{
				free(Stack);
				return false;
			}
		}
		else if (buffer[i] == '}')
		{
			int value = pop(&Stack);
			if (value != 3)
			{
				free(Stack);
				return false;
			}
		}
	}
	bool answerProgramm = isEmpty(Stack);
	free(Stack);
	return answerProgramm;
}


bool correctTestCase()
{
	char buffer[26] = "(hochu{}3balla[]zazadachu)";
	return isCorrectBraces(buffer);
}

bool testUncorrectCase()
{
	char buffer[26] = "((lubluprogrammirovat)[]{}";
	return isCorrectBraces(buffer);
}

bool testNullCase()
{
	isCorrectBraces(NULL);
	return true;
}

int main()
{
	if (!isCorrectAdd() || !isCorrectPop() || !correctTestCase() || testUncorrectCase() || !testNullCase())
	{
		printf("ERROR!");
		return 1;
	}

	char buffer[100] = "";
	scanf("%[^\n]", &buffer);

	if (isCorrectBraces(buffer))
	{
		printf("Correct!");
	}
	else
	{
		printf("Wrong sequence =(");
	}
	
	return 0;
}