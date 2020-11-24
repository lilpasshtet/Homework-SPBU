#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct linkList
{
	int value;
	struct linkList* next;
} linkList;

void removeEnter(const char* nameFile)
{
	FILE* fileIn = fopen(nameFile, "r");
	FILE* fileOut = fopen("text2.txt", "w");

	int c = 0;

	while ((c = fgetc(fileIn)) != EOF)
	{
		if (c == '\n')
		{
			fputc(' ', fileOut);
			continue;
		}
		fputc(c, fileOut);
	}
	fclose(fileIn);
	fclose(fileOut);
}

char* readFile(const char* nameFile)
{
	removeEnter(nameFile);
	const newFileName = "text2.txt";

	FILE* file = fopen(newFileName, "r");
	if (file == NULL)
	{
		return NULL;
	}

	char* rezultString = calloc(300, 1);

	while (!feof(file))
	{
		char* buffer = calloc(100, 1);
		fgets(buffer, 100, file);
		strncat(rezultString, buffer, 100);
		free(buffer);
	}

	return rezultString;
}

linkList* createNode()
{
	linkList* newNode = malloc(sizeof(linkList));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->next = NULL;
	return newNode;
}

linkList* insertValue(linkList* mainNode, int value)
{
	if (mainNode == NULL)
	{
		mainNode = createNode();
		mainNode->value;
		return mainNode;
	}

	linkList* newNode = createNode();
	newNode->value = value;
	newNode->next = mainNode;

	return newNode;
}

linkList* createList(char* receivedString)
{
	if (receivedString == NULL)
	{
		return NULL;
	}

	linkList* mainNode = NULL;

	char* currentSymbol = strtok(receivedString, " ");
	mainNode = insertValue(mainNode, atoi(currentSymbol));

	while (currentSymbol != NULL)
	{
		mainNode = insertValue(mainNode, atoi(currentSymbol));
		currentSymbol = strtok(NULL, " ");
	}

	return mainNode;
}

void printList(linkList* mainNode)
{
	printf("Inverted list:\n");
	while (mainNode->next != NULL)
	{
		printf("%d ", mainNode->value);
		mainNode = mainNode->next;
	}
}

bool isCorrectOpenFile()
{
	char* nameFile = "correctOpen.txt";
	char* receivedString = readFile(nameFile);
	for (int i = 0; i < 3; i++)
	{
		if (receivedString[i] != '2')
		{
			return false;
		}
	}
	return true;
}

bool isCorrectCreateList()
{
	char* nameFile = "correctCreate.txt";
	linkList* mainList = createList(readFile(nameFile));

	if (mainList->value != 2 || mainList->next->value != 1)
	{
		return false;
	}

	free(mainList);
	return true;
}

bool isCorrectInsert()
{
	linkList* mainList = NULL;
	mainList = insertValue(mainList, 2);
	mainList = insertValue(mainList, 3);

	int value = mainList->value;
	free(mainList);
	return value == 3;
}

int main()
{
	if (!isCorrectOpenFile() || !isCorrectCreateList() || !isCorrectInsert())
	{
		printf("ERROR!");
		return 1;
	}


	linkList* mainList = createList(readFile("text.txt"));

	printList(mainList);

	free(mainList);
	return 0;
}