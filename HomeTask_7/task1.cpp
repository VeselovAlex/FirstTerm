#include <stdio.h>

void fillChain (int *cheat, int *variant, int num, int &buffer)
{
	
	if ((cheat[num] == 1) || (cheat[num] == 2) || (cheat[num] == 3))
	{
		variant[num] = cheat[num];
		buffer = cheat[num];
	}
	else
	{
		fillChain(cheat, variant, cheat[num]-1, buffer);
		variant[num] = buffer;
	}
}

int main()
{
	FILE *create = fopen("InputList.txt", "a");
	fclose(create);
	
	FILE *output = fopen("OutputList.txt", "w");
	
	FILE *input = fopen("InputList.txt", "r");
	int aver = 0;
	fscanf(input, "%d\n",&aver);
	int *cheat = new int[aver];
	int *variant = new int[aver];
	
	for (int i = 0; i < aver; i++)
	{
		cheat[i] = 0;
		variant[i] = 0;
	}
	
	for (int i = 0; i < aver; i++)
	{
		int studNum = 0;
		int cheatBuffer = 0;
		fscanf(input, "%d %d\n", &studNum,&cheatBuffer);
		cheat[studNum - 1] = cheatBuffer;
	}
	variant[0] = 1;
	variant[1] = 2;
	variant[2] = 3;

	int varBuffer = 0;
	

	for (int i = 0; i < aver; i++)
	{
		if ((cheat[i] != 0) && (variant[i] == 0))
		{
			fillChain(cheat, variant, i, varBuffer);
			varBuffer = 0;

		}
		fprintf(output, "%d %d\n", i + 1, variant[i]);
	}
	delete[] cheat;
	delete[] variant;
	fclose(input);
	fclose(output);
}