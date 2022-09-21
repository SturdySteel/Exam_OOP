#include "Test.h"

Test::Test() :
	nameTable{},
	arrTest{ new std::vector<TestLine> }
{}

void Test::setTestLine(TestLine& line) {
	this->arrTest->push_back(line);
}

void Test::setNameTab(std::string nameTable) {
	this->nameTable = nameTable;
}

Test& Test::getTest() {
	return *this;
}

Test::~Test() {
	if (arrTest != nullptr) {
		this->arrTest->clear();
		delete arrTest;
	}
}
