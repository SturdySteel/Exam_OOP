#ifndef TEST_H
#define TEST_H
#include <string>
#include <vector>
#include "TestLine.h"

class Test
{
//public:
	int numTest;
	std::string nameTest;
	std::string tableNameTest;
	int countQuestions;	
	std::vector<TestLine> arrTest;
	
public:
	Test();

	void setTestLine(TestLine* line);
	
	void setNumTest(int numTest);
	void setNameTest(std::string nameTest);
	void setTableNameTest(std::string tableNameTest);
	void setCountQuestions(int countQuestions);
	//void setTests(Test& val);

	int getNumTest();
	std::string getNameTest();
	std::string getTableNameTest();
	int getCountQuestions();

	Test& getTest();
	std::vector<TestLine>& getArrTest();
	//~Test();
};

#endif // !TEST_H
