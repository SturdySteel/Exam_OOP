#ifndef ITESTS_H
#define ITESTS_H
#include <fstream>
#include <locale>
#include <regex>
#include "GroupsTests.h"
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
	GroupsTests* grTests{ nullptr };
	GroupTest* grTest{ nullptr };
	SubGroupTest* subGrTest{ nullptr };
	Test* test{ nullptr };
	TestLine* tesLine{ nullptr };
	std::vector<GroupsTests> allTests;

public:
	ITests();

	void getAllTests();
	void setAllTests();
	void getGroupsTest();

	~ITests();
};

#endif // !ITESTS_H
