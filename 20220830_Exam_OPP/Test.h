#ifndef TEST_H
#define TEST_H
#include <string>
#include <vector>
#include "TestLine.h"

class Test
{
//public:
private:
	std::string nameTable;
	std::vector<TestLine> arrTest;
	
public:
	Test();

	void setTestLine(TestLine& line);
	void setNameTab(std::string nameTable);
	Test& getTest();

	//~Test();
};

#endif // !TEST_H
