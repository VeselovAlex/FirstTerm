#pragma once
#include <string>

struct Monome
{
	int deg;
	double index;
	Monome* next;
};

struct Polynome
{
	Monome* head;	
};

void addMonome(Polynome *poly, int deg, double index);
Polynome *createPoly();
void inputPoly(Polynome *poly, std::string expr);
Polynome *summ(Polynome *poly1, Polynome *poly2);
double value (Polynome *poly, int x);
bool equals(Polynome *poly1, Polynome *poly2);

void destroyPoly(Polynome *poly);