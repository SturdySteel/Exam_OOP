#include "UserTest.h"

int UserTest::getCount()
{
    return this->count;
}

UserTest::~UserTest()
{
    dataT.clear();
    count = 0;
}

UserTest::UserTest(int id, int num, int groupNum, int subGroupNum, int testNum, 
	int countAnswers, int countRightAns, int countTry, bool passed) :
	id{ id }
{
	dataT[count].num = num;
	dataT[count].groupNum = groupNum;
	dataT[count].subGroupNum = subGroupNum;
	dataT[count].testNum = testNum;
	dataT[count].countAnswers = countAnswers;
	dataT[count].countRightAns = countRightAns;
	dataT[count].countTry = countTry;
	dataT[count].passed = passed;
	++count;
}
