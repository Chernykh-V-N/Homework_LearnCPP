Задание №1
Контейнер map — это класс, в котором все элементы хранятся в виде пары ключ-значение. Ключ должен быть уникальным и использоваться для доступа к связанной паре. В этом задании вам нужно будет написать программу, которая позволит присваивать оценки ученикам, указывая только имя ученика. Для этого используйте контейнер map: имя ученика — ключ, оценка (тип char) — значение.

a) Сначала напишите структуру StudentGrade с двумя элементами: имя студента (std::string) и оценка (char).

Ответ №1.a)

b) Добавьте класс GradeMap, который содержит std::vector типа StudentGrade с именем m_map. Добавьте пустой конструктор по умолчанию.

Ответ №1.b)

c) Реализуйте перегрузку оператора [] для этого класса. Функция перегрузки должна принимать параметр std::string (имя ученика) и возвращать ссылку на его оценку. В функции перегрузки сначала выполните поиск указанного имени ученика в векторе (используйте цикл foreach). Если ученик нашелся, то возвращайте ссылку на его оценку, и всё — готово!

В противном случае, используйте функцию std::vector::push_back() для добавления StudentGrade нового ученика. Когда вы это сделаете, std::vector добавит себе копию нового StudentGrade (при необходимости изменив размер). Наконец, вам нужно будет возвратить ссылку на оценку студента, которого вы только что добавили в std::vector — для этого используйте std::vector::back().


Следующая программа должна скомпилироваться без ошибок:

#include <iostream>
 
int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';
 
	return 0;
}
Ответ №1.c)

Задание №2
Класс GradeMap и программа, которую мы написали, неэффективна по нескольким причинам. Опишите один способ улучшения класса GradeMap.

Ответ №2

Задание №3
Почему следующая программа не работает должным образом?

#include <iostream>
 
int main()
{
	GradeMap grades;
 
	char& gradeJohn = grades["John"]; // выполняется push_back
	gradeJohn = 'A';
 
	char& gradeMartin = grades["Martin"]; // выполняется push_back
	gradeMartin = 'B';
 
	std::cout << "John has a grade of " << gradeJohn << '\n';
	std::cout << "Martin has a grade of " << gradeMartin << '\n';
 
	return 0;
}
