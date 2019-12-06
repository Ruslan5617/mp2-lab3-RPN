#include <string>
using namespace std;
class ReversePolishNotation
{
	std::string Str;
	std::string rpnStr;
	int result;

public:
	bool checkBracket();            // ��������� ��� �� ������ ����� ����
	bool Operation(char in);        // �������� ��������
	bool Digit(char in);            // �������� �� �����
	bool Unary(int i);              // �������� �� ���������
	bool checkDoubleOperation();    // �������� ������������ ������
	int priority(char in);          // ����������� ����������� ��������
	void Parse();                   // ����������� ��������� ������ � �������� �������� ������
	void calculate();               // ���������� ����������
	string getRpnStr(); 
	int getResult();

	ReversePolishNotation(std::string str);
	~ReversePolishNotation();
};

