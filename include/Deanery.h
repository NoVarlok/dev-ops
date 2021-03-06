/* Copyright (C) 2020 Leonid Yakhtin - All Rights Reserved
 */

#pragma once

#include <vector>
#include <map>
#include <string>
#include "Group.h"
#include "Student.h"

class Deanery{
	std::map<std::string, Group*>groups;
 public:
	void loadGroupsFromFile(std::string _filename);
	void loadStudentsFromFile(std::string _filename);
	void addRandomMarks(int _number = 1);
	void addGroup(Group* _group, bool force = false);
	void getStatistics() const;
	int getSize() const;
	void transfer(Student* _student, Group* _from, Group* _to);
	void dismissal(int _number = 3);
	void saveToFile(std::string _filename);
	void chooseHeads();
	void print();
	Group* findGroup(std::string _title);
	std::vector<std::string> getGroupTitles() const;
	Deanery();
	~Deanery();
};

