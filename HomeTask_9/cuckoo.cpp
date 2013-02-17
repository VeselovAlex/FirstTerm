#include "cuckoo.h"

void initHT(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
		hashT->table[i] = NULL;
}

HashTable *createHT(int size, int (*method) (char *string, int mod))
{
	HashTable *hashTable = new HashTable;
	hashTable->size = size;
	hashTable->table = new char*[size];
	hashTable->method = method;
	return hashTable;
}

int HTLoad(HashTable *hashT)
{
	int load = 0;
	for (int i = 0; i < hashT->size; i++)
		if (hashT->table[i]!= NULL)
			load++;
	return load;
}

void destroy(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
	{
		delete[] hashT->table[i];
	}
	delete[] hashT->table;
	delete hashT;
}

void addString(HashTable *hashT, char* string)
{
	if (HTLoad(hashT) != hashT->size)
	{
		int hash = polynomeHash(string, hashT->size);
		{

		}
		hashT->table[hash] = string;
	}
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

void printAll(HashTable *hashT)
{
	for (int i = 0; i < hashT->size; i++)
	{
		printf(hashT->table[i]);
		printf("\n");
	}
}


double loadFactor(HashTable *hashT)
{
	return (double)HTLoad(hashT) / (double)hashT->size;
}

void printStat(HashTable *hashT)
{
	printf("\n****************************************************************\n");
	printf("%d elements\n", HTLoad(hashT));
	printf("%.5f load-factor\n", loadFactor(hashT));
	printf("%d filled cells\n", HTLoad(hashT));
	printf("%.5f collision level\n", (double)elemQuant(hashT) / (double)HTLoad(hashT));
	printf("****************************************************************\n");
}