Реализуем наш пример с Фруктом, о котором мы говорили на уроке №153. Создайте родительский класс Fruit, который имеет два закрытых члена: name (std::string) и color (std::string). Создайте класс Apple, который наследует свойства Fruit. У Apple должен быть дополнительный закрытый член: fiber (тип double). Создайте класс Banana, который также наследует класс Fruit. Banana не имеет дополнительных членов.

Следующий код:

int main()
{
	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}
Должен выдавать следующий результат:

Apple(Red delicious, red, 7.3)
Banana(Cavendish, yellow)

Подсказка: Поскольку a и b являются const, то убедитесь, что ваши параметры и функции соответствуют const.

Ответ
