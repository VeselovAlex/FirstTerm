#include <iostream>
#include "hsort.h"

using namespace std;

void screen(int *a, int size, int pos)
{
	int max = pos;
	int el = a[pos];
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

void hsort(int *a, int size)
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

int main()
{
	int a[10] = {5,3,8,12,49,5,7,76,15,11};
	cout << "Enter the number of elements: (<=10)";
	int size = 0;
	cin >> size;
	hsort(a, size-1);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cin >> size;

}