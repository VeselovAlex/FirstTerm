#include "polynome.h"
#include <iostream>


void init(Polynome **poly, const int size)
{
	for (int i = 0; i < size; i++)
	{
		poly[i] = createPoly();
	}
}

int main()
{
	const int size = 10;
	int checkFill = 0;
	Polynome** poly = new Polynome*[size];
	init (poly, size);

	while (true)
	{
				
		std::string command = "";
		std::cout << "Type command here, or type \"?\" for help:\n";
		std::cin >> command;

		if (command == "?") 
		{
			std::cout << "List of commands:\n";
			std::cout << "input - type polynome\n";
			std::cout << "delete - delete polynome\n";
			std::cout << "value - find value of polynome\n";
			std::cout << "equals - check polynomes' equality\n";
			std::cout << "add - add polynome as a summ of two polynomes\n";
			std::cout << "exit - finish the work\n";
		}
		else if (command == "delete")
		{
			if (checkFill == 0)
			{
				std::cout << "(X) Polynome not found\n";
				continue;
			}
			std::cout << "Type polynome number( < " << size << "):\n";
			int polyNum = 0;
			std::cin >> polyNum;

			while ((polyNum > size) || (poly[polyNum]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type polynome number( < " << size << "):\n";
				std::cin >> polyNum;
			}

			destroyPoly(poly[polyNum]);
			poly[polyNum] = createPoly();
			checkFill--;
		}
		else if (command == "add") 
		{
			checkFill++;
			if ((checkFill > size) || (checkFill < 3))
			{
				std::cout << "(X) Out of memory or not enough polynomes\n";
				continue;
			}

			std::cout << "Type first polynome number( < " << size << "):\n";
			int polyNum1 = 0;
			std::cin >> polyNum1;

			while ((polyNum1 > size) || (poly[polyNum1]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type first polynome number( < " << size << "):\n";
				std::cin >> polyNum1;
			}

			std::cout << "Type second polynome number( < " << size << "):\n";
			int polyNum2 = 0;
			std::cin >> polyNum2;

			while ((polyNum2 > size) || (poly[polyNum2]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type second polynome number( < " << size << "):\n";
				std::cin >> polyNum2;
			}

			std::cout << "Type new polynome number( < " << size << "):\n";
			int polyNum = 0;
			std::cin >> polyNum;

			while ((polyNum > size) || (poly[polyNum]->head != nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type polynome number( < " << size << "):\n";
				std::cin >> polyNum;
			}

			poly[polyNum] = summ(poly[polyNum1], poly[polyNum2]);
		}
		else if (command == "equals") 
		{
			if (checkFill < 2)
			{
				std::cout << "(X) Polynome not found\n";
				continue;
			}
			std::cout << "Type first polynome number( < " << size << "):\n";
			int polyNum1 = 0;
			std::cin >> polyNum1;

			while ((polyNum1 > size) || (poly[polyNum1]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type first polynome number( < " << size << "):\n";
				std::cin >> polyNum1;
			}

			std::cout << "Type second polynome number( < " << size << "):\n";
			int polyNum2 = 0;
			std::cin >> polyNum2;

			while ((polyNum2 > size) || (poly[polyNum2]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type second polynome number( < " << size << "):\n";
				std::cin >> polyNum2;
			}

			std::cout << "Polynomes " << polyNum1 << " and " << polyNum2 << " are ";
			if (!equals(poly[polyNum1], poly[polyNum2]))
				std::cout << "not ";
			std::cout << "equal.\n";
		}
		else if (command == "input") 
		{
			checkFill++;
			if (checkFill > size)
			{
				std::cout << "(X) Out of memory\n";
				continue;
			}
			std::cout << "Type polynome number( < " << size << "):\n";
			int polyNum = 0;
			std::cin >> polyNum;

			while ((polyNum > size) || (poly[polyNum]->head != nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type polynome number( < " << size << "):\n";
				std::cin >> polyNum;
			}

			std::cout << "Type polynome\n";
			std::string polinome = "";
			std::cin >> polinome;

			inputPoly(poly[polyNum], polinome);
		}
		else if (command == "value") 
		{
			if (checkFill == 0)
			{
				std::cout << "(X) Polynome not found\n";
				continue;
			}
			std::cout << "Type polynome number( < " << size << "):\n";
			int polyNum = 0;
			std::cin >> polyNum;

			while ((polyNum > size) || (poly[polyNum]->head == nullptr))
			{
				std::cout << "(X) Invalid number\n";
				std::cout << "Type polynome number( < " << size << "):\n";
				std::cin >> polyNum;
			}

			std::cout << "Type variant's value\n";
			int var = 0;
			std::cin >> var;

			std::cout << polyNum << "(" << var << ") = " << value(poly[polyNum], var) << std::endl;
		}
		else if (command == "exit") 
		{
			for (int i = 0; i < size; i++)
				destroyPoly(poly[i]);
			delete[] poly;
			return 0;
		}
		else 
		{
			std::cout << "(X) Invalid command\n";
		}
		std::cout << std::endl;
	}
	return 0;
}