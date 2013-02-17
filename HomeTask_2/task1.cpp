# include <iostream>
using namespace std;

int fib( int n)
{
	if ((n == 1)|(n == 2)) return 1;
	return fib(n - 1) + fib (n - 2);
}

int main()
{
	cout << "Enter the number of element: \n";
	int n;
	cin >> n;
	int a1 = 1, a2 = 1, fi = 1;
	for (int i = 3; i <= n; i++)
	{
		fi = a1 + a2;
		a1 = a2;
		a2 = fi;
	}
	int q = fib(n);
	cout << "Element #" << n << " = " << q << " = " << fi << endl;
	cin >> n;
}