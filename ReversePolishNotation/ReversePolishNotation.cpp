#include "ReversePolishNotation.h"
#include <stack>

using namespace std;


bool ReversePolishNotation::checkBracket()
{
	int openBracket = 0;
	int closeBracket = 0;

	for (int i = 0; i < Str.size(); i++)
	{
		if (Str[i] == '(') openBracket++;
		if (Str[i] == ')') closeBracket++;
		
	}

	if (openBracket == closeBracket) return true;
	else
		return false;
}

bool ReversePolishNotation::Operation(char in)
{
	if (in == '(' || in == ')' || in == '+' || in == '*' || in == '-' || in == '/' || in == '$' || in =='~' || in == '^') return true;
	else
		return false;
}

bool ReversePolishNotation::Digit(char in)
{
	if (isdigit(static_cast<unsigned char>(in)))
		return true;
	return false;
}

bool ReversePolishNotation::Unary(int i)
{
	if (i == 0) return true;
	if (Str[i - 1] == '(') return true;
	if (Str[i - 1] == '+') return true;
	if (Str[i - 1] == '-') return true;
	return false;
}

bool ReversePolishNotation::checkDoubleOperation()
{
	for (int i = 0; i < Str.length() - 1; i++)
	{
		switch (Str[i])
		{
		case('+'): if (Str[i + 1] == '+' || Str[i + 1] == '-' || Str[i + 1] == '*' || Str[i + 1] == '/')
			return false;

		case('-'): if (Str[i + 1] == '+' || Str[i + 1] == '-' || Str[i + 1] == '*' || Str[i + 1] == '/')
			return false;

		}


	}
	return true;
}

int ReversePolishNotation::priority(char in)
{
	switch (in) {
	case('('):
		return 0;

	case(')'):
		return 1;

	case('+'):
		return 2;

	case('-'):
		return 2;

	case('/'):
		return 3;

	case('*'):
		return 3;

	case('$'):
		return 3;

	case('~'):
		return 3;

	case('^'):
		return 4;
	}
}

void ReversePolishNotation::Parse()
{
	bool unarPlus = false;
	bool unarMinus = false;
	stack<char> operations;
	if (!checkBracket() || !checkDoubleOperation())
		throw - 1;
	for (int i = 0; i < Str.length(); i++)
	{
		if (Operation(Str[i]))
		{
			if (operations.empty())
			{
				if (Unary(i) && Str[i] == '-') { operations.push('~'); unarMinus = true; }
				else
					if (Unary(i) && Str[i] == '+') { operations.push('$'); unarPlus = true; }
					else
						operations.push(Str[i]);
			}
			else
			{
				switch (priority(Str[i]))
				{
				case(0):
					operations.push(Str[i]);
					break;

				case(1):
					while (operations.top() != '(')
					{
						rpnStr.append(1, operations.top());
						rpnStr.append(1, ' ');
						operations.pop();

						if (operations.empty()) break;
					}
					if (operations.top() == '(') operations.pop();
					break;

				case(2):
					if (Unary(i))
					{
						while (priority(operations.top()) >= priority(Str[i]))
						{
							rpnStr.append(1, operations.top());
							rpnStr.append(1, ' ');
							operations.pop();
							if (operations.empty()) break;
						}
						if (Str[i] == '-') { operations.push('~'); unarMinus = true; }
						else
							if (Str[i] == '+') { operations.push('$'); unarPlus = true; } break;

					}
					while (priority(operations.top()) >= priority(Str[i]))
					{
						rpnStr.append(1, operations.top());
						rpnStr.append(1, ' ');
						operations.pop();
						if (operations.empty()) break;
					}

					operations.push(Str[i]);
					break;

				case(3):
				{
					while (priority(operations.top()) >= priority(Str[i]))
					{
						rpnStr.append(1, operations.top());
						rpnStr.append(1, ' ');
						operations.pop();
						if (operations.empty()) break;
					}

					operations.push(Str[i]);
					break;
				}
				case(4):
				{
					while (priority(operations.top()) >= priority(Str[i]))
					{
						rpnStr.append(1, operations.top());
						rpnStr.append(1, ' ');
						operations.pop();
						if (operations.empty()) break;
					}

					operations.push(Str[i]);
					break;
				}
				default:
					break;
				}
			}
		}

		

		if (Digit(Str[i]))
		{
			rpnStr.append(1, Str[i]);
			if (!Digit(Str[i + 1])) rpnStr.append(1, ' ');
		}
	}
		while (!operations.empty())
		{
			if (operations.top() != '(')
			{
				rpnStr.append(1, operations.top());
				rpnStr.append(1, ' ');
			}
			operations.pop();
		}
	

}

string ReversePolishNotation::getRpnStr()
{
	return rpnStr;
}

int ReversePolishNotation::getResult()
{
	return result;
}

ReversePolishNotation::ReversePolishNotation(std::string str)
{
	Str = str;
}

ReversePolishNotation::~ReversePolishNotation()
{
}

void ReversePolishNotation::calculate()
{
	stack<string> operations;
	string str1;
	int tmp = 0;
	int x, y;
	bool flag = true;
	for (int i = 0; i < rpnStr.length(); i++)
	{
		if (Digit(rpnStr[i]))
		{
			str1.clear();
			while (Digit(rpnStr[i]))
			{
				str1 += rpnStr[i];
				i++;
			}
			operations.push(str1);
			i--;
		}
		if (Operation(rpnStr[i]))
		{
			if (rpnStr[i] == '$' || rpnStr[i] == '~')
			{
				x = stoi(operations.top());
				operations.pop();
			}
			else
			{
				y = stoi(operations.top());
				operations.pop();
				x = stoi(operations.top());
				operations.pop();
			}
			switch (rpnStr[i])
			{
			case('+'):

				tmp = x + y;
				operations.push(to_string(tmp));
				break;

			case('-'):

				tmp = x - y;
				operations.push(to_string(tmp));
				break;

			case('/'):

				tmp = x / y;
				operations.push(to_string(tmp));
				break;

			case('*'):
				tmp = x * y;
				operations.push(to_string(tmp));
				break;

			case('$'):

				tmp = abs(x);
				operations.push(to_string(tmp));
				break;

			case('~'):

				tmp = -x;
				operations.push(to_string(tmp));
				break;

			case('^'):

				tmp = pow(x, y);
				operations.push(to_string(tmp));
				break;
			}
		}
	}
		result = stoi(operations.top());
	
}







