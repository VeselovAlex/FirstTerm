#include <iostream>
using namespace	std;

int step(int k, int n)
{
	if (n == 0) 
	{
		return 1;
	}
	if (n == 1)
	{
		return k;
	}
	int z = step (k, n / 2);
	if ((n % 2) == 1) 
	{
		return z * z * k;
	}
	return z * z;
}

int main()
{
	cout << "Enter the base: \n";
	int k = 0;
	cin >> k;
	cout << "Enter the power: \n";
	int n = 0;
	cin >> n;
	int p = step(k, n);
	cout << k << "^" << n << " = " << p;
	cin >> k;
}