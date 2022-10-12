#include <iostream>
#include <memory> // ��� std::shared_ptr

class Item
{
public:
	std::weak_ptr<Item> m_ptr; // ���������� ������

	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
};

int main()
{
	auto ptr1 = std::make_shared<Item>();

	ptr1->m_ptr = ptr1; // m_ptr ������ �������� ���������� Item-�, ������ �������� �� �������� ���

	return 0;
}