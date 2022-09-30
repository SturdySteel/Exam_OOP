#include "SubGroupTest.h"

SubGroupTest::SubGroupTest() :
	numGrTest{},
	nameGroupTest{},
	tableGroupTest{}
	//tests{ new std::vector<Test> }
{}

void SubGroupTest::setNumGrTest(int numGrTest) { this->numGrTest = numGrTest; }

void SubGroupTest::setNameGroupTest(std::string nameGroupTest) { this->nameGroupTest = nameGroupTest; }

void SubGroupTest::setTableGroupTest(std::string tableGroupTest) { this->tableGroupTest = tableGroupTest; }

int SubGroupTest::getNumGrTest() { return this->numGrTest; }

std::string SubGroupTest::getNameGroupTest() { return this->nameGroupTest; }

std::string SubGroupTest::getTableGroupTest() { return this->tableGroupTest; }

std::vector<Test>& SubGroupTest::getTests() { return this->tests; }

void SubGroupTest::setTests(Test& test) { this->tests.push_back(test); }

SubGroupTest& SubGroupTest::getSubGroup() {	return *this; }

//SubGroupTest::~SubGroupTest() {
//	if (tests != nullptr) {
//		this->tests->clear();
//		delete tests;
//	}
//}
