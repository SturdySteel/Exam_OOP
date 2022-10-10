#ifndef ITESTS_H
#define ITESTS_H
#include <fstream>
#include <locale>
#include <regex>
#include "GroupTest.h"
#include "SubGroupTest.h"
#include "Test.h"
#include "TestLine.h"
#include "queryDB.h"
#include "typeinfo"
#include "DataEdit.h"
//#include <boost/locale.hpp>

class ITests
{
private:	
	GroupTest* grTest{ nullptr };
	SubGroupTest* subGrTest{ nullptr };
	Test* test{ nullptr };
	TestLine* testLine{ nullptr };
	std::vector<GroupTest> arrTests;
	
public:
	ITests();
	
	void getAllTests();
	void setAllTests();
	//void getGroupsTest();

	TestLine* setTest(int i);

	void setGrTest(GroupTest& val);

	std::vector<GroupTest>& getGrTest();

	ITests& getGroupTest();

	~ITests();
};

#endif // !ITESTS_H
