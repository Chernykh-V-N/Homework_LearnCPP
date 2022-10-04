#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct StudentGrade
{
	string m_studentName;
	char m_studentGrade;
};

bool operator<(const StudentGrade& lhs, const StudentGrade& rhs);

class GradeMap
{
public:

	GradeMap()
	{
		sort(m_map.begin(), m_map.end());
	}

	char& operator[](string name);

private:

	vector<StudentGrade> m_map;
};

bool operator<(const StudentGrade& lhs, const StudentGrade& rhs)
{
	if (lhs.m_studentName < rhs.m_studentName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char& GradeMap::operator[](string name)
{
	/*
	for (auto &item : m_map)
	{
		if (item.m_studentName == name)
		{
			return item.m_studentGrade;
		}
	}
	*/

	bool flag = false;
	int min = 0;
	int max = m_map.size() - 1;

	while (flag == false && min < max)
	{
		int mid = (min + max) / 2;

		if (m_map[mid].m_studentName == name)
		{
			flag = true;
			return m_map[mid].m_studentGrade;
		}
		else
		{
			if (m_map[mid].m_studentName < name)
			{
				min = mid + 1;
			}
			else
			{
				max = mid - 1;
			}
		}
	}

	//StudentGrade tmp{ name, ' ' };
	//m_map.push_back(tmp);
	m_map.push_back(StudentGrade{name, ' '});
	//m_map.back().m_studentName = name;
	return m_map.back().m_studentGrade;
}

int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

	return 0;
}