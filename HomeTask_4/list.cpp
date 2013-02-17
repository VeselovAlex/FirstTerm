#include "list.h"
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
	while (list->head->next != NULL)
	{
		tmp = list->head->next;
		list->head->next = tmp->next;
		delete tmp;
	}
	delete list->head;
}
bool isEmpty(List *list)
{
	return list->head == NULL;
}

void addValue(List *list, int value)
{
	list->size++;
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->last = list->head;
		list->head->value = value;
		list->head->next = NULL;
	}
	else
	{
		ListElement *newEl = new ListElement;
		if (value <= list->head->value)
		{
			newEl->next = list->head;
			newEl->value = value;
			list->head = newEl;
		}
		else if (value >= list->last->value)
		{
			newEl->value = value;
			list->last->next = newEl;
			list->last = newEl;
			newEl->next = NULL;
		}
		else
		{
			ListElement *tmp = list->head;
			while (tmp->next->value < value) 
				tmp = tmp->next;
			newEl = tmp->next;
			newEl->value = value;
			tmp->next = newEl;
		}
	}
}

void printList(List *list)
{
	ListElement *tmp = list->head;
	if (isEmpty(list))
	{
		std::cout << "The list is empty.\n";
	}
	else
	{
		std::cout << "The list contains: ";
		while (tmp != NULL)
		{
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}
}

bool checkValue (List *list, int value)
{
	bool result = false;
	ListElement *temp = list->head;
	while (temp != NULL)
	{
		result = result || (temp->value == value);
		temp = temp->next;
	}
	return result;
}

void removeValue(List *list,int value)
{
	if (!isEmpty(list))
	{
		ListElement *preremoved = list->head;
		if (list->head->value == value)
		{
			list->head = list->head->next;
			delete preremoved;
		}
		else
		{
			while (preremoved->next->value != value)
				preremoved = preremoved->next;
			if (preremoved->next == list->last)
				list->last = preremoved;
			preremoved->next = preremoved->next->next;
			delete preremoved->next;
		}
	list->size--;
	}
	
}