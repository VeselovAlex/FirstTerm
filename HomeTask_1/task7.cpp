#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "Enter the max number\n";
	cin >> n;
	cout << "1 ";
	bool f = 1;
	for (int i = 2; i <= n; i++)
	{
		f = 1;
		for (int j = 2; j*j <= i; j++)
		{
			if ((i % j) == 0) 
			{
				f = 0;
			}
		}
		if (f)
		{
			cout << i << " ";
		}
	}
	cin >> n;
}