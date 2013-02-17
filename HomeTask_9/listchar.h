#pragma once;
struct ListElement
{
	char* value;
	int count;
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
void addValue(List *list, char value);
void addLetter(List *list, char letter);
void printList(List *list);
bool checkValue(List *list, char value);
void removeValue(List *list, char value);
void addString(List *list, char* string);
void removeString(List *list,char* string);
bool areEqual(char* st1, char* st2);
