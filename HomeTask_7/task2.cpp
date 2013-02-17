#include <iostream>
#include "listchar.h"
#include "hashfunctions.h"
#include "charhashtable.h"

using namespace std;

int main()
{
	HashTable *test = createHT(501,polynomeHash);
	getTableFromFile("test2.txt", test);
	cout << HTLoad(test) << endl;
	printAll(test);
	printStat(test);
	destroy(test);
	int i = 0;
	cin >> i;

}