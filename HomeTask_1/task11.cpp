# include <iostream>
using namespace std;

int a[5]={1,1,8,3,2};
int n = 4;
void quicksort(int first, int last )
{
	int o = a[(last / 2)];
	int j = last;
	int i = first;
	while (i <= j)
	{
		while (a[i] < o) 
		{
			i++;
		}
		while (a[j] > o) 
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i],a[j]);
		}
		i++;
		j--;
	}
	if (j > 1) quicksort(0,j);
	if (n > i) quicksort(i,n);
}
int main()
{
	quicksort(0,4);
	for (int i = 0; i < 5; i++)
	{
		cout << a[i];	
	}
	cin >> n;
}