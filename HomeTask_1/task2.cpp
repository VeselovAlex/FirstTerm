#include <iostream>

int main()
{
	int a = 0, b = 0;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	int c = 0;
	while (a > b)
	{
		a = a - b;
		++c;
	}

	std::cout << "\na div b = " << c;
	std::cin >> a;
}