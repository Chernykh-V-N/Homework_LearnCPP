#include <iostream>

using namespace std;


template<class T>
class Pair1
{
public:
	Pair1(const T& s_first, const T& s_second)
		: m_first(s_first), m_second(s_second)
	{}

	Pair1()
		: Pair1(0, 0)
	{}
	
	T& first()
	{
		return m_first;
	}
	const T& first() const
	{
		return m_first;
	}

	T& second()
	{
		return m_second;
	}
	const T& second() const
	{
		return m_second;
	}

private:
	T m_first;
	T m_second;
};

/*
int main()
{
	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
*/

template<class T1, class T2>
class Pair
{
public:
	Pair(const T1& s_first, const T2& s_second)
		: m_first(s_first), m_second(s_second)
	{}

	Pair()
		: Pair(0, 0)
	{}

	T1& first()
	{
		return m_first;
	}
	const T1& first() const
	{
		return m_first;
	}

	T2& second()
	{
		return m_second;
	}
	const T2& second() const
	{
		return m_second;
	}

private:
	T1 m_first;
	T2 m_second;
};

/*
int main()
{
	Pair<int, double> p1(6, 7.8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
*/

template<typename T2>
class StringValuePair : public Pair<string, T2>
{
public:
	StringValuePair(const string& s_first, const T2& s_second)
		: Pair<string, T2>(s_first, s_second)
	{}

	StringValuePair()
		: StringValuePair("", 0)
	{}


};

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}