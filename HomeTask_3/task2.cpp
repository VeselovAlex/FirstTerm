#include <iostream>
#include "clist.h"
#include "stdlib.h"

using namespace std;

int main()
{
	int size;
	cout << "Enter the number of players: ";
	cin >> size;
	
	int i = 0;
	cout << "\nEnter the player to save: ";
	cin >> i;
	
	CircleList *roulette = createRoulette(size);
		
	bool alive = 0;
	
	for (int k = 2; k <= size; k++)
	{
		remElem(roulette,k);
		if (roulette->head->value == i)
		{
			if (!alive) 
				cout << "\nThe answer is "<< k;
			else
				cout << " or " << k;
			alive = 1;
		}
		delete roulette->head;
		delete roulette;
		roulette = createRoulette(size);
	}
	
	if (!alive) 
		cout<< "\nSorry, but you will die.";
	remElem(roulette,1);
	delete roulette->head;
	delete roulette;


	cin >> size;
}