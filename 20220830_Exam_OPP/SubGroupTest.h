#ifndef SUBGROUPTEST_H
#define SUBGROUPTEST_H
#include <string>
#include <vector>
#include "Test.h"

class SubGroupTest
{
//public:
private:
	int numGrTest;
	std::string nameGroupTest;
	std::string tableGroupTest;	
	std::vector<Test> tests;

public:
	SubGroupTest();

	void setTests(Test& val);
	std::vector<Test>& getTests();

	void setNumGrTest(int numGrTest);
	void setNameGroupTest(std::string nameGroupTest);
	void setTableGroupTest(std::string tableGroupTest);

	int getNumGrTest();
	std::string getNameGroupTest();
	std::string getTableGroupTest();

	SubGroupTest& getSubGroup();

	//~SubGroupTest();
};

#endif // !SUBGROUPTEST_H
