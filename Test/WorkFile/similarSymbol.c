#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* deleteSimilar(const char buffer[])
{
	if (buffer == NULL)
	{
		return NULL;
	}

	const int lenString = strlen(buffer);

	char* rezultString = calloc(200, 1);

	char currentSymbol[1] = { buffer[0] };

	strncat(rezultString, currentSymbol, 1);

	for (int i = 1; i < lenString; i++)
	{
		if (buffer[i] != currentSymbol[0])
		{
			currentSymbol[0] = buffer[i];
			strncat(rezultString, currentSymbol, 1);
		}
	}

	return rezultString;
}

char* correctFile(const char nameFile[])
{
	FILE* file = fopen(nameFile, "r");

	char* rezultString = calloc(300, 1);

	while (!feof(file))
	{
		char buffer[100] = { 0 };
		fgets(buffer, 100, file);

		strncat(rezultString, deleteSimilar(buffer), 100);
	}

	fclose(file);
	return rezultString;
}

bool similarString(const char firstString[], const char secondString[])
{
	int lenStringFirst = strlen(firstString);
	int lenSecondFirst = strlen(secondString);

	if (lenStringFirst == lenSecondFirst)
	{
		for (int  i = 0; i < lenStringFirst; i++)
		{
			if (firstString[i] != secondString[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool testCorrectCase()
{
	char nameFile[16] = "correctTest.txt";

	return similarString(correctFile(nameFile), "abcds");
}

bool testNullCase()
{
	char nameFile[13] = "nullTest.txt";

	char* nullFile = correctFile(nameFile);

	return true;
}


int main()
{
	if (!testCorrectCase() || !testNullCase())
	{
		printf("ERROR");
		return 1;
	}

	char nameFile[9] = "text.txt";

	char* answerString = correctFile(nameFile);

	printf("Correct string:\n");
	printf("%s", answerString);

	return 0;
}