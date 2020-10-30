#pragma once
#include <stdbool.h>
struct Stack;

bool isEmpty(struct Stack* Stack);

struct Stack* createStack();

void push(struct Stack** Stack, int value);

int pop(struct Stack** Stack);

bool isCorrectAdd();

bool isCorrectPop();