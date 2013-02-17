#include <iostream>
#include "stack.h"

using namespace std;

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = NULL;
	return stack;
}

bool isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

void push(Stack *stack, char value)
{
	StackElement *newEl = new StackElement;
	newEl->value = value;
	newEl->next = stack->head;
	stack->head = newEl;
}

char top(Stack *stack)
{
	if (!isEmpty(stack))
		return stack->head->value;
	return 0;
}

char pop(Stack *stack)
{
	char result = top(stack);
	if (!isEmpty(stack))
	{
		StackElement *tmp = stack->head;
		stack->head = stack->head->next;
		delete tmp;
	}
	return result;
}