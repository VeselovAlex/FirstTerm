#include <iostream>
using namespace std;

int main()
{
	int a[28];
	int i = 0, j = 0, k = 0;
	for (i = 0; i <= 27; i++)
	{
		a[i] = 0;		
	}

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				a[i + j + k]++; 
			}	
		}
	}
	long int S = 0;
	for (i = 0; i <= 27; i++)
	{
		S = S + a[i] * a[i];		
	}
	cout << "There is " << S <<" lucky tickets!";
	cin >> S;
}