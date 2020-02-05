#include "Student.h"
#include <iostream>

Student::Student(int _id, std::string _fio, Group* _group) {
	id = _id;
	fio = _fio;
	group = _group;
}

Student::~Student() {
	std::cout << id << " " << fio << " " << "отчислен(-а)" << '\n';
}

void  Student::addToGroup(Group* _group) {
	group = _group;
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

std::vector<int> Student::getMarks() {
	return marks;
}