#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction
{
public:
	Fraction(const int& s_numerator, const int& s_denominator)
		: m_numerator(s_numerator), m_denominator(s_denominator)
	{
		if (s_denominator == 0)
		{
			throw runtime_error("Denominator is 0, it's not right");
		}
	}


private:
	int m_numerator;
	int m_denominator;
};

int main()
{
	int numerator, denominator;
	cout << "Enter the numerator: ";
	cin >> numerator;
	cout << "Enter the denominator: ";
	cin >> denominator;

	try
	{
		Fraction fraction1(numerator, denominator);
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "The end" << endl;

	return 0;
}