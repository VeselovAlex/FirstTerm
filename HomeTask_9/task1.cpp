#include <stdio.h>
#include "charhashtable.h"

using namespace std;

int main()
{
	const int size = 5;
	
	FILE *input = fopen("TextFile2.txt", "r");
	if (input == NULL)
		return 0;

	HashTable *table = createHT(size,polynomeHash);
	getTableFromFile ("TextFile1.txt", table);

	FILE *output = fopen("TextFile3.txt", "w");

	char* buffer = new char[255];

	while (!feof(input))
	{
		fgets(buffer, 255, input);
		if (checkString(table, buffer))
			fprintf(output, buffer);
	}

	delete[] buffer;.
	destroy(table);
	fclose(output);
	fclose(input);

	scanf(" ");

}