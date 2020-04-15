/* Copyright (C) 2020 Leonid Yakhtin - All Rights Reserved
 */

#pragma once

#include <string>
#include <vector>

class Group;

class Student{
	int id;
	std::string fio;
	Group * group;
	std::vector<int> marks;


 public:
	Student(int _id, std::string _fio, Group* _group = nullptr);
	~Student();
	void  addToGroup(Group* _group);
	void addMark(int _mark);
	double meanMark();

	int getId();
	Group* getGroup();
	std::string getFio();
	std::vector<int> getMarks();
	std::vector<std::string>getStatistics();

	friend class Group;
	friend class Deanery;
};
