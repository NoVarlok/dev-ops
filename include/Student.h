#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

extern class Group;

class Student
{
	int id;
	std::string fio;
	Group * group;
	std::vector<int> marks;


public:
	Student(int _id, std::string _fio, Group* _group=nullptr);
	~Student();
	void  addToGroup(Group* _group);
	void addMark(int _mark);
	double meanMark();

	int getId();
	std::string getFio();
	std::vector<int> getMarks();

	friend class Group;
	friend class Deanery;
};

#endif // !STUDENT_H
