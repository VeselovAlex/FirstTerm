#include <iostream>
#include <string.h>
#include "getdouble.h"

using namespace std;

bool inDouble (char ch)
{
	if (((ch >= '0') && (ch <= '9')) || (ch == '.') || (ch == 'e') || (ch == 'E'))
		return true;
	return false;
}

int sumLeft(string expr, int &pos);// sL->mL sR
int sumRight(string expr, int &pos);// sR->+mL sR | NULL
int mulLeft(string expr, int &pos);// mL->gId mR
int mulRight(string expr, int &pos);// mR->*gId mR | NULL
int getId(string expr, int &pos);// gId->(sL) | id

int checkExpr (string expr)
{
	int pos = 0;
	return sumLeft(expr, pos);
}

int sumLeft(string expr, int &pos)
{
	if ((mulLeft(expr, pos) == 0) && (sumRight(expr, pos) == 0))
		return 0;
	//cout << "sL! \n";
	return 1;
}

int sumRight(string expr, int &pos)
{
	if ((expr[pos] == '\0') || (expr[pos] == ')') || (expr[pos] == '\n') || (expr[pos] == '*') || (expr[pos] == '/'))
		return 0;
	if ((expr[pos] == '+') || (expr[pos] == '-'))
	{
		pos++;
		if ((mulLeft(expr, pos) == 0) && (sumRight(expr, pos) == 0))
			return 0;
	}
	//cout << "sR! \n";
	return 1;
}

int mulLeft(string expr, int &pos)
{
	if ((getId(expr, pos) == 0) && (mulRight(expr, pos) == 0))
			return 0;
	//cout << "mL! \n";
	return 1;
}

int mulRight(string expr, int &pos)
{
	if ((expr[pos] == '\0') || (expr[pos] == ')') || (expr[pos] == '\n') || (expr[pos] == '+') || (expr[pos] == '-'))
		return 0;
	if ((expr[pos] == '/') || (expr[pos] == '*'))
	{
		pos++;
		if ((getId(expr, pos) == 0) && (mulRight(expr, pos) == 0))
			return 0;
	}
	cout << "mR! \n";
	return 1;
}

int getId(string expr, int &pos)
{
	if (expr[pos] == '(') 
	{
		pos++;
		if (sumLeft(expr, pos) == 0) 
		{
			if (expr[pos] == ')') 
			{
				pos++;
				return 0;
			}
			return 1;
		}
		//cout << "gId! \n";
		return 1;
	}

	if  (inDouble(expr[pos]))
	{
		string substr = "";
		while (inDouble(expr[pos]))
		{
			substr += expr[pos];
			pos++;
		}
		if (isDouble(substr)) 
			return 0;
		//cout << "gId! \n";
		return 1;
	}
	//cout << "gId! \n";
	return 1;

}

int main()
{
	string str = "";
	cin >> str;
	cout << "The expression is ";
	if (checkExpr(str) != 0)
		cout << "in";
	cout << "correct\n";
	cin >> str;

}