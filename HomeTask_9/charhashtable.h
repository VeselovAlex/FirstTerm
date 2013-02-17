#include "listchar.h"
#include "hashfunctions.h"



struct HashTable
{
	int size;
	List** table;
	int (*method) (char *string, int mod);
};

HashTable *createHT(int size, int (*method) (char *string, int mod));
int HTLoad(HashTable *hashT);
int elemQuant(HashTable *hashT);
void addString(HashTable *hashT, char* string);
bool checkString(HashTable *hashT, char* string);
void destroy(HashTable *hashT);
void printAll(HashTable *hashT);
void getTableFromFile(char* filename, HashTable *hashT);
double loadFactor(HashTable *hashT);
void printStat(HashTable *hashT);