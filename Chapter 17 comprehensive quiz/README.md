Задание №2
a) Создайте классы Apple и Banana, которые наследуют класс Fruit. У класса Fruit есть две переменные-члены: name и color.

Следующий код:

int main()
{
	Apple a("red");
	Banana b;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	
	return 0;
}
Должен выдавать следующий результат:

My apple is red.
My banana is yellow.

Ответ №2.a)

b) Добавьте новый класс GrannySmith, который наследует класс Apple.

Следующий код:

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}
Должен выдавать следующий результат:

My apple is red.
My banana is yellow.
My Granny Smith apple is green.

Ответ №2.b)


Задание №3
Самое любимое! Будем создавать простую игру, в которой вы будете сражаться с монстрами. Цель игры — собрать максимум золота, прежде чем вы умрете или достигнете 20 уровня.

Игра состоит из трех классов: Creature, Player и Monster. Player и Monster наследуют класс Creature.


a) Сначала создайте класс Creature со следующими членами:

   имя (std::string);

   символ (char);

   количество здоровья (int);

   количество урона, которое он наносит врагу во время атаки (int);

   количество золота, которое он имеет (int).

Создайте полный набор геттеров (по одному на каждую переменную-член класса). Добавьте еще три метода:

   void reduceHealth(int) — уменьшает здоровье Creature на указанное целочисленное значение;

   bool isDead() — возвращает true, если здоровье Creature равно 0 или меньше;

   void addGold(int) — добавляет золото Creature-у.

Следующий код:

#include <iostream>
#include <string>
 
int main()
{
	Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.";
 
	return 0;
}
Должен выдавать следующий результат:

The orc has 3 health and is carrying 15 gold.

Ответ №3.a)

b) Теперь нам нужно создать класс Player, который наследует Creature. Player имеет:

   переменную-член level, которая начинается с 1;

   имя (пользователь вводит с клавиатуры);

   символ @;

   10 очков здоровья;

   1 очко урона (для начала);

   0 золота.

Напишите метод levelUp(), который увеличивает уровень Player-а и его урон на 1. Также напишите геттер для члена level и метод hasWon(), который возвращает true, если Player достиг 20 уровня.

Допишите в функцию main() код, который спрашивает у пользователя его имя и выводит количество его здоровья и золота:


Enter your name: Anton
Welcome, Anton.
You have 10 health and are carrying 0 gold.

Ответ №3.b)

c) Следующий класс Monster также наследует Creature и у него нет собственных переменных-членов. Но есть перечисление Type, которое содержит 3 перечислителя, они обозначают типы монстров: DRAGON, ORC и SLIME (вам также нужен дополнительный перечислитель MAX_TYPES).

Ответ №3.c)

d) Каждый тип Монстра имеет свое имя, символ, определенное количество здоровья, урона и золота:

Type	Name	Symbol	Health	Damage	Gold
DRAGON	dragon	D	20	4	100
ORC	orc	o	4	2	25
SLIME	slime	s	1	1	10
Следующий шаг — реализация конструктора класса Monster, с помощью которого можно создавать монстров. Этот конструктор должен принимать перечисление Type в качестве параметра, а затем создавать монстра с соответствующими таблице характеристиками.

Это можно реализовать по-разному. Однако, поскольку все наши свойства типов монстров предопределены (не случайны), то мы будем использовать таблицу поиска. Таблица поиска — это массив, который содержит все предопределенные атрибуты (свойства) чего-либо. Мы можем использовать таблицу поиска для просмотра характеристики определенного типа монстра по мере необходимости.

Как это сделать? Нам нужны всего лишь две вещи. Во-первых, массив с отдельным элементом для каждого типа монстра. Во-вторых, этот элемент будет содержать структуру, в которой будут находиться все предопределенные значения атрибутов для конкретного типа монстра.


   Шаг №1: Создайте структуру MonsterData внутри класса Monster. Эта структура должна иметь следующие перечислители: name, symbol, health, damage и gold.

   Шаг №2: Объявите статический массив этой структуры с именем monsterData.

   Шаг №3: Добавьте код определения нашей таблицы поиска вне тела класса:

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};
Теперь мы можем искать любые значения, которые нам нужны! Например, чтобы узнать количество золота Dragon, мы можем использовать monsterData[DRAGON].gold.

Используйте эту таблицу поиска для реализации вашего конструктора:

Monster(Type type): Creature(monsterData[type].name, ...)
Следующий код:

#include <iostream>
#include <string>
 
int main()
{
	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}
Должен выдавать следующий результат:

A orc (o) was created.

Ответ №3.d)

e) Наконец, добавьте статический метод getRandomMonster() в класс Monster. Этот метод должен генерировать случайное число от 0 до MAX_TYPES-1 и возвращать (возврат по значению) определенный тип монстра (вам нужно использовать оператор static_cast для конвертации int в Type, чтобы передать его конструктору класса Monster).

Вы можете использовать следующий код для генерации случайного числа:

#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
 
// Генерируем рандомное число между min и max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
Следующий код:

#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
 
int main()
{
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат
 
	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}
 
	return 0;
}
Должен сгенерировать 10 рандомных монстров:

A slime (s) was created.
A orc (o) was created.
A slime (s) was created.
A slime (s) was created.
A orc (o) was created.
A orc (o) was created.
A dragon (D) was created.
A slime (s) was created.
A orc (o) was created.
A orc (o) was created.

Ответ №3.e)

f) Готово, теперь нам нужно разобраться с логикой выполнения нашей игры!

Суть:

   Игрок сталкивается с одним случайно выбранным монстром.

   С каждым монстром игрок может либо (R)un, либо (F)ight.


   Если игрок решает Run, то шансы на удачный побег составляют 50%.

   Если игроку удается сбежать, то ​​он благополучно переходит к следующему монстру (его здоровье/урон/золото при этом не уменьшается).

   Если игроку не удается сбежать, то монстр его атакует. Здоровье игрока уменьшается от урона монстра. Затем игрок выбирает свое следующее действие.

   Если игрок выбирает Fight, то он атакует монстра. Здоровье монстра уменьшается от урона игрока.

   Если монстр умирает, то игрок забирает всё золото монстра + увеличивает свой level и урон на 1.

   Если монстр не умирает, то он атакует игрока. Здоровье игрока уменьшается от урона монстра.

   Игра заканчивается, если игрок умер (проигрыш) или достиг 20 уровня (выигрыш).

   Если игрок умирает, то программа должна сообщить игроку, какой уровень у него был и сколько золота он имел.

   Если игрок побеждает, то игра должна сообщить игроку, что он выиграл и сколько у него есть золота.

Пример игры:

Enter your name: Anton
Welcome, Anton
You have encountered a orc (o).
(R)un or (F)ight: r
You successfully fled.
You have encountered a slime (s).
(R)un or (F)ight: f
You hit the slime for 1 damage.
You killed the slime.
You are now level 2.
You found 10 gold.
You have encountered a dragon (D).
(R)un or (F)ight: f
You hit the dragon for 2 damage.
The dragon hit you for 4 damage.
(R)un or (F)ight: f
You hit the dragon for 2 damage.
The dragon hit you for 4 damage.
(R)un or (F)ight: f
You hit the dragon for 2 damage.
The dragon hit you for 4 damage.
You died at level 2 and with 10 gold.
Too bad you can't take it with you!

Подсказка: У вас должны быть следующие 4 функции:

   Функция создания Игрока и основной игровой цикл (в функции main()).

   Функция fightMonster(), которая обрабатывает бой между Игроком и Монстром, и спрашивает у игрока, что он хочет сделать: Run или Fight.

   Функция attackMonster(), которая обрабатывает атаку монстра игроком, включая увеличение уровня игрока.

   Функция attackPlayer(), которая обрабатывает атаку игрока монстром.

Ответ №3.f)
