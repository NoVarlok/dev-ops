#include "Student.h"
#include "Group.h"
#include <iostream>
#include <boost/program_options.hpp>


Student::Student(int _id, std::string _fio, Group* _group) {
	id = _id;
	fio = _fio;
	if (_group != nullptr) {
		_group->addStudent(this);
	}
}

Student::~Student() {
	std::cout << id << " " << fio << " " << "отчислен(-а)" << '\n';
}

void  Student::addToGroup(Group* _group) {
	_group->addStudent(this);
}

void Student::addMark(int _mark) {
	marks.push_back(_mark);
}

double Student::meanMark() {
	double sum = 0;
	for (int mark : marks) {
		sum += mark;
	}
	if (marks.size() == 0)return 0;
	return sum / marks.size();
}

int Student::getId() {
	return id;
}

std::string Student::getFio() {
	return fio;
}

Group* Student::getGroup() {
	return group;
}


std::vector<int> Student::getMarks() {
	return marks;
}
std::vector<std::string> Student::getStatistics() {
	std::vector<std::string> stat(5, "");
	stat[0] = std::to_string(id);
	stat[1] = fio;
	if (group != nullptr) {
		stat[2] = group->getTitle();
		stat[3] = group->getSpec();
	}
	for (int mark : marks) {
		stat[4] += std::to_string(mark);
	}
	return stat;
}