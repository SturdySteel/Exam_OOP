#ifndef ITESTS_H
#define ITESTS_H
#include <fstream>
#include <locale>
#include <regex>
#include <iomanip>
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
	/*GroupTest* grTest{ nullptr };
	SubGroupTest* subGrTest{ nullptr };
	Test* test{ nullptr };*/
	//TestLine* testLine{ nullptr };
	std::vector<GroupTest> arrTests;
	static int counter;

private:
	TestLine* setTest(int i);
	//void setIgrTest(GroupTest*& grTest, std::string str);
	//void setIsubGrTest(SubGroupTest*& grTest, std::string str, auto& sGj);
	void insertTestToDB();

public:
	ITests();
	
	void getAllTests();
	void setAllTests();
	//void getGroupsTest();
	
	//void setGrTest(GroupTest& val);

	std::vector<GroupTest>& getGrTest();

	void getGroupTest(bool tline = 1);
	void fillArrTests();

	//~ITests();
};

#endif // !ITESTS_H
