#ifndef GROUPTEST_H
#define GROUPTEST_H
#include <string>
#include <vector>
#include "SubGroupTest.h"

class GroupTest
{
//public:
private:
	int idGrTest;
	std::string nameGroup;
	int countTest{ 1 };
	std::string tableName;	
	std::vector<SubGroupTest> arrSubGrTest;

public:
	GroupTest();

	void setIdGrTest(int idGrTest);
	void setNameGroup(std::string nameGroup);
	void setTableName(std::string tableName);
	void setCountTest(int countTest);		
	void setSubGrTest(SubGroupTest& val);

	int getIdGrTest();
	std::string getNameGroup();
	std::string getTableName();
	int getCountTest();	
	std::vector<SubGroupTest>& getArrSubGrTest();

	GroupTest& getGroupTest();

	//~GroupTest();
};

#endif // !GROUPTEST_H
