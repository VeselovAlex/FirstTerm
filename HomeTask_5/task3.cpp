#include <stdio.h>
#include "string.h"


void printComments(char* string, bool &multiString)
{
	bool notQuotes = 1;
	bool slashes = 0;
	unsigned short int length = strlen(string);
	for (int i = 0; i < length - 1; i++)
	{
		char now = string[i];
		char next = string[i+1];
		if ((now == '/') && (next == '*') && notQuotes)//changes flag if there is a multistring comment
			multiString = 1;
		if ((now == '*') && (next == '/') && notQuotes)//changes flag and goes to next letter
		{
			multiString = 0;
			i++;
		}
		if ((now == '/') && (next == '/') && notQuotes)
			slashes = 1;
		if (now == '"')
			notQuotes = !notQuotes;
		if(slashes && !multiString) 
			printf("%c",now);
	}
	if(slashes && !multiString) 
		printf("%c",string[length - 1]);

}

int main()
{
	FILE *create = fopen("Input.txt","a");
	fclose(create);
	FILE *input = fopen("Input.txt","r");
	char *string = new char[255];
	bool multiString = 0;
	while (!feof(input))
	{
		fgets(string,255,input);
		printComments(string, multiString);
		delete[] string;
		string = new char[255];
	}
	fclose(input);
	scanf("Empty enter");
}
