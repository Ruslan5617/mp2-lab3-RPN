#include <iostream>
#include "ReversePolishNotation.h"
#include <string>
int main()
{
	setlocale(LC_ALL, "Russian");
	string ex;
	while (true) {
		cout << "������� ������ " << endl;
		cin >> ex;
		ReversePolishNotation rpnStr(ex);
		rpnStr.Parse();
		cout << "�������� �������� ������ ������� " << endl;
		cout << rpnStr.getRpnStr() << endl;
		rpnStr.calculate();
		cout << "��������� " << endl;
		cout << rpnStr.getResult() << endl;
	}
	system("pause");
}