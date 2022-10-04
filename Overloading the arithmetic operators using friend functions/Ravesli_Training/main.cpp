#include <iostream>

using namespace std;

class Fraction
{
public:
    Fraction(int numerator = 0, int denominator = 0)
        : m_numerator(numerator), m_denominator(denominator)
    {
        reduce();
    }

    void print()
    {
        cout << m_numerator << "/" << m_denominator << endl;
    }

    int nod(int a, int b) 
    {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);   
    }

    void reduce()
    {
        m_nod = nod(m_numerator, m_denominator);
        m_numerator /= m_nod;
        m_denominator /= m_nod;
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);

    friend Fraction operator*(const Fraction& fr, const int& num);

    friend Fraction operator*(const int& num, const Fraction& fr);


private:
	int m_numerator;
	int m_denominator;
    int m_nod;
};

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.m_numerator * rhs.m_numerator, lhs.m_denominator * rhs.m_denominator);
}

Fraction operator*(const Fraction& fr, const int& num)
{
    return Fraction(fr.m_numerator * num, fr.m_denominator);
}

Fraction operator*(const int& num, const Fraction& fr)
{
    return Fraction(fr.m_numerator * num, fr.m_denominator);
}

int main()
{
    Fraction f1(3, 4);
    f1.print();

    Fraction f2(2, 7);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 3;
    f4.print();

    Fraction f5 = 3 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}