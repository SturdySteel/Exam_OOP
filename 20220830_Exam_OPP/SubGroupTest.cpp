#include "SubGroupTest.h"

SubGroupTest::SubGroupTest():
	numTest{},
	nameTest{},
	tableNameTest{},
	countQuestions{}
	//tests{ new std::vector<Test> }
{}

void SubGroupTest::setNumTest(int numTest) {
	this->numTest = numTest;
}


void SubGroupTest::setNameTest(std::string nameTest) {
	this->nameTest = nameTest;
}

void SubGroupTest::setTableNameTest(std::string tableNameTest) {
	this->tableNameTest = tableNameTest;
}

void SubGroupTest::setCountQuestions(int countQuestions) {
	this->countQuestions = countQuestions;
}

void SubGroupTest::setTests(Test& test) {
	this->tests.push_back(test);
}

int SubGroupTest::getNumTest() { 
	return this->numTest; 
}

std::string SubGroupTest::getNameTest() { 
	return this->nameTest; 
}

std::string SubGroupTest::getTableNameTest() { 
	return this->tableNameTest; 
}
int SubGroupTest::getCountQuestions() { 
	return this->countQuestions; 
}

std::vector<Test>& SubGroupTest::getTests() { 
	return this->tests; 
}

SubGroupTest& SubGroupTest::getSubGroup() {	
	return *this; 
}

//SubGroupTest::~SubGroupTest() {
//	if (tests != nullptr) {
//		this->tests->clear();
//		delete tests;
//	}
//}
