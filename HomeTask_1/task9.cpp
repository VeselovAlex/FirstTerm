# include <iostream>
using namespace std;

int main()
{
	int x = 0;
	cout << "������� ��������� �������: \n"; //P.S. ��� ����������� �� ���� � ����������?
	cin >> x;
	int n = 0;
	cout << "������� ���������� �������: \n";
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