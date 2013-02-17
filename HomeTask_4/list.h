#pragma once;
struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement* head;
	ListElement* last;
	int size;
};

List *createList();
void clearList(List *list);
bool isEmpty(List *list);
void addValue(List *list, int value);
void printList(List *list);
bool checkValue(List *list, int value);
void removeValue(List *list, int value);
