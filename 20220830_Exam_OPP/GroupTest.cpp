#include "GroupTest.h"

GroupTest::GroupTest():
	numGroupTest{},
	nameGroupTest{},
	tableGroupTest{}
	//subGrTest{ new std::vector<SubGroupTest> }
{}

void GroupTest::setNumGroupTest(int numGroupTest) {
	this->numGroupTest = numGroupTest;
}

void GroupTest::setNameGroupTest(std::string nameGroupTest) {
	this->nameGroupTest = nameGroupTest;
}

void GroupTest::setTableGroupTest(std::string tableGroupTest) {
	this->tableGroupTest = tableGroupTest;
}

void GroupTest::setSubGrTest(SubGroupTest& val) {
	this->subGrTest.push_back(val);
}

int GroupTest::getNumGroupTest() {
	return this->numGroupTest;
}

std::string GroupTest::getNameGroupTest() {
	return this->nameGroupTest;
}

std::string GroupTest::getTableGroupTest() {
	return this->tableGroupTest;
}

std::vector<SubGroupTest>& GroupTest::getSubGrTest() {
	return this->subGrTest;
}

GroupTest& GroupTest::getGroupTest() {
	return *this;
}

//GroupTest::~GroupTest() {
//	if (subGrTest != nullptr) {
//		this->subGrTest->clear();
//		delete subGrTest;
//	}
//}
