#include "listchar.h"
#include "stdlib.h"
#include <iostream>

List *createList()
{
	List *list = new List;
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}
void clearList(List *list)
{
	ListElement *tmp = list->head;
	while (!isEmpty(list))
	{
		tmp = list->head->next;
		delete[] list->head->value;
		delete list->head;
		list->head = tmp;
	}
	list->size = 0;
}
bool isEmpty(List *list)
{
	return list->head == NULL;
}

void printList(List *list)
{
	ListElement *tmp = list->head;
	if (isEmpty(list))
	{
		return;
	}
	else
	{
		while (tmp != NULL)
		{
			std::cout << tmp->value << " " <<tmp->count << std::endl;
			tmp = tmp->next;
		}
	}
}



bool areEqual(char* st1, char* st2)
{
	int l1 = strlen(st1);
	int l2 = strlen(st2);
	if (l1 != l2)
		return false;
	for (int i = 0; i < l1; i++)
		if (st1[i] != st2[i]) 
			return false;
	return true;
}

void addString(List *list, char* string)
{
	
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->last = list->head;
		list->head->count = 1;
		list->head->value = string;
		list->head->next = NULL;
	}
	else
	{
		ListElement *tmp = list->head;
		while ((tmp->next != NULL) && (!areEqual(tmp->value,string)))
		{
			tmp = tmp->next;
		}
		if (areEqual(tmp->value,string))
		{
			tmp->count++;
			return;
		}
		ListElement *newString = new ListElement;
		newString->value = string;
		tmp->next = newString;
		list->last = newString;
		newString->count = 1;
		newString->next = NULL;
	}
	list->size++;
}



void removeString(List *list,char* string)
{
	if (!isEmpty(list))
	{
		ListElement *preremoved = list->head;
		if (list->head->value == string)
		{
			list->head = list->head->next;
			delete preremoved;
		}
		else
		{
			while (preremoved->next->value != string)
				preremoved = preremoved->next;
			if (preremoved->next == list->last)
				list->last = preremoved;
			preremoved->next = preremoved->next->next;
			delete preremoved->next;
		}
	list->size--;
	}
	delete[] string;
}

