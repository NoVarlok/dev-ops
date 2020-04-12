#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"

class Group
{
	std::string title, spec;
	std::vector<Student*>students;
	Student* head;

public:
	Group(std::string _title, std::string _spec = "Undefined");
	~Group();
	void addStudent(Student* _student);
	void chooseHead();
	Student* findStudent(int _id, std::string _fio);
	double meanGroupMark();
	void deduct(Student* _student, Group* _transferGroup = nullptr);
	std::string getTitle() const;
	std::string getSpec() const;
	Student* getHead() const;
	int getGroupSize() const;
	std::vector<std::pair<int, std::string>>getStudentsList() const;
	friend class Deanery;
};

#endif // !GROUP_H
