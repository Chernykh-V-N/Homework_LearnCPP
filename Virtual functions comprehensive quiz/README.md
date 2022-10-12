Задание №1
Каждая из следующих программ имеет какую-то ошибку. Ваша задача состоит в том, чтобы найти эту ошибку визуально (не запуская код). Предполагаемый вывод каждой программы:

Child

a)

#include <iostream>
 
class Parent
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	const char* getName() const { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	const char* getName() const { return "Child"; }
};
 
int main()
{
	Child ch(7);
	Parent &p = ch;
	std::cout << p.getName();
 
	return 0;
}
Ответ №1.a)

b)

#include <iostream>
 
class Parent
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	virtual const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	virtual const char* getName() const { return "Child"; }
};
 
int main()
{
	Child ch(7);
	Parent &p = ch;
	std::cout << p.getName();
 
	return 0;
}
Ответ №1.b)

c)

#include <iostream>
 
class Parent
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	virtual const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	virtual const char* getName() override { return "Child"; }
};
 
int main()
{
	Child ch(7);
	Parent p = ch;
	std::cout << p.getName();
 
	return 0;
}
Ответ №1.c)

d)

#include <iostream>
 
class Parent final
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	virtual const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	virtual const char* getName() override { return "Child"; }
};
 
int main()
{
	Child ch(7);
	Parent &p = ch;
	std::cout << p.getName();
 
	return 0;
}
Ответ №1.d)

e)

#include <iostream>
 
class Parent
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	virtual const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	virtual const char* getName() = 0;
};
 
const char* Child::getName()
{
    return "Child";
}
 
int main()
{
	Child ch(7);
	Parent &p = ch;
	std::cout << p.getName();
 
	return 0;
}
Ответ №1.e)

f)

#include <iostream>
 
class Parent
{
protected:
	int m_value;
 
public:
	Parent(int value)
		: m_value(value)
	{
	}
 
	virtual const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
	Child(int value)
		: Parent(value)
	{
	}
 
	virtual const char* getName() { return "Child"; }
};
 
int main()
{
	Child *ch = new Child(7);
	Parent *p = ch;
	std::cout << p->getName();
	delete p;
 
	return 0;
}
Ответ №1.f)


Задание №2
a) Создайте абстрактный класс Shape. Этот класс должен иметь три метода:

   чистую виртуальную функцию print() с параметром типа std::ostream;

   перегрузку operator<<;

   пустой виртуальный деструктор.

Ответ №2.a)

b) Создайте два класса: Triangle и Circle, которые наследуют класс Shape.

   Triangle должен иметь 3 точки в качестве переменных-членов.


   Circle должен иметь одну центральную точку и целочисленный радиус в качестве переменных-членов.

Перегрузите функцию print(), чтобы следующий код:

int main()
{
    Circle c(Point(1, 2, 3), 7);
    std::cout << c << '\n';
 
    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    std::cout << t << '\n';
 
    return 0;
}
Выдавал следующий результат:

Circle(Point(1, 2, 3), radius 7)
Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9))

Вот класс Point, который вы можете использовать:

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
 
public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{
 
	}
 
	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};
Ответ №2.b)

c) Используя код из предыдущих заданий (классы Point, Shape, Circle и Triangle) завершите следующую программу:

#include <iostream> 
#include <vector>
 
int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
 
	// Вывод элементов вектора v здесь
 
       	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию
 
	// Удаление элементов вектора v здесь
}
Подсказка: Вам нужно добавить метод getRadius() в Circle и выполнить понижающее приведение Shape* в Circle*, чтобы получить доступ к этому методу.
