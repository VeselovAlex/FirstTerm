#include <iostream>
#include"list.h"
using namespace std;

int main()
{
	int menu = 0;
	List *list = createList();
	
	cout << "Hello! How can I help you?\n";
	cout << "0 - exit\n";
	cout << "1 - add value to sorted list\n";
	cout << "2 - remove value from list\n";
	cout << "3 - print list\n";

	while (true)
	{
		cout << "\nType command here\n";
		cin >> menu;
		if (menu == 0) 
		{
			if(!isEmpty(list))
				clearList(list);
			delete list;
			return 0;
		}
		switch (menu)
		{
			
			case 1:
			{
				cout << "Enter the new value: ";
				int newValue;
				cin >> newValue;
				addValue(list, newValue);
				cout << "The new value has been successfully added.";
				break;
			}
			case 2:
			{
				cout << "Enter the value to remove: ";
				int value;
				cin >> value;
				if (checkValue(list,value))
				{
					removeValue(list, value);
					cout << "The value has been successfully removed.";
				}
				else
				{
					cout << "The value does not exist.";
				}
				break;
			}
			case 3:
			{
				printList(list);
				break;
			}

			default:
			{
				cout << "(X) Invalid operation! ";
				break;
			}
			break;
		}
	}
}