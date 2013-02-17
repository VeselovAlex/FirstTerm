#include <iostream>
using namespace std;

int main()
{
	int m = 0, n = 0;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	const int k = m + n;
	int a[100];
	int i = 0;
	for (i = 1; i <= k; i++)
	{
		a[i] = i;
	//}
	//for (i = m + 1; i <= k; i++)
	//{
	//	a[i] = i;
	}
	int b = 0, j = 0;
	for (i = 1; i <= m; i++)
	{
		b = a[1];
		for (j = 1; j <= k - 1; j++)
		{
			a[j] = a[j + 1];
		}
		a[k] = b;
	}
	for (i = 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	cin >> m;
}
