/* Copyright (C) 2020 Leonid Yakhtin - All Rights Reserved
 */

#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Student.h"
#include "Group.h"

class Group{
	std::string title, spec;
	std::vector<Student*>students;
	Student* head;

 public:
	explicit Group(std::string _title, std::string _spec = "Undefined");
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
	std::vector<std::pair<int, std::string>> getStudentsList() const;
	friend class Deanery;
};
