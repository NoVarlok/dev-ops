#ifndef DEANERY_H
#define DEANERY_H

#include <vector>
#include <map>
#include <string>
#include "Group.h"
#include "Student.h"

class Deanery
{
	std::map<std::string, Group*>groups;

public:
	void loadGroupsFromFile(std::string _filename);
	void loadStudentsFromFile(std::string _filename);
	void addRandomMarks(int _number=1);
	void getStatistics();
	void transfer(Student* _student, Group* _from, Group* _to);
	void dismissal(int _number=3);
	void saveToFile(std::string _filename);
	void chooseHeads();
	void print();
	Group* findGroup(std::string _title);
	std::vector<std::string> getGroupTitles() const;
	Deanery();
	~Deanery();
};

#endif // !DEANERY_H