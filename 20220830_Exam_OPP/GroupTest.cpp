#include "GroupTest.h"

GroupTest::GroupTest() :
	idGrTest{},
	nameGroup{},
	tableName{},
	countTest{}
	//subGrTest{ new std::vector<SubGroupTest> }
{}

void GroupTest::setIdGrTest(int idGrTest) { this->idGrTest = idGrTest; }

void GroupTest::setNameGroup(std::string nameGroup) { this->nameGroup = nameGroup; }

void GroupTest::setTableName(std::string tableName) { this->tableName = tableName; }

void GroupTest::setCountTest(int countTest) { this->countTest = countTest; }

void GroupTest::setSubGrTest(SubGroupTest& val) { this->subGrTest.push_back(val); }

int GroupTest::getIdGrTest() { return this->idGrTest; }

std::string GroupTest::getNameGroup() { return this->nameGroup; }

std::string GroupTest::getTableName() { return this->tableName; }

int GroupTest::getCountTest() { return this->countTest; }

std::vector<SubGroupTest>& GroupTest::getSubGrTest() { return this->subGrTest; }

GroupTest& GroupTest::getGroupTest() { return *this; }

//GroupTest::~GroupTest() {
//	if (subGrTest != nullptr) {
//		this->subGrTest->clear();
//		delete subGrTest;
//	}
//}
