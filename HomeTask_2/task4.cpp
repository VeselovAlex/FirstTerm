#include <iostream>
using namespace std;

int NOD(int a, int b)
{
	while (a != b)
	{
		if (a > b) 
		{
			a -= b;
		}
		else if (a != b)
		{
			b -= a;
		}
	}
	return a;
}

int main()
{
	cout << "Enter the number: ";
	int num = 0;
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (NOD(i,j) == 1) 
			{
				cout << j << "/" << i <<endl;
			}
		}
	}

	cin >> num;
}