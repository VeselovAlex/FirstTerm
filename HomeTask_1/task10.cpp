#include <iostream>
using namespace std;

int main()
{
	char s[30];
	cout << "Enter string: ";
	cin >> s;
	int l = strlen(s);
	bool f = true;
	for (int i = 0; i <= (l / 2); i++)
	{
		f = f && (s[i] == s[l - i - 1]);
	}
	if (f)
	{
		cout << "\n Palindrome";
	}
	else 
	{
		cout << "\n Not palindrome";	
	}
	cin >> l;
}
