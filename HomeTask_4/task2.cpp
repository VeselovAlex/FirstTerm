#include <iostream>
using namespace std;

int main()
{
	const int size = 5;
	int matrix[size][size] = 
	{
		{ 1, 2, 3,10,11},
		{ 4, 5, 6,12,13},
		{ 7, 8, 9,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	int center = size / 2;
	cout << matrix[center][center] << " ";
	int start = center;
	for (int layer = 1; layer <= center; layer++)
	{
		int top = center - layer;
		int bottom = center + layer;
		
		int left = top;
		int right = bottom;
		
		for (int i = start; i <= right; i++)
		cout << matrix[top][i] << " ";
		
		for (int j = top + 1; j <= bottom; j++)
		cout << matrix[j][right] << " ";
		
		for (int i = right - 1; i >= left; i--)
		cout << matrix[bottom][i] << " ";
		
		for (int j = bottom - 1; j >= top + 1; j--)
		cout << matrix[j][left] << " ";
		
		for (int i = left; i < start; i++)
		cout << matrix[top][i] << " ";
		
		start--;
	
	}
	cout << "\n";
	cin >> start;


}