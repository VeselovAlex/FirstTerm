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


bool checkString(HashTable *hashT, char* string)
{
	int hash = polynomeHash(string, hashT->size);
	ListElement* tmp = hashT->table[hash]->head;
	while (tmp != NULL)
	{
		if (areEqual(tmp->value, string))
			return true;
		tmp = tmp->next;
	}
	return false;
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

	while(!feof(input))
	{
		char *str = new char[256];
		fgets(str, 255, input);
		addString(hashT, str);
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