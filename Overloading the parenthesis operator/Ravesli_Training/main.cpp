#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:
	MyString(string str)
		: m_str(str)
	{}

	string operator()(int number, int count);

private:
	string m_str;
};

string MyString::operator()(int number, int count)
{
	string tmp;
	for (int i = 0; i < count; i++)
	{
		tmp += m_str[number + i];
	}
	return tmp;
}

int main()
{
	MyString string("Hello, world!");
	std::cout << string(7, 6); // начинаем с 7-го символа (индекса) и возвращаем следующие 6 символов

	return 0;
}