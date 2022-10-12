#include "Test.h"

Test::Test() :
	numTest{},
	nameTest{},
	tableNameTest{},
	countQuestions{}
	//arrTest{ new std::vector<TestLine> }
{}

void Test::setTestLine(TestLine* line) { this->arrTestLines.push_back(*line); delete line; }


void Test::setNumTest(int numTest) { this->numTest = numTest; }

void Test::setNameTest(std::string nameTest) { this->nameTest = nameTest; }

void Test::setTableNameTest(std::string tableNameTest) { this->tableNameTest = tableNameTest; }

void Test::setCountQuestions(int countQuestions) { this->countQuestions = countQuestions; }


int Test::getNumTest() { return this->numTest; }

std::string Test::getNameTest() { return this->nameTest; }

std::string Test::getTableNameTest() { return this->tableNameTest; }

int Test::getCountQuestions() {	return this->countQuestions; }


Test& Test::getTest() { return *this; }

std::vector<TestLine>& Test::getArrTestLines()
{
	 return this->arrTestLines;
}

//Test::~Test() {
//	if (arrTest != nullptr) {
//		this->arrTest->clear();
//		delete arrTest;
//	}
//}
