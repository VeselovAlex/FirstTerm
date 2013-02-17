# include <iostream>
using namespace std;

int main()
{
	int x = 0;
	cout << "Введите основание степени: \n"; //P.S. Как избавляться от бага с кириллицей?
	cin >> x;
	int n = 0;
	cout << "Введите показатель степени: \n";
	cin >> n;
	float p = 1;
	for (int i = 1; i <= abs(n); i++)
	{
		p *= x;
	}
	if (n < 0)
	{
		p = 1 / p;
	}
	cout << x << "^" << n << " = " << p;
	cin >> x;
}