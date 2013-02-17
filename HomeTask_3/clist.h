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
void addElem(CircleList *clist, int num);//��������� ��������� � num � ������
void remElem(CircleList *clist, int num);//������� ������� k-���� ���������
CircleList *createRoulette(int size);//������� ������ �������
void remEl (CircleList *clist, CircleListElement *element);//������� ������� �� ������