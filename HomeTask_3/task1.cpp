#include <iostream>
#include "hsort.h"

using namespace std;

int main()
{
	cout << "Enter the size of the set: \n";
	int size = 0;
	cin >> size;
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 15;
		cout << array[i] << " ";
	}
	cout << endl;
	hsort (array,size);
	int j = 0;
	for(j = size - 1; j > 0; j--)
	{
		if (array[j] == array[j-1]) 
		{
			cout << "The max element: " << array[j] << endl;
			break;
		}
	}
	if (j == 0) 
		cout << "There isn't any max element.";
	delete array;
	cin >> size;
}