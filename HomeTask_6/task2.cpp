#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *create = fopen("InputSample.txt", "a");
	fclose(create);
	FILE *input = fopen("InputSample.txt", "r");
	
	
	char symbol = ' ';
	
	while (symbol != EOF)
	{
		int i = 0;
		char *buffer = new char[256];
		Tree *expression = createTree();
		symbol = fgetc(input);
		while ((symbol != '\n') && (symbol != EOF))
		{
					
			if ((symbol != '(') && (symbol != ')'))
			{
				buffer[i] = symbol;
				i++;
			}
			printf("%c",symbol);
			symbol = fgetc(input);

		}
		makeTree(expression, buffer);
		printf("\n%d\n", countTree(expression->root));
		clearTree(expression);
		delete[] buffer;
		
	}
	scanf(" ");
	fclose(input);
}