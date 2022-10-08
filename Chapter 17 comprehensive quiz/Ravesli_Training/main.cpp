#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
public:
	Creature(const string& name, const char& symbol, const int& health, const int& damage, const int& gold)
		: m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
	{}

	void reduceHealth(int value);

	bool isDead();

	void addGold(int value);

	string& getName();
	char& getSymbol();
	int& getHealth();
	int& getDamage();
	int& getGold();
protected:
	string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
};

void Creature::reduceHealth(int value)
{
	m_health -= value;
}

bool Creature::isDead()
{
	return (m_health <= 0);
}

void Creature::addGold(int value)
{
	m_gold += value;
}

string& Creature::getName()
{
	return m_name;
}
char& Creature::getSymbol()
{
	return m_symbol;
}
int& Creature::getHealth()
{
	return m_health;
}
int& Creature::getDamage()
{
	return m_damage;
}
int& Creature::getGold()
{
	return m_gold;
}

class Player : public Creature
{
public:
	Player(string name)
		: Creature(name, '@', 10, 1, 0), m_level(1)
	{}

	void levelUp();

	bool hasWon();

	int& getLevel();

protected:
	int m_level;
};

void Player::levelUp()
{
	m_level++;
	m_damage++;
	cout << "You now on level " << getLevel() << endl;
}

bool Player::hasWon()
{
	return (m_level >= 20);
}

int& Player::getLevel()
{
	return m_level;
}

class Monster : public Creature
{
public:

	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	Monster(const Type type)
		: Creature(monsterData[type].name,
			monsterData[type].symbol,
			monsterData[type].health,
			monsterData[type].damage,
			monsterData[type].gold)
	{}

	struct MonsterData
	{
		string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];

	static Type getRandomMonster()
	{
		return static_cast<Type>(getRandomNumber(0, 2));
	}

private:
	
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};


/*
int main()
{
	Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold." << endl;

	string players_name;
	cout << "Enter your name: ";
	cin >> players_name ;
	Player this_player(players_name);
	cout << "Welcome, " << this_player.getName() << "!" << endl;
	cout << "You have " << this_player.getHealth() << " health and are carrying " << this_player.getGold() << " gold" << endl;

	return 0;
}
*/

/*
int main()
{
	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}
*/

/*
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
*/

void attackMonster(Player& player, Monster& monster)
{
	monster.reduceHealth(player.getDamage());
	cout << "You hit the " << monster.getName() << " for " << player.getDamage() << "health" << endl;
}

void attackPlayer(Player& player, Monster& monster)
{
	player.reduceHealth(monster.getDamage());
	cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " health" << endl;
}

void gameOver(Player& player)
{
	cout << "Game over! You had " << player.getLevel() << " level and " << player.getGold() << " gold." << endl;
}

void fightMonster(Player& player, Monster& monster)
{
	attackMonster(player, monster);
	while (true)
	{
		if (!monster.isDead())
		{
			attackPlayer(player, monster);
			if (player.isDead())
			{
				gameOver(player);
				break;
			}
			else
			{
				attackMonster(player, monster);
			}
		}
		else
		{
			player.addGold(monster.getGold());
			player.levelUp();
			cout << "You killed the " << monster.getName() << endl;

			break;
		}
	}

}

void Choice(Player& player, Monster& monster)
{
	cout << "(R)un or (F)ight: ";
	char choise;
	cin >> choise;
	cout << endl;
	if (choise == 'F')
	{
		fightMonster(player, monster);
	}
	else
	{
		bool luck;
		luck = getRandomNumber(0, 1);
		if (luck)
		{
			cout << "You succesfully fled" << endl;
		}
		else
		{
			fightMonster(player, monster);
		}
	}
}

int main()
{
	string players_name;
	cout << "Enter your name: ";
	cin >> players_name;
	Player this_player(players_name);
	cout << "Welcome, " << this_player.getName() << "!" << endl;
	cout << "You have " << this_player.getHealth() << " health and are carrying " << this_player.getGold() << " gold" << endl;

	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат

	while (true)
	{
		Monster this_monster = Monster::getRandomMonster();
		cout << "You have encountered a " << this_monster.getName() << " (" << this_monster.getSymbol() << ") " << endl;

		Choice(this_player, this_monster);

		if (this_player.hasWon())
		{
			cout << "You won! You have " << this_player.getGold() << endl;
			break;
		}
		if (this_player.isDead())
		{
			break;
		}
	}

	return 0;
}