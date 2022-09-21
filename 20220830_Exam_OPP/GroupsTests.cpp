#include "GroupsTests.h"

GroupsTests::GroupsTests():
	idGrTest{},
	nameGroup{},
	tableName{},
	countTest{},
	grTest{new std::vector<GroupTest> }
{}

void GroupsTests::setIdGrTest(int idGrTest) {
	this->idGrTest = idGrTest;
}

void GroupsTests::setNameGroup(std::string nameGroup) {
	this->nameGroup = nameGroup;
}

void GroupsTests::setTableName(std::string tableName) {
	this->tableName = tableName;
}

void GroupsTests::setCountTest(int countTest) {
	this->countTest = countTest;
}

void GroupsTests::setGrTest(GroupTest& val) {
	grTest->push_back(val);
}

int GroupsTests::getIdGrTest() {
	return this->idGrTest;
}

std::string GroupsTests::getNameGroup() {
	return this->nameGroup;
}

std::string GroupsTests::getTableName() {
	return this->tableName;
}

int GroupsTests::getCountTest() {
	return this->countTest;
}

std::vector<GroupTest>& GroupsTests::getGrTest() {
	return *this->grTest;
}

GroupsTests& GroupsTests::getGroupsTests() {
	return *this;
}

GroupsTests::~GroupsTests() {
	if (grTest != nullptr) {
		this->grTest->clear();
		delete grTest;
	}
}
