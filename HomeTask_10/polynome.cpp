#include <iostream>
#include <string>
#include "polynome.h"
#include "getdouble.h"
using namespace std;

Polynome* createPoly()
{
	Polynome *newP = new Polynome;
	newP->head = nullptr;
	return newP;
}

void destroyPoly(Polynome *poly)
{
	if (poly->head != nullptr)
	{
		Monome *tmp = poly->head;
		while (poly->head->next != nullptr)
		{
			tmp = poly->head->next;
			delete poly->head;
			poly->head = tmp;
		}
		delete poly->head;
	}
	delete poly;
}

void addMonome(Polynome *poly, int deg, double index)
{
	if (poly->head == nullptr)
	{
		poly->head = new Monome;
		poly->head->deg = deg;
		poly->head->index = index;
		poly->head->next = nullptr;
	}
	else if (poly->head->deg > deg)
	{
		Monome* nMon = new Monome;
		nMon->index = index;
		nMon->next = poly->head;
		poly->head = nMon;
		nMon->deg = deg;
	}
	else
	{
		Monome* tmp = poly->head;
		while ((tmp->next != nullptr) && (tmp->next->deg < deg))
		{
			tmp = tmp->next;
		}
		Monome* nMon = new Monome;
		nMon->index = index;
		nMon->next = tmp->next;
		tmp->next = nMon;
		nMon->deg = deg;
	}
}

int typeP(char symbol)
{
	if ((symbol == ' ') || (symbol == '\t'))
		return 0;
	if ((symbol >= '0') && (symbol <= '9'))
		return 1;
	if ((symbol >= 'a') && (symbol <= 'z'))
		return 2;
	if (symbol == '*')
		return 5;
	if (symbol == '^')
		return 3;
	if ((symbol == '+') || (symbol == '-'))
		return 4;
	if ((symbol == '\n') || (symbol == '\0'))
		return 6;
	return -1;
}


void inputPoly(Polynome *poly, string expr)
{
	int statement = 0;
	int input = 0;
	char buffer = ' ';
	int pos = -1;
	char var = ' ';

	double nIndex = 0;
	int nDeg = 0;
	int nsign = 1;

	while (true)
	{
		enum State
		{
			delim,
			index,
			deg,
			variant,
			exit,
			error = -1,
		};

		enum Type
		{
			space,
			number,
			letter,
			power,
			sign,
			multy,
			end,
			invalid = -1,
		};
				
		

		switch (statement)
		{
		case delim:
			{
				cout << "Delim->";
				pos++;
				input = typeP(expr[pos]);
				switch (input)
				{
				case space:
					{
						statement = delim;
						break;
					}
				case number:
					{
						statement = index;
						break;
					}
				case letter:
					{
						nIndex = 1;
						statement = variant;
						break;
					}
				case power:
					{
						statement = error;
						break;
					}
				case sign:
					{
						if (expr[pos] == '-')
							nsign = -1;
						else
							nsign = 1;
						statement = delim;
						break;
					}
				case multy:
					{
						statement = error;
						break;
					}
				case end:
					{
						statement = exit;
						break;
					}
				case invalid:
					{
						statement = error;
						break;
					}
				default:
					break;
				}
				break;
			}
		case index:
			{
				cout << "Index->";
				string sNumber = "";
				while ((typeP(expr[pos]) == number) || (expr[pos] == '.'))
				{
					sNumber += expr[pos];
					pos++;
				}
				nIndex = getDouble(sNumber);
				
				input = typeP(expr[pos]);
				switch (input)
				{
				case space:
					{
						statement = error;
						break;
					}
				case number:
					{
						break;
					}
				case letter:
					{
						statement = error;
						break;
					}
				case power:
					{
						statement = error;
						break;
					}
				case sign:
					{
						if (expr[pos] == '-')
							nsign = -1;
						else
							nsign = 1;
						addMonome(poly, nDeg, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						statement = delim;
						break;
					}
				case multy:
					{
						statement = variant;
						pos++;
						break;
					}
				case end:
					{
						addMonome(poly, 0, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						statement = exit;
						break;
					}
				case invalid:
					{
						statement = error;
						break;
					}
				default:
					break;
				}
				break;
			}
		case deg:
			{
				cout << "Deg->";
				nDeg = nDeg * 10 + (expr[pos] - '0');
				pos++;
				
				input = typeP(expr[pos]);
				switch (input)
				{
				case space:
					{
						addMonome(poly, nDeg, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						statement = delim;
						break;
					}
				case number:
					{
						statement = deg;
						break;
					}
				case letter:
					{
						statement = error;
						break;
					}
				case power:
					{
						statement = error;
						break;
					}
				case sign:
					{
						addMonome(poly, nDeg, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						if (expr[pos] == '-')
							nsign = -1;
						else
							nsign = 1;
						statement = delim;
						break;
					}
				case multy:
					{
						statement = error;
						break;
					}
				case end:
					{
						addMonome(poly, nDeg, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						statement = exit;
						break;
					}
				case invalid:
					{
						statement = error;
						break;
					}
				default:
					break;
				}
				break;
			}
		case variant:
			{
				cout << "Variant->";
				if (var == ' ')
					var = expr[pos];
				else if (var != expr[pos])
				{
					statement = error;
					continue;
				}

				pos++;
				input = typeP(expr[pos]);
				switch (input)
				{
				case space:
					{
						statement = delim;
						nIndex = nsign;
						nDeg = 1;
						addMonome(poly, nDeg, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						break;
					}
				case number:
					{
						statement = error;
						break;
					}
				case letter:
					{
						statement = error;
						break;
					}
				case power:
					{
						pos++;
						statement = deg;
						break;
					}
				case sign:
					{
						addMonome(poly, 1, nsign * nIndex);
						nIndex = 0;
						nDeg = 0;
						nsign = 1;
						if (expr[pos] == '-')
							nsign = -1;
						else
							nsign = 1;
						statement = delim;
						break;
					}
				case multy:
					{
						statement = error;
						break;
					}
				case end:
					{
						addMonome(poly, 1, nsign * nIndex);
						statement = exit;
						break;
					}
				case invalid:
					{
						statement = error;
						break;
					}
				default:
					break;
				}
				break;
			}
		case exit:
			{
				cout << "Exit\n";
				return;
				
				break;
			}
		case error:
			{
				cout << "(X) invalid polynome\n";
				destroyPoly(poly);
				poly = createPoly();
				return;
			}

		}	
	}
}

bool equals(Polynome *poly1, Polynome *poly2)
{
	Monome *tmp1 = poly1->head;
	Monome *tmp2 = poly2->head;

	while ((tmp1 != nullptr) && (tmp2 != nullptr))
	{
		if ((tmp1->deg != tmp2->deg) || (tmp1->index != tmp2->index))
			return false;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	if (tmp1 != tmp2)
		return false;

	return true;
}

double value (Polynome *poly, int x)
{
	int deg = 0;
	long int power = 1;
	double sum = 0;

	Monome *tmp = poly->head;

	while (tmp != nullptr)
	{
		if (tmp->deg == deg)
		{
			sum = sum + power * tmp->index;
			power *= x;
			deg++;
			tmp = tmp->next;
		}
		else
		{
			power *= x;
			deg++;
		}
	}

	return sum;
}

Polynome *summ(Polynome *poly1, Polynome *poly2)
{
	Monome *tmp1 = poly1->head;
	Monome *tmp2 = poly2->head;
	Polynome *result = createPoly();

	while ((tmp1 != nullptr) && (tmp2 != nullptr))
	{
		if (tmp1->deg == tmp2->deg)
		{
			addMonome(result, tmp1->deg, tmp1->index + tmp2->index);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		else if (tmp1->deg > tmp2->deg)
		{
			addMonome(result, tmp1->deg, tmp1->index);
			tmp1 = tmp1->next;
		}
		else
		{
			addMonome(result, tmp2->deg, tmp2->index);
			tmp2 = tmp2->next;
		}
	}

	return result;
}