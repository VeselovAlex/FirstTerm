#include <iostream>
#include <stdlib.h>
#include "clist.h"

using namespace std;

CircleList *createCList()
{
	CircleList *clist = new CircleList;
	clist->size = 0;
	clist->head = NULL;
	clist->last = NULL;
	return clist;
}

void addElem(CircleList *clist, int num)
{
	CircleListElement *nEl = new CircleListElement;
	
	if (clist->head == NULL)
	{
		clist->head = nEl;
		clist->last = nEl;
	}
	
	else
	{
		nEl->next = clist->head;
		clist->last->next = nEl;
		clist->last = nEl;
	}
	
	nEl->value = num;
	clist->size++;
}

void remElem(CircleList *clist, int num)
{
	CircleListElement *start = clist->head;
	while (clist->size > 1)
	{
		CircleListElement *remove = start;
		for(int i = 1; i < num; i++)
		{
			remove = remove->next;
		}
		start = remove->next;
		remEl (clist,remove);
	}
	clist->head->next = clist->head;
	clist->last = clist->head;
}

void remEl (CircleList *clist, CircleListElement *element)
{
	if (element == clist->head)
	{
		clist->head = clist->head->next;
		clist->last->next = clist->head;
		delete element;
	}
	
	else if (element == clist->last)
	{
		CircleListElement *previous = clist->head;
		while (previous->next != clist->last)
		{
			previous = previous->next;
		}
		previous->next = clist->head;
		clist->last = previous;
		delete element;
	}
	
	else if (clist->size > 2)
	{
	CircleListElement *previous = clist->head;
	while (previous->next != element)
	{
		previous = previous->next;
	}
	previous->next = element->next;
	delete element;
	}
	
	else
	{
		clist->head->next = clist->head;
		clist->last =clist->head;
		clist->last->next = clist->head;
		delete element;
	}
	
	clist->size--;
}

CircleList *createRoulette(int size)
{
	CircleList *roulette = createCList();
	for (int i = 1; i <= size; i++)
	{
		addElem(roulette, i);
	}
	return roulette;
}