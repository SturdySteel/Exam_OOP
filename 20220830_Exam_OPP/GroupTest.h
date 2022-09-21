#ifndef GROUPTEST_H
#define GROUPTEST_H
#include <string>
#include <vector>
#include "SubGroupTest.h"

class GroupTest
{
//public:
private:
	int numGroupTest;
	std::string nameGroupTest;
	std::string tableGroupTest;
	std::vector<SubGroupTest>* subGrTest;

public:
	GroupTest();

	void setNumGroupTest(int numGroupTest);
	void setNameGroupTest(std::string nameGroupTest);
	void setTableGroupTest(std::string tableGroupTest);
	void setSubGrTest(SubGroupTest& val);

	int getNumGroupTest();
	std::string getNameGroupTest();
	std::string getTableGroupTest();
	std::vector<SubGroupTest>& getSubGrTest();

	GroupTest& getGroupTest();

	~GroupTest();
};

#endif // !GROUPTEST_H
