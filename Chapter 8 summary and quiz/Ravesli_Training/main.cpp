#include <iostream>
#include<ostream>
#include <istream>
#include <cstdint>
#include <cassert>
#include <cmath>

using namespace std;

class Average
{
public:
	Average()
	{}

	Average& operator+=(int rhs);
	friend ostream& operator<<(ostream& os, Average& avg);
private:
	int32_t m_sum = 0;
	int8_t m_number = 0;
};

Average& Average::operator+=(int rhs)
{
	m_sum += rhs;
	m_number++;

	return *this;
}

ostream& operator<<(ostream& os, Average& avg)
{
	os << (avg.m_sum / avg.m_number);
	return os;
}

/*
int main()
{
	Average avg;

	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5

	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7

	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
*/

class IntArray
{
public:
	IntArray(int size)
		: m_size(size)
	{
		m_member = new int[size];
	}

	IntArray(const IntArray& arr)
	{
		m_size = arr.m_size;

		if (arr.m_member)
		{
			m_member = new int[arr.m_size];

			for (int count = 0; count < arr.m_size; count++)
			{
				m_member[count] = arr.m_member[count];
			}
		}
		else
		{
			m_member = nullptr;
		}
	}

	int& operator[](const int index);
	friend ostream& operator<<(ostream& os, const IntArray& obj);
	IntArray& operator=(IntArray& obj);

	~IntArray()
	{
		delete m_member;
	}
private:
	int m_size;
	int* m_member = nullptr;
};

IntArray& IntArray::operator=(IntArray& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete m_member;

	m_member = new int[obj.m_size];

	m_size = obj.m_size;

	if (obj.m_member)
	{
		for (int count = 0; count < obj.m_size; count++)
		{
			m_member[count] = obj.m_member[count];
		}
	}
	else
	{
		m_member = nullptr;
	}

	return *this;
}


int& IntArray::operator[](const int index)
{
	assert(index >= 0);
	assert(index < m_size);
	return m_member[index];
}

ostream& operator<<(ostream& os, const IntArray& obj)
{
	for (int count = 0; count < obj.m_size; count++)
	{
		os << obj.m_member[count] << " ";
	}
	return os;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;

	return a;
}

/*
int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
*/

class FixedPoint
{
public:
	FixedPoint(const int& left, const int& right)
		: m_left(left), m_right(right)
	{
		if (left < 0 || right < 0)
		{
			if (left < 0)
			{
				m_left = -left;
			}
			if (right < 0)
			{
				m_right = -right;
			}
		}
		if (m_right > 99 || m_right < -99)
		{
			double tmp(m_right / 100);
			m_left += tmp;
			m_right -= (tmp * 100);
		}
	}

	FixedPoint(const double& double_number)
	{
		m_left = double_number;
		m_right = round((double_number - m_left) * 100);
	}

	//friend ostream& operator<<(ostream& os, FixedPoint& fp);
	operator double()
	{
		double tmp = m_left + (static_cast<double>(m_right) / 100);
		return tmp;
	}

	friend ostream& operator<<(ostream& os, FixedPoint& fp)
	{
		os << static_cast<double>(fp);
		return os;
	}

	//friend bool operator==(const FixedPoint& lhs, const FixedPoint& rhs);
	FixedPoint operator-();
	friend FixedPoint operator+(FixedPoint& lhs, FixedPoint& rhs)
	{
		FixedPoint tmp(static_cast<double>(lhs) + static_cast<double>(rhs));
		return tmp;
	}



private:
	int16_t m_left;
	int8_t m_right;
};



istream& operator>>(istream& is, FixedPoint& obj)
{
	double tmp;
	is >> tmp;
	obj = FixedPoint(tmp);
	return is;
}

/*
bool operator==(const FixedPoint& lhs, const FixedPoint& rhs)
{
	return (lhs.m_left == rhs.m_left && lhs.m_right == rhs.m_right);
}
*/

FixedPoint FixedPoint::operator-()
{
	return FixedPoint(-m_left, -m_right);
}

/*
FixedPoint operator+(FixedPoint& lhs, FixedPoint& rhs)
{
	return FixedPoint(static_cast<double>(lhs) + static_cast<double>(rhs));
}
*/


/*
int main()
{
	
	FixedPoint a(37, 58);
	std::cout << a << '\n';

	FixedPoint b(-3, 9);
	std::cout << b << '\n';

	FixedPoint c(4, -7);
	std::cout << c << '\n';

	FixedPoint d(-5, -7);
	std::cout << d << '\n';

	FixedPoint e(0, -3);
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';
	
	return 0;
}
*/
	/*
	int main()
	{
	FixedPoint a(0.03);
	std::cout << a << '\n';

	FixedPoint b(-0.03);
	std::cout << b << '\n';

	FixedPoint c(4.01); // сохранится, как 4.0099999..., поэтому нам нужно это всё округлить
	std::cout << c << '\n';

	FixedPoint d(-4.01); // сохранится, как -4.0099999..., поэтому нам нужно это всё округлить
	std::cout << d << '\n';

	return 0;
	}
	*/

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}

int main()
{
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';
	
	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}
