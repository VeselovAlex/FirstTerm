#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

int priority(char oper)
{
	switch (oper) 
	{
		case '+':
		{
			return 1;
		}
		break;
		case '-':
		{
			return 1;
		}
		break;
		case '*':
		{
			return 2;
		}
		break;
		case '/':
		{
			return 2;
		}
		break;
		default:
		{
			return 0;
		}
		break;
	}
}

bool isNumber(char symbol)
{
	return (symbol >= '0') && (symbol <= '9');
}

bool isOper(char symbol)
{
	return priority(symbol) != 0;
}

int main()
{
	char input[30];
	char output[30];
	cout << "Enter the expression: \n";
	cin >> input;
	int size = strlen(input);
	Stack *opers = createStack();
	unsigned short int j = 0;
	int counter = 0;
	for (unsigned short int i = 0; i < size; i++)
	{
		if (isNumber(input[i]))
		{
			output[j] = input[i];
			j++;
		}
		
		if (input[i] == '(')
			push(opers,input[i]);
		if (input[i] == ')')
		{
			counter = counter + 2;
			do 
			{
				output[j] = pop(opers);
				j++;
			}
			while (top(opers) != '(');
			pop(opers);
			//output[j] = pop(opers);
			//j++;
		}

		if (isOper(input[i]))
		{
			if (isEmpty(opers))
			{
				push (opers,input[i]);
			}
			else
			{
				while ((priority(input[i]) <= priority(top(opers))) && (!isEmpty(opers)))
				{
					output[j] = pop(opers);
					j++;
				}
				push(opers,input[i]);
				
			}
		}
	}
	for(j; j < size;j++)
	{
		output[j] = pop(opers);
	}
	for (j = 0; j < size-counter; j++)
	{
		cout << output[j];
	};
	while (!isEmpty(opers))
	{
		pop(opers);
	}
	delete opers;
	cin >> j;
}