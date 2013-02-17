#include <iostream>;
using namespace std;

void sums(int *a, int number, int sum, int pos)
{
	int csum = sum;
	int num = number - sum;
	for (a[pos] = 2; a[pos] <= num; a[pos]++)
	{
		if (pos > 0)
		{ 
			if (a [pos] > a[pos-1])
			{
				break;
			}
			for (int i = 0; i < pos; i++)
			{
				cout << a[i] << " ";
			}
		}
		sum = csum + a[pos];
		cout << a[pos] << " ";
		int i = pos;
		int asum = a[pos];
		while (asum <= (num - 1))
		{
			i++;
			a[i] = 1;
			cout << a[i] << " ";
			asum++;
		}
		cout << "\n";
		if (sum <= num)
		{
			sums(a, number,sum,pos + 1);
		}
	}
}

int main()
{
	int number = 0;
	cout << "Enter the number \n";
	cin >> number;
	int a[20]={};
	for (int i = 0; i < number; i++)
	{
		a[i] = 1;
		cout << a[i] << " ";
	}
	cout << "\n";
	sums(a,number,0,0);
	cin >> number;
}