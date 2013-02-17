#include <string.h>

int polynomeHash (char *string, int first, int last, int mod)
{
	int size = last - first + 1;
	long int hash = 0;
	int multi = 1;
	const int changes = 2;
	for (int i = first; i < last; i++)
	{
		multi *=changes;
	}
	for (int i = first; i <= last; i++)
	{
		hash = ((hash + (int)(string[i])*multi));
		multi = multi / changes;
	}
	hash = hash % mod;
	return hash;
}

int polynomeHash (char *string, int mod)
{
	return polynomeHash (string, 0, strlen(string) - 1, mod);
}

int hashSums(char *string, int first, int last, int mod)
{
	long int sum = 0;
	for (int i = first; i <= last; i++)
		sum = sum + string[i];
	int res = sum % mod;
	return res;
}

int hashSums (char *string, int mod)
{
	return hashSums (string, 0, strlen(string) - 1, mod);
}