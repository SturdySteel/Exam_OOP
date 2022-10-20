#include "TestPassed.h"

TestPassed::TestPassed(int num, int groupNum, int subGroupNum, int testNum,
	int countAnswers, int countRightAnswers, int countTry, bool passed) :
	num{ num }, groupNum{ groupNum }, subGroupNum{ subGroupNum }, testNum{ testNum },
	countAnswers{}, countRightAnswers{ countRightAnswers }, countTry{ countTry }, passed{ passed }
{}

void TestPassed::setNum(int num) { this->num = num; }

void TestPassed::setGroupNum(int groupNum) { this->groupNum = groupNum; }

void TestPassed::setSubGroupNum(int subGroupNum) { this->subGroupNum = subGroupNum; }

void TestPassed::setTestNum(int testNum) { this->testNum = testNum; }

void TestPassed::setCountAnswers(int countAnswers) { this->countAnswers = countAnswers; }

void TestPassed::setCountRightAnswers(int countRightAnswers) { this->countRightAnswers = countRightAnswers; }

void TestPassed::setCountTry(int countTry) { this->countTry = countTry; }

void TestPassed::setPassed(bool passed) { this->passed = passed; }

int TestPassed::getNum() { return this->num; }

int TestPassed::getGroupNum() { return this->groupNum; }

int TestPassed::getSubGroupNum() { return this->subGroupNum; }

int TestPassed::getTestNum() { return this->testNum; }

int TestPassed::getCountAnswers() { return this->countAnswers; }

int TestPassed::getCountRightAnswers() { return this->countRightAnswers; }

int TestPassed::getCountTry() { return this->countTry; }

bool TestPassed::getPassed() { return this->passed; }
