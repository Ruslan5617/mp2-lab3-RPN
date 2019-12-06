#include <string>
using namespace std;
class ReversePolishNotation
{
	std::string Str;
	std::string rpnStr;
	int result;

public:
	bool checkBracket();            // Проверяем все ли скобки имеют пару
	bool Operation(char in);        // Проверка операции
	bool Digit(char in);            // Проверка на число
	bool Unary(int i);              // Проверка на унарность
	bool checkDoubleOperation();    // Проверка корректности записи
	int priority(char in);          // Расстановка приоритетов операций
	void Parse();                   // Превращение введенной строки в обратную польскую запись
	void calculate();               // Вычисление результата
	string getRpnStr(); 
	int getResult();

	ReversePolishNotation(std::string str);
	~ReversePolishNotation();
};

