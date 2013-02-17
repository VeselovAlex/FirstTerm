#include<iostream>
using namespace std;

int main()
{
	char s[30],s1[30];
	cout << "Enter string: \n";
	cin >> s;
	cout << "Enter sub-string: \n";
	cin >> s1;
	int l = strlen(s), l1 = strlen(s1);
	bool f = 0;
	int k = 0;
	for (int i = 0; i <= l; i++)
	{
		f = 1;
		for (int j = 0; j < l1; j++)
		{
			f = f && (s1[j] == s[i + j]);
		}
		if (f) 
		{
			k++;
		}
	}
	cout << k <<" times";
	cin >> k;
}