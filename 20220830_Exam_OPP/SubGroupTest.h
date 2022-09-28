#ifndef SUBGROUPTEST_H
#define SUBGROUPTEST_H
#include <string>
#include <vector>
#include "Test.h"

class SubGroupTest
{
//public:
private:
	int numTest;
	std::string nameTest;
	std::string tableNameTest;
	int countQuestions;
	std::vector<Test> tests;

public:
	SubGroupTest();

	void setNumTest(int numTest);
	void setNameTest(std::string nameTest);
	void setTableNameTest(std::string tableNameTest);
	void setCountQuestions(int countQuestions);
	void setTests(Test& val);

	int getNumTest();
	std::string getNameTest();
	std::string getTableNameTest();
	int getCountQuestions();
	std::vector<Test>& getTests();

	SubGroupTest& getSubGroup();

	//~SubGroupTest();
};

#endif // !SUBGROUPTEST_H
