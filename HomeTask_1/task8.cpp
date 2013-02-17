#include <iostream>
using namespace std;

int f(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * f (n-1);
}

int main()
{
	int n = 0;
	cout << "Enter the number: \n";
	cin >> n;
	if (n < 0) 
	{
		return 0;
	}
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= i;
	}
	int q = f(n); 
	cout << n << "! = " << p << "(int)\n";
	cout << n << "! = " << q << "(rec)";
	cin >> n;

}
