#include <stdlib.h>
#include <stdbool.h>
#include "AdditionalModule.h"

struct Stack
{
	int value;
	struct Stack* next;
};

bool isEmpty(struct Stack* Stack)
{
	return Stack->next == NULL;
}

struct Stack* createStack()
{
	struct Stack* newElement = malloc(sizeof(struct Stack));
	if (newElement == NULL)
	{
		return NULL;
	}
	newElement->next = NULL;
	return newElement;
}

void push(struct Stack** Stack, int value)
{
	struct Stack* newList = createStack();
	if (newList == NULL)
	{
		return NULL;
	}
	newList->value = value;
	newList->next = *Stack;
	*Stack = newList;
}

int pop(struct Stack** Stack)
{
	if (isEmpty(*Stack))
	{
		return NULL;
	}
	struct Stack* oldList = (*Stack);
	int element = (*Stack)->value;
	(*Stack) = (*Stack)->next;
	free(oldList);
	return element;
}

bool isCorrectAdd()
{
	struct Stack* Stack = createStack();
	push(&Stack, 6);
	bool flag = Stack->value;
	free(Stack);
	return flag;
}

bool isCorrectPop()
{
	struct Stack* Stack = createStack();
	push(&Stack, 6);
	int element = Stack->value;
	free(Stack);
	return element == 6;
}