Используя вышеприведенный класс ArrayInt, реализуйте перегрузку оператора присваивания, который будет принимать список инициализации. Следующий код:

int main()
{
	ArrayInt array { 7, 6, 5, 4, 3, 2, 1 }; // список инициализации
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';
 
	std::cout << '\n';
 
	array = { 1, 4, 9, 12, 15, 17, 19, 21 };
 
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';
 
	return 0;
}
Должен выдавать следующий результат:

7 6 5 4 3 2 1
1 4 9 12 15 17 19 21
