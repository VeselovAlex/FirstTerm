#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "hashfunctions.h"


struct HashTable
{
	int size;
	char** table;
	int (*method) (char *string, int mod);
};

HashTable *createHT(int size, int (*method) (char *string, int mod))