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
	while (list->head->next != NULL)
	{
		tmp = tmp->next;
		delete list-> head;
		list->head = tmp;
	}
	delete list->head;
	list->size = 0;
}
bool isEmpty(List *list)
{
	return list->head == NULL;
}

void addValue(List *list, char value)
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

void addLetter(List *list, char letter)
{
	
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->last = list->head;
		list->head->value = letter;
		list->head->next = NULL;
	}
	else
	{
		ListElement *tmp = list->head;
		while (tmp->next != NULL)
		{
			if (tmp->value == letter)
				return;
			tmp = tmp->next;
		}
		if (tmp->value == letter)
			return;
		ListElement *newLetter = new ListElement;
		newLetter->value = letter;
		tmp->next = newLetter;
		list->last = newLetter;
		newLetter->next = NULL;
	}
	list->size++;
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
			std::cout << tmp->value;
			tmp = tmp->next;
		}
	}
	std::cout << " " ;
}

bool checkValue (List *list, char value)
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

void removeValue(List *list,char value)
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