Наш пример с Animal/Cat/Dog не работает так, как мы хотим, потому что ссылка/указатель класса Animal не может получить доступ к методам speak() дочерних классов. Один из способов обойти эту проблему — сделать так, чтобы данные, возвращаемые методом speak(), стали доступными в виде родительской части класса Animal (так же, как name класса Animal доступен через член m_name).

Обновите классы Animal, Cat и Dog в коде, приведенном выше, добавив новый член m_speak в класс Animal. Инициализируйте его соответствующим образом. Следующая программа должна работать корректно:

#include <iostream>
 
int main()
{
    Cat matros("Matros"), ivan("Ivan"), martun("Martun");
    Dog barsik("Barsik"), tolik("Tolik"), tyzik("Tyzik");
 
    // Создаем массив указателей на наши объекты Cat и Dog
    Animal *animals[] = { &matros, &ivan, &martun, &barsik, &tolik, &tyzik};
    for (int iii=0; iii < 6; iii++)
        std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';
 
    return 0;
}
