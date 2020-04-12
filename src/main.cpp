#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
//#include <filesystem>
#include "Deanery.h"
#include "Student.h"
#include "Group.h"
using namespace std;

int main() {
	system("chcp 1251");
	//cout << filesystem::current_path() << '\n';
	Deanery dean;
	//dean.loadGroupsFromFile("group_input.txt");
	dean.loadStudentsFromFile("/input_data/student_input.txt");
	dean.chooseHeads();
	dean.addRandomMarks(3);
	dean.print();
	dean.saveToFile("output.txt");
	dean.getStatistics();
	std::vector<std::string>list = dean.getGroupTitles();
	for (std::string s : list) {
		cout << s << "\n";
	}
	cout << std::endl;
	Group* from = dean.findGroup(list[0]);
	Group* to = dean.findGroup(list[1]);
	cout << from->getTitle() << " " << from->getSpec() << std::endl<<std::endl;
	cout << to->getTitle() << " " << to->getSpec() << std::endl<<std::endl;
	std::vector < std::pair<int, std::string>>fromlist = from->getStudentsList();
	for (auto t : fromlist) {
		cout << "(" << t.first << ", " << t.second << "), ";
	}
	cout << std::endl;
	std::vector < std::pair<int, std::string>>tolist = to->getStudentsList();
	for (auto t : tolist) {
		cout << "(" << t.first << ", " << t.second << "), ";
	}
	cout << std::endl;
	dean.transfer(from->findStudent(fromlist[0].first, fromlist[0].second), from, to);
	fromlist = from->getStudentsList();
	tolist = to->getStudentsList();
	for (auto t : fromlist) {
		cout << "(" << t.first << ", " << t.second << "), ";
	}
	cout << std::endl;
	for (auto t : tolist) {
		cout << "(" << t.first << ", " << t.second << "), ";
	}
	cout << std::endl;
	return 0;
}