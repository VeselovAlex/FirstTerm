#include <iostream>
using namespace std;

int main()
{
	const int l = 20;
	char s[l];
	cout << "Enter string: ";
	cin >> s;
	int i = 0, k = 0;
	for (i = 0; i <= l; i++)
	{
		if (s[i] == '(') 
		{
			k++;
		}
		else if (s[i] == ')')
		{
			k--;
		}
		if (k < 0) break;
	}
	if (k == 0) 
	{
		cout << "It's all right! :)";
	}
	else
	{
		cout << "There's a little mistake! :(";
	}
	cin >> k;
}