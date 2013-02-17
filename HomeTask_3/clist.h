#include <stdlib.h>

struct CircleListElement
{
	CircleListElement *next;
	int value;
};

struct CircleList
{
	CircleListElement *head;
	int size;
	CircleListElement *last;
};

CircleList *createCList();
void addElem(CircleList *clist, int num);//Добавляет участника № num к списку
void remElem(CircleList *clist, int num);//Удаляет каждого k-того участника
CircleList *createRoulette(int size);//Создает список игроков
void remEl (CircleList *clist, CircleListElement *element);//Удаляет элемент из списка