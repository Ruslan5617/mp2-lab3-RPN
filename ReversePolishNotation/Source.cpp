#include <iostream>
#include "ReversePolishNotation.h"
#include <string>
int main()
{
	setlocale(LC_ALL, "Russian");
	string ex;
	while (true) {
		cout << "Введите пример " << endl;
		cin >> ex;
		ReversePolishNotation rpnStr(ex);
		rpnStr.Parse();
		cout << "Обратная польская запись примера " << endl;
		cout << rpnStr.getRpnStr() << endl;
		rpnStr.calculate();
		cout << "Результат " << endl;
		cout << rpnStr.getResult() << endl;
	}
	system("pause");
}