#ifndef GROUPSTESTS_H
#define GROUPSTESTS_H
#include <string>
#include <vector>
#include "GroupTest.h"

class GroupsTests
{
//public:
private:
	int idGrTest;
	std::string nameGroup;
	int countTest;
	std::string tableName;	
	std::vector<GroupTest>* grTest;

public:
	GroupsTests();

	void setIdGrTest(int idGrTest);
	void setNameGroup(std::string nameGroup);
	void setTableName(std::string tableName);
	void setCountTest(int countTest);
	void setGrTest(GroupTest& val);

	int getIdGrTest();
	std::string getNameGroup();
	std::string getTableName();
	int getCountTest();
	std::vector<GroupTest>& getGrTest();

	GroupsTests& getGroupsTests();

	~GroupsTests();
};

#endif // !GROUPSTESTS_H
