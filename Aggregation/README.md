Задание №2
Обновите вышеприведенный пример с Работником/Отделом так, чтобы Отдел мог состоять из нескольких Работников. Следующий код:

#include <iostream>
 
int main()
{
    // Создаем Работников вне области видимости класса Department
    Worker *w1 = new Worker("Anton");
    Worker *w2 = new Worker("Ivan");
    Worker *w3 = new Worker("Max");
 
    {
        // Создаем Отдел и передаем Работников в качестве параметров конструктора
        Department department; // содаем пустой Отдел
        department.add(w1);
        department.add(w2);
        department.add(w3);
 
        std::cout << department;
 
    } // department выходит из области видимости и уничтожается здесь
 
    std::cout << w1->getName() << " still exists!\n";
    std::cout << w2->getName() << " still exists!\n";
    std::cout << w3->getName() << " still exists!\n";
 
    delete w1;
    delete w2;
    delete w3;
 
    return 0;
}
Должен выдавать следующий результат:

Department: Anton Ivan Max
Anton still exists!
Ivan still exists!
Max still exists!

Подсказки:

   Используйте std::vector для хранения Работников.

   Используйте std::vector::push_back() для добавления Работника.

   Используйте std::vector::size() для получения длины std::vector.
