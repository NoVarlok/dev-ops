/* Copyright (C) 2020 Leonid Yakhtin - All Rights Reserved
 */

#include "Group.h"
#include <iostream>
#include <random>
#include <boost/program_options.hpp>


Group::Group(std::string _title, std::string _spec) {
	title = _title;
	spec = _spec;
}

Group::~Group() {
	std::cout << "Group " << title << " " << spec << " is disbanded" << "\n";
	for (Student* student : students) {
		delete student;
	}
}

void Group::addStudent(Student* _student) {
	students.push_back(_student);
	_student->group = this;
}

void Group::chooseHead() {
	head = nullptr;
	if (students.size()) {
		unsigned int temp = 10000;
		int headIndex = rand_r(&temp) % students.size();
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

std::string Group::getTitle() const {
	return title;
}

std::string Group::getSpec() const {
	return spec;
}

Student* Group::getHead() const {
	return head;
}

int Group::getGroupSize() const {
	return students.size();
}

std::vector<std::pair<int, std::string>> Group::getStudentsList() const {
	std::vector<std::pair<int, std::string>> list;
	for (Student* student : students) {
		list.push_back({ student->id, student->fio });
	}
	return list;
}
