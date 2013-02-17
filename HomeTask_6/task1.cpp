#include <iostream>
#include "bst.h"
using namespace std;

enum Menu
{
	quit,
	addVal,
	removeVal,
	check,
	printAcs,
	printDesc
};

int main()
{
	cout << "1. Add value to set;\n";
	cout << "2. Remove value from set;\n";
	cout << "3. Check value;\n";
	cout << "4. Print set in acsending order;\n";
	cout << "5. Print set in descending order;\n";
	cout << "0. Quit.\n";
	Tree *set = createTree();
	
	while(true)
	{
		int comm = 0;
		cout << "Type command here:\n";
		cin >> comm;
		

		switch (comm)
		{
			case quit:
			{
				clearTree(set);
				return 0;
				break;
			}
			case addVal:
			{
				int value = 0;
				cout << "Type value: ";
				cin >> value;
				add(set, value);
				cout << "The value has been successfully added.\n";
				break;
			}
			case removeVal:
			{
				int value = 0;
				cout << "Type value: ";
				cin >> value;
				remove(set, value);
				cout << "The value has been successfully removed.\n";
				break;
			}
			case check:
			{
				int value = 0;
				cout << "Type value: ";
				cin >> value;
				if (exists(set, value))
					cout << "This value is in the set.\n";
				else
					cout << "This value is not in the set.\n";
				break;
			}
			case printAcs:
			{
				if(set->root == NULL)
				{
					cout << "The set is empty:\n";
					break;
				}
				cout << "The set contains:\n";
				printInOrder(set);
				cout << '\n';
				break;
			}
			case printDesc:
			{
				if(set->root == NULL)
				{
					cout << "The set is empty:\n";
					break;
				}
				cout << "The set contains:\n";
				printInRevOrder(set);
				cout << '\n';
				break;
			}
			default:
				cout << "(x) Invalid command.\n";
				break;
		}
	}
}