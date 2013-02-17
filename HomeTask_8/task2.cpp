#include <limits.h>
#include <stdio.h>

using namespace std;

int minimum(int a, int b)
{
	if (a > b) 
		return b;
	return a;
}


int main()
{
	int size = 0;
	int buffer = 0;
	FILE *input = fopen("test1.txt", "r+");
	
	if (input == NULL)
		return 0;
	
	fscanf(input, "%d %d", &size, &buffer);

	int **graph = new int*[size];
	int l = 0;
	for (l = 0; l < size; l++)
	{
		graph[l] = new int [size];
		for (int j = 0; j < size; j++)
			graph[l][j] = 0;
	}
	l = 0;
	int m = 0;
	int len = 0;

	while (!feof(input))
	{
		fscanf(input,"%d %d %d", &l, &m, &len);
		graph[l-1][m-1] = len;
	}

	fclose(input);

	int *path = new int[size];
	path[0] = 0;
	for (int i = 1; i < size; i++)
		path[i] = INT_MAX;
	
	int fixMin = 0;
	int numMin = 0;

	int* way = new int[size];
	way[0] = 1;
		
	for (int i = 0; i < size; i++)
	{
		way[i] = 0;

		if (graph[numMin][i] != 0)
		{
			path[i] = graph[numMin][i];
			way[i] = 1;
		}

	}

	for (int j = 1; j < size; j++)
	{
		int min = INT_MAX;
		for (int i = 0; i < size; i++)
			if ((path[i] > fixMin) && (path[i] < min))
			{
				min = path[i];
				numMin = i;
			}
		fixMin = min;
		for (int i = 0; i < size; i++)
		{
			if ((path[i] > fixMin) && (graph[numMin][i] != 0))
			{
				int buf = path[i];
				path[i] = minimum(path[i], fixMin + graph[numMin][i]);
				if (buf != path[i])
				{
					way[i] = numMin + 1;
				}
			}
		}
	}
					

	int *vert = new int[size];
	vert[0] = 1;
	for (int i = 1; i < size; i++)
		vert[i] = 0;
	int active = 0;
	int i = 1;
	
	while (i != size)
	{
		int nMin = 0;
		int min = INT_MAX;
		
		for (int j = 0; j < size; j++)
		{	 
			if ((path[j] < min) && (path[j] > path[active]))
			{
				nMin = j;
				min = path[j];
			}
		}
		
		if (nMin == 0)
			for (int j = active; j < size; j++)
				if (path[j] == path[active])
					nMin = j;
		
		active = nMin;
		vert[i] = active + 1;
		i++;
	}
	vert[0] = 1;

	way[0] = 1;

	for (int i = 1; i < size; i++)
	{
		printf("%d\n", vert[i]);
		printf("%d - %d\n",vert[i], path[vert[i] - 1]);
		int vertex = i + 1;
		while (vertex != 1)
		{
			printf ("%d<- ", vertex);
			vertex = way[vert[vertex - 1] - 1];
		}
		printf("1\n\n");
	}
	
	for (int i = 0; i < size; i++)
		delete[] graph[i];
	delete[] graph;
	delete[] vert;
	delete[] path;
	delete[] way;
	scanf(" ");

}