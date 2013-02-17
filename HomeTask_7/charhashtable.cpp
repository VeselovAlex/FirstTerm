#include "listchar.h"
#include "hashfunctions.h"
#include "charhashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void initHT(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
		hashT->table[i] = createList();
}

HashTable *createHT(int size, int (*method) (char *string, int mod))
{
	HashTable *hashTable = new HashTable;
	hashTable->size = size;
	hashTable->table = new (List*[size]);
	hashTable->method = method;
	initHT(hashTable);
	return hashTable;
}
int HTLoad(HashTable *hashT)
{
	int load = 0;
	for (int i = 0; i < hashT->size; i++)
		if (hashT->table[i]->head != NULL)
			load++;
	return load;
}

void destroy(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
	{
		clearList(hashT->table[i]);
	}
	delete[] hashT->table;
	delete hashT;
}

void addString(HashTable *hashT, char* string)
{
	int hash = hashT->method(string, hashT->size);
	addString(hashT->table[hash],string);
}

void printAll(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
	{
		printList(hashT->table[i]);
	}

}

bool isLowLetter(char sym)
{
	return ((sym >= 'a') && (sym <= 'z'));
}

void getTableFromFile(char* filename, HashTable *hashT)
{
	FILE *input = fopen(filename, "r+");
	if (input == NULL)
		return;
	char symbol = ' ';
	char buffer[50];
	unsigned short int i = 0;
	bool endWord = false;
	while(!feof(input))
	{
		symbol = fgetc(input);
		symbol = tolower(symbol);
		if (isLowLetter(symbol))
		{
			buffer[i] = symbol;
			i++;
			endWord = true;
		}
		else
		{
			if (endWord)
			{
				char *str = new char[i + 1];// Why???? WTF!!!!!!!!!!!!!!!!!!!
				for (int j = 0; j < i; j++)
					str[j] = buffer[j];
				str[i] = '\0';
				addString(hashT, str);
			}
			i = 0;
			endWord = false;
		}
	}
	fclose(input);
}

int elemQuant(HashTable *hashT)
{
	long int sum = 0;
	for (int i = 0; i < hashT->size; i++)
		sum = sum + hashT->table[i]->size;
	return sum;
}

double loadFactor(HashTable *hashT)
{
	return (double)HTLoad(hashT) / (double)hashT->size;
}

void printStat(HashTable *hashT)
{
	printf("\n****************************************************************\n");
	printf("%d cells\n", hashT->size);
	printf("%d elements\n", elemQuant(hashT));
	printf("%.5f load-factor\n", loadFactor(hashT));
	printf("%d filled cells\n", HTLoad(hashT));
	printf("%.5f collision level\n", (double)elemQuant(hashT) / (double)HTLoad(hashT));
	printf("****************************************************************\n");
}