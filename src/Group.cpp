#include "Group.h"
#include <iostream>
#include <stdexcept>

Group::Group(std::string _title, std::string _spec) {
	title = _title;
	spec = _spec;
	
}

Group::~Group() {
	std::cout << "Группа " << title << " " << spec << " расформирована" << "\n";
	for (auto student : students) {
		delete student;
	}
}

void Group::addStudent(Student* _student) {
	students.push_back(_student);
}

void Group::chooseHead() {
	head = nullptr;
	if (students.size()) {
		int headIndex = rand() % students.size();
		head = students[headIndex];
	}
}

Student* Group::findStudent(int _id, std::string _fio) {
	for (Student* student : students) {
		if (student->id == _id && student->fio == _fio) {
			return student;
		}
	}
	return nullptr;
}

double Group::meanGroupMark() {
	double sum = 0;
	int cnt = 0;
	for (Student* student : students) {
		cnt += student->marks.size();
		for (int mark : student->marks) {
			sum += mark;
		}
	}
	if (cnt == 0)return 0;
	return sum / cnt;
}

void Group::deduct(Student* _student, Group* _transferGroup) {
	for (auto iter = students.begin(); iter != students.end(); iter++) {
		if (*iter == _student) {
			students.erase(iter);
			if (head == _student) {
				chooseHead();
			}
			if (_transferGroup == nullptr) {
				delete _student;
			}
			break;
		}
	}
}

std::string Group::getTitle() const{
	return title;
}

std::string Group::getSpec() const{
	return spec;
}

int Group::getGroupSize() const{
	return students.size();
}

std::vector<std::pair<int, std::string>> Group::getStudentsList() const {
	std::vector<std::pair<int, std::string>>list;
	for (Student* student:students) {
		list.push_back({ student->id, student->fio });
	}
	return list;
}
