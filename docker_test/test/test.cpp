/* Copyright (C) 2020 Leonid Yakhtin - All Rights Reserved
 */

#include "Deanery.h"
#include "Student.h"
#include "Group.h"
#include "gtest/gtest.h"

TEST(TestStudent, StudentGetIdCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	student1->addMark(4);
	student1->addMark(1);
	group1->chooseHead();
	std::vector<int>marks = { 5, 4, 1 };
	EXPECT_EQ(student1->getId(), 1);
}
TEST(TestStudent, StudentGetFioCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	student1->addMark(4);
	student1->addMark(1);
	group1->chooseHead();
	std::vector<int>marks = { 5, 4, 1 };
	EXPECT_EQ(student1->getFio(), "Yershov Abram Robertovich");
}
TEST(TestStudent, StudentGetGroupCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	student1->addMark(4);
	student1->addMark(1);
	group1->chooseHead();
	std::vector<int>marks = { 5, 4, 1 };
	EXPECT_EQ(student1->getGroup(), group1);
}
TEST(TestStudent, StudentGetMarksCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	student1->addMark(4);
	student1->addMark(1);
	group1->chooseHead();
	std::vector<int>marks = { 5, 4, 1 };
	EXPECT_EQ(student1->getMarks(), marks);
}
TEST(TestStudent, StudentGetMeanMarkCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	student1->addMark(4);
	student1->addMark(1);
	group1->chooseHead();
	std::vector<int> marks = { 5, 4, 1 };
	EXPECT_DOUBLE_EQ(student1->meanMark(), (5 + 4 + 1) / 3.0);
}

// Group tests

TEST(TestGroup, GroupGetTitleCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getTitle(), "PI-1");
}

TEST(TestGroup, GroupGetSpecCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getSpec(), "PI");
}

TEST(TestGroup, GroupAddStudentCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich");
	group1->addStudent(student1);
	EXPECT_EQ(group1->getGroupSize(), 1);
}

TEST(TestGroup, GroupChooseHeadCheak) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getGroupSize(), 0);
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	group1->chooseHead();
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	EXPECT_EQ(group1->getHead(), student1);
}

TEST(TestGroup, GroupFindStudentYesCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getGroupSize(), 0);
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	group1->chooseHead();
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	EXPECT_EQ(group1->findStudent(student2->getId(),
				student2->getFio()), student2);
}

TEST(TestGroup, GroupFindStudentNoCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getGroupSize(), 0);
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	group1->chooseHead();
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	EXPECT_EQ(group1->findStudent(3, student2->getFio()), nullptr);
}

TEST(TestGroup, GroupSizeCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getGroupSize(), 0);
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	group1->chooseHead();
	EXPECT_EQ(group1->getGroupSize(), 2);
}

TEST(TestGroup, GroupDeductCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	group1->deduct(student2);
	EXPECT_EQ(group1->getGroupSize(), 1);
}

// Deanery tests

TEST(TestDeanery, DeaneryAddGroupCheck) {
	Deanery deanery;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	Group* group2 = new Group("PMI-1", "PMI");
	Student* student3 = new Student(1, "Yershov Abraam Robertovich", group2);
	Student* student4 = new Student(2, "Kudryavtsev Oleg Borisovich", group2);
	deanery.addGroup(group1);
	deanery.addGroup(group1);
	deanery.addGroup(group2);
	EXPECT_EQ(deanery.getSize(), 2);
}

TEST(TestDeanery, DeaneryTransferCheck) {
	Deanery deanery;
	Group* group1 = new Group("PI-1", "PI");
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	Group* group2 = new Group("PMI-1", "PMI");
	Student* student3 = new Student(1, "Yershov Abraam Robertovich", group2);
	Student* student4 = new Student(2, "Kudryavtsev Oleg Borisovich", group2);
	deanery.addGroup(group1);
	deanery.addGroup(group2);
	deanery.transfer(student3, group2, group1);
	EXPECT_EQ(group1->getGroupSize(), 3);
	EXPECT_EQ(group2->getGroupSize(), 1);
}

TEST(TestDeanery, DeaneryDimissalCheck) {
	Deanery deanery1;
	Group* group1 = new Group("PI-1", "PI");
	EXPECT_EQ(group1->getGroupSize(), 0);
	Student* student1 = new Student(1, "Yershov Abram Robertovich", group1);
	student1->addMark(5);
	Student* student2 = new Student(2, "Kudryavtsev Oleg Borisovich", group1);
	student2->addMark(2);
	student2->addMark(3);
	Student* student3 = new Student(3, "Guriev Willie Parfenovich", group1);
	student3->addMark(2);
	student3->addMark(2);
	student3->addMark(5);
	Student* student4 = new Student(4, "Yershov Igor Bogdanovich", group1);
	group1->chooseHead();
	deanery1.addGroup(group1);
	deanery1.dismissal(1);
	EXPECT_EQ(group1->getGroupSize(), 2);
}

TEST(TestDeanery, DeaneryGetGroupTitlesCheck) {
	Deanery deanery;
	Group* group1 = new Group("PI-1", "PI");
	Group* group2 = new Group("PI-2", "PI");
	Group* group3 = new Group("PMI-1", "PMI");
	deanery.addGroup(group1);
	deanery.addGroup(group2);
	deanery.addGroup(group3);
	std::vector<std::string> answer = { "PI-1", "PI-2", "PMI-1" };
	EXPECT_EQ(deanery.getGroupTitles(), answer);
}

TEST(TestDeanery, DeaneryGetGroupTitlesYesCheck) {
	Deanery deanery;
	Group* group1 = new Group("PI-1", "PI");
	Group* group2 = new Group("PI-2", "PI");
	Group* group3 = new Group("PMI-1", "PMI");
	deanery.addGroup(group1);
	deanery.addGroup(group2);
	deanery.addGroup(group3);
	EXPECT_EQ(deanery.findGroup(group1->getTitle()), group1);
}

TEST(TestDeanery, DeaneryGetGroupTitlesNoCheck) {
	Deanery deanery;
	Group* group1 = new Group("PI-1", "PI");
	Group* group2 = new Group("PI-2", "PI");
	Group* group3 = new Group("PMI-1", "PMI");
	deanery.addGroup(group1);
	deanery.addGroup(group2);
	deanery.addGroup(group3);
	EXPECT_EQ(deanery.findGroup(""), nullptr);
}

int main(int argc, char** argv) {
	printf("hello world!");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
