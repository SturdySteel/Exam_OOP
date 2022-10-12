#ifndef SUBGROUPTEST_H
#define SUBGROUPTEST_H
#include <string>
#include <vector>
#include "Test.h"

class SubGroupTest
{
private:
	int numGrTest;
	std::string nameGroupTest;
	std::string tableGroupTest;	
	std::vector<Test> arrTests;

public:
	SubGroupTest();

	void setTests(Test& val);
	
	void setNumGrTest(int numGrTest);
	void setNameGroupTest(std::string nameGroupTest);
	void setTableGroupTest(std::string tableGroupTest);

	int getNumGrTest();
	std::string getNameGroupTest();
	std::string getTableGroupTest();
	std::vector<Test>& getArrTests();

	SubGroupTest& getSubGrArr();

	//~SubGroupTest();
};

#endif // !SUBGROUPTEST_H
