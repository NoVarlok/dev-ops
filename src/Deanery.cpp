#include "Deanery.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <boost/program_options.hpp>


static 	int tableSize = 90;

std::vector<std::string> split(std::string&s, char separator) {
	std::vector<std::string>tokens;
	std::istringstream split_stream(s);
	std::string string_part;
	while (std::getline(split_stream, string_part, separator)) {
		tokens.push_back(string_part);
	}
	return tokens;
}

void Deanery::loadGroupsFromFile(std::string _filename) {
	std::ifstream input(_filename);
	std::string s;
	while (true) {
		std::getline(input, s);
		if (s == "")break;
		std::string group_title, group_spec;
		std::vector<std::string>tokens = split(s, ';');
		group_title = tokens[0];
		group_spec = tokens[1];
		Group* newGroup = new Group(group_title, group_spec);
		groups[group_title] = newGroup;
	}
	input.close();
}

void Deanery::loadStudentsFromFile(std::string _filename) {
	std::ifstream input(_filename);
	std::string s;
	while (true) {
		std::getline(input, s);
		if (s == "")break;
		std::vector<std::string> tokens = split(s, ';');
		int student_id = stoi(tokens[0]);
		std::string student_fio = tokens[1];
		std::string student_group = tokens[2];
		std::string student_spec = tokens[3];
		if (groups.count(student_group) == 0) {
			Group* newGroup = new Group(student_group, student_spec);
			groups[student_group] = newGroup;
		}
		if (groups[student_group]->findStudent(student_id, student_fio) != nullptr)continue;
		Student* newStudent = new Student(student_id, student_fio);
		for (int i = 4; i < tokens.size(); i++) {
			int student_mark = stoi(tokens[i]);
			newStudent->addMark(student_mark);
		}
		groups[student_group]->addStudent(newStudent);
	}
	input.close();
}

void Deanery::addRandomMarks(int _number) {
	for (std::pair<std::string, Group*> temp : groups) {
		for (Student* student : temp.second->students) {
			for (int i = 0; i < _number; i++) {
				student->addMark(std::rand() % 4 + 2);
			}
		}
	}
}

void Deanery::getStatistics() const{
	for (int i = 0; i < tableSize; i++) {
		std::cout << "-";
	}
	std::cout << '\n';
	std::cout << std::setw(15) << "group title" << " | " << std::setw(10) << "group spec" << " | " << std::setw(10) << "head id" << " | " << std::setw(30) << "head fio" << " | " << "mean mark" << '\n';
	for (int i = 0; i < tableSize; i++) {
		std::cout << "-";
	}
	std::cout << '\n';
	for (auto temp : groups) {
		Group* group = temp.second;
		std::cout << std::setw(15) << group->title << " | " << std::setw(10) << group->spec << " | ";
		if (group->head == nullptr) {
			std::cout << std::setw(10) << "undefined" << " | " << std::setw(30) << "undefined" << " | ";
		}
		else {
			std::cout << std::setw(10) << group->head->id << " | " << std::setw(30) << group->head->fio << " | ";
		}
		std::cout << group->meanGroupMark() << '\n';
	}
}

int Deanery::getSize() const {
	return groups.size();
}

void Deanery::transfer(Student* _student, Group* _from, Group* _to) {
	_from->deduct(_student, _to);
	//if (_from->head == _student) {
	//	_from->chooseHead();
	//}
	_to->addStudent(_student);	
}

void Deanery::dismissal(int _number) {
	for (std::pair<std::string, Group*> temp : groups) {
		std::vector<Student*>dismissalList;
		for (Student* student : temp.second->students) {
			int badMarks = 0;
			for (int mark : student->marks) {
				if (mark == 2) {
					badMarks++;
				}
			}
			if (badMarks >= _number) {
				dismissalList.push_back(student);
			}
		}
		for (Student* student : dismissalList) {
			temp.second->deduct(student);
		}
	}
}

void Deanery::saveToFile(std::string _filename) {
	std::ofstream out(_filename);
	for (auto temp : groups) {
		Group* group = temp.second;
		for (Student* student : group->students) {
			out << student->id << ";" << student->fio << ";" << student->group->title << ";" << student->group->spec << ";";
			for (int mark : student->marks) {
				out << mark << ";";
			}
			out << '\n';
		}
	}
	out.close();
}

void Deanery::chooseHeads() {
	for (std::pair<std::string, Group*> temp : groups) {
		temp.second->chooseHead();
	}
}

void Deanery::print() {
	std::cout << "Список деканата" << '\n';
	for (auto temp : groups) {
		Group* group = temp.second;
		for (int i = 0; i < tableSize; i++) {
			std::cout << "-";
		}
		std::cout << '\n';
		std::cout <<  group->title << ", " << group->spec << '\n';
		for (int i = 0; i < tableSize; i++) {
			std::cout << "-";
		}
		std::cout << '\n';
		std::cout << std::setw(3) << "id" << " | " << std::setw(30) << "FIO" << " | " << std::setw(15) << "group title" << " | " << std::setw(10) << "group spec" << " | " << std::setw(5) << "marks" << '\n';
		for (Student* student : group->students) {
			std::cout << std::setw(3) << student->id << " | " << std::setw(30) << student->fio << " | " << std::setw(15) << group->title << " | " << std::setw(10) << group->spec << " | ";
			for (int mark : student->marks) {
				std::cout << mark;
			}
			std::cout << '\n';
		}
		for (int i = 0; i < tableSize; i++) {
			std::cout << "-";
		}
		std::cout << '\n';
	}
}

Deanery::Deanery() {
	std::cout << "Deanery is created" << std::endl;
	std::srand(time(0));
}

Deanery::~Deanery() {
	std::cout << "Деканат расформирован" << '\n';
	for (auto temp : groups) {
		delete temp.second;
	}
}

Group* Deanery::findGroup(std::string _title){
	if (groups.count(_title) == 0)return nullptr;
	return groups[_title];
}

std::vector<std::string> Deanery::getGroupTitles() const{
	std::vector<std::string>list;
	for (auto temp : groups) {
		list.push_back(temp.first);
	}
	return list;
}

void Deanery::addGroup(Group* group, bool force) {
	if (groups.count(group->title) == 0) {
		groups[group->title] = group;
	}
	else if (force && groups[group->title] != group) {
		delete groups[group->title];
		groups[group->title] = group;
	}
}