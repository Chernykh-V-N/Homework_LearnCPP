#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual ostream& print(ostream& os) = 0;

	friend ostream& operator<<(ostream& os, Shape& obj);

	virtual ~Shape()
	{}
};

ostream& operator<<(ostream& os, Shape& obj)
{
	return obj.print(os);
}

struct Point
{
	Point(double p_x, double p_y, double p_z)
		: x(p_x), y(p_y), z(p_z)
	{}

	Point()
		: Point(0, 0, 0)
	{}

	Point(int p_x, int p_y, int p_z)
		: Point(static_cast<double>(p_x), static_cast<double>(p_y), static_cast<double>(p_z))
	{}

	double x;
	double y;
	double z;
};

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "Point(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
	return os;
}

class Triangle : public Shape
{
public:
	Triangle(const Point& p_a, const Point& p_b, const Point& p_c)
		:m_a(p_a), m_b(p_b), m_c(p_c)
	{}

	Triangle()
		: Triangle(Point(0, 0, 0), Point(0, 0, 0), Point(0, 0, 0))
	{}

	ostream& print(ostream& os) override;


private:
	Point m_a;
	Point m_b;
	Point m_c;
};

ostream& Triangle::print(ostream& os)
{
	os << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")" << endl;
	return os;
}

class Circle : public Shape
{
public:
	Circle(const Point& p_center, const int& p_radius)
		: m_center(p_center), m_radius(p_radius)
	{}

	ostream& print(ostream& os) override;

	int& getRadius();

private:
	Point m_center;
	int m_radius;
};

ostream& Circle::print(ostream& os)
{
	os << "Circle(" << m_center << ", radius " << m_radius << ")" << endl;
	return os;
}

int& Circle::getRadius()
{
	return m_radius;
}

int getLargestRadius(const vector<Shape*> v)
{
	int tmp = 0;

	for (auto const& item : v)
	{
		if (Circle* c = dynamic_cast<Circle*>(item))
		{
			if (c->getRadius() > tmp)
			{
				tmp = c->getRadius();
			}
		}
	}

	return tmp;
}

/*
int main()
{
	Circle c(Point(1, 2, 3), 7);
	std::cout << c << '\n';

	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	std::cout << t << '\n';

	return 0;
}
*/

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	// Вывод элементов вектора v здесь
	for (auto i : v)
	{
		cout << *i << ", ";
	}


	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

	// Удаление элементов вектора v здесь
	//delete v;

	for (auto& item : v)
	{
		delete item;
	}
}