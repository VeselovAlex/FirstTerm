#include <stdio.h>
#include "listchar.h"

void editWords()//Editing words in text
{
	char buffer = NULL;
	buffer = getchar();
	List *word = createList();
	while (true)
	{
		while ((buffer != ' ') && (buffer != '\n'))
		{
			addLetter(word, buffer);
			buffer = getchar();
		}

		printList(word);
		clearList(word);
		
		while (buffer == ' ')//Missing all spases between words
			buffer = getchar();
		if (buffer == '\n')
			break;
		
		delete word;
		word = createList();
	}
	delete word;
	
}

int main()
{
	printf("Enter text here: \n");
	editWords();
	scanf(" ");
}