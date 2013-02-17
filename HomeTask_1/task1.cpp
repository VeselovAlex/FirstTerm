#include <iostream>

int main()
{ 
	int x = 0;
	std::cout << "Enter X:";
	std::cin >> x;
	int y = x * x;
	y = 1 + (y + x) * (y + 1);
	std::cout << "x^4+x^3+x^2+x+1= "<< y;
	std::cin >> x;
}
 