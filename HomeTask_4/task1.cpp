#include <iostream>
#include "hsort.h"

using namespace std;

int main()
{
	cout << "Enter the length of the first string: \n";
	int len1 = 0;
	cin >> len1;
	char *str1 = new char[len1 + 1];
	cout << "\nEnter the first string: \n";
	cin >> str1;
	int l1 = strlen(str1);
	
	cout << "\nEnter the length of the second string: \n";
	int len2 = 0;
	cin >> len2;
	char *str2 = new char[len2 + 1];
	cout << "\nEnter the second string: \n";
	cin >> str2;
	int l2 = strlen(str2);

	if (l2 != l1)
	{
		cout << "The sizes are not equal.";
	}
	else
	{	
		hsort(str1,l1);
		hsort(str2,l2);

		bool equality = true;
		for (int i = 0; i < l1; i++)
		{
			if (str1[i] != str2[i])
				equality = false;
		}

		if (equality) 
			cout << "The second string is an anagram to the first string. ";
		else
			cout << "The second string is not an anagram to the first string. ";
	}
	
	char exit;
	cin >> exit;

	delete[] str1;
	delete[] str2;

	
}