#include <iostream>
#include <string>
#include <ostream>
#include <vector>

using namespace std;

class Worker
{
private:
    std::string m_name;

public:
    Worker(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
};

class Department
{
private:
    vector<Worker*> m_worker;

public:
    /*
    Department(Worker* worker = nullptr)
        : m_worker(worker)
    {
    }
    */

    void add(Worker* worker)
    {
        m_worker.push_back(worker);
    }

    friend ostream& operator<<(ostream& os, const Department& obj)
    {
        for (int count = 0; count < obj.m_worker.size(); count++)
        {
            os << obj.m_worker[count]->getName() << " ";
        }

        /*
        for (auto item : obj.m_worker)
        {
            os << item.getName() << " ";
        }
        */
        os << endl;
        return os;
    }
};

int main()
{
    // ??????? ?????????? ??? ??????? ????????? ?????? Department
    Worker* w1 = new Worker("Anton");
    Worker* w2 = new Worker("Ivan");
    Worker* w3 = new Worker("Max");

    {
        // ??????? ????? ? ???????? ?????????? ? ???????? ?????????? ????????????
        Department department; // ?????? ?????? ?????
        department.add(w1);
        department.add(w2);
        department.add(w3);

        std::cout << department;

    } // department ??????? ?? ??????? ????????? ? ???????????? ?????

    std::cout << w1->getName() << " still exists!\n";
    std::cout << w2->getName() << " still exists!\n";
    std::cout << w3->getName() << " still exists!\n";

    delete w1;
    delete w2;
    delete w3;

    return 0;
}