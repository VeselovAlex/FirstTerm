#include <iostream>
#include <string>
#include "getdouble.h"

using namespace std;

int type (char input)
{
	if ((input >= '0') && (input <= '9'))
		return 1;
	if (input == '-')
		return 2;
	if (input == '.')
		return 3;
	if (input == 'e' || input == 'E')
		return 4;
	if ((input == '\n') || (input == '\0'))
		return 5;
	if (input == ' ' || input == '\t')
		return 0;
	return -1;
}

double getDouble (string innumber)
{
	enum State
	{
		delay,
		trunc,
		frac,
		deg,
		exit,
		error = -1,
	};
	
	enum Type
	{
		space,
		number,
		sign,
		point,
		exp,
		end,
		invalid = -1,
	};

	int statement = delay;
	int input = space;
	int pos = -1;

	int numsign = 1;
	int expsign = 1;
	int expDeg = 0;
	double fracDeg = 1;
	double result = 0;

	while (true)
	{
		switch (statement)
		{
		case delay:
			{
				
				pos++;
				input = type(innumber[pos]);
				switch (input)
				{
				case number:
					{
						statement = trunc;
						break;
					}
				case sign:
					{
						numsign = -1;
						pos++;
						if (type(innumber[pos]) == point)
							statement = error;
						else
							statement = trunc;
						break;
					}
				case point:
					{
						pos++;
						statement = frac;
						break;
					}
				case exp:
					{
						statement = error;
						break;
					}
				case end:
					{
						statement = exit;
						break;
					}
				case space:
					{
						statement = delay;
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
		case trunc:
			{
				
				int buffer = (innumber[pos] - '0');
				result = result * 10 + buffer;
				pos++;
				input = type(innumber[pos]);
				switch (input)
				{
				case number:
					{
						statement = trunc;
						break;
					}
				case sign:
					{
						statement = error;
						break;
					}
				case point:
					{
						statement = frac;
						pos++;
						break;
					}
				case exp:
					{
						statement = deg;
						break;
					}
				case end:
					{
						statement = exit;
						break;
					}
				case space:
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
		case frac:
			{
			
				int buffer = (innumber[pos] - '0');
				fracDeg = fracDeg / 10;
				result = result + (buffer * fracDeg);
				pos++;
				input = type(innumber[pos]);
				switch (input)
				{
				case number:
					{
						statement = frac;
						break;
					}
				case sign:
					{
						statement = error;
						break;
					}
				case point:
					{
						statement = error;
						break;
					}
				case exp:
					{
						statement = deg;
						break;
					}
				case end:
					{
						statement = exit;
						break;
					}
				case space:
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
		case deg:
			{
				
				pos++;
				input = type(innumber[pos]);
				switch (input)
				{
				case number:
					{
						int buffer = (innumber[pos] -'0');
						expDeg = expDeg * 10 + buffer;
						statement = deg;
						break;
					}
				case sign:
					{
						expsign = -1;
						statement = deg;
						break;
					}
				case point:
					{
						statement = error;
						break;
					}
				case exp:
					{
						statement = error;
						break;
					}
				case end:
					{
						statement = exit;
						break;
					}
				case space:
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
		case exit:
			{
			
				result = result * numsign;
				for (int i = 0; i < expDeg; i++)
					if (expsign == -1)
						result = result / 10;
					else
						result = result * 10;
				return result;
				break;
			}
		case error:
			{
				cout << "(X) invalid number.\n";
				return 0;
				break;
			}

		default:
			break;
		}
	}

}