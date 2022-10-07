#include <iostream>
#include <ostream>

using namespace std;

class Fruit
{
public:
	Fruit(string name, string color)
		: m_name(name), m_color(color)
	{

	}

	string getName() const;
	string getColor() const;

	friend ostream& operator<<(ostream& os, const Fruit& obj);

private:
	string m_name;
	string m_color;
};

class Apple : public Fruit
{
public:
	Apple(const string& name, const string& color, const double& fiber)
		: Fruit(name, color), m_fiber(fiber)
	{}

	double getFiber() const;

	friend ostream& operator<<(ostream& os, Apple& obj);
private:
	double m_fiber;
};

class Banana : public Fruit
{
public:
	Banana(const string& name, const string& color)
		: Fruit(name, color)
	{

	}

	friend ostream& operator<<(ostream& os, const Banana& obj);

private:

};

string Fruit::getName() const
{
	return m_name;
}

string Fruit::getColor() const
{
	return m_color;
}

double Apple::getFiber() const
{
	return m_fiber;
}


ostream& operator<<(ostream& os, const Fruit& obj)
{
	os << obj.m_name << ", " << obj.m_color;
	return os;
}

ostream& operator<<(ostream& os, const Banana& obj)
{
	os << "Banana(" << obj.getName() << ", " << obj.getColor() << ")" << endl;
		return os;
}

ostream& operator<<(ostream& os, const Apple& obj)
{
	os << "Apple(" << obj.getName() << ", " << obj.getColor() << ", " << obj.getFiber() << ")" << endl;
	return os;
}

int main()
{
	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

	return 0;
}