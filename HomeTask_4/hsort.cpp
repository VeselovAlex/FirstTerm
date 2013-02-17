#include <iostream>
#include "hsort.h"

using namespace std;

void screen(char *a, int size, int pos)
{
	int max = pos;
	char el = a[pos];
	while (pos < size / 2)
	{
		int next = pos * 2 + 1;
		if ((next < size) && (a[next] > el))
		{
			max = next;
		}
		int next2 = next + 1;
		if ((next2 < size) && (a[next2] > a[max]))
		{
			max = next2;
		}
		if (max == pos) 
		{
			break;
		}
		a[pos] = a[max];
		a [max] = el;
		pos = max;
	}
}

void hsort(char *a, int size)
{
	for(int i = (size / 2) - 1; i >= 0; i--) 
	{ 
		screen(a, size,i);
	}
	while (size > 1)
	{
		size--;
		swap(a[0],a[size]);
		screen(a, size, 0);
	}
}

