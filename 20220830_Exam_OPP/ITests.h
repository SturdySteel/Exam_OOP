#ifndef ITESTS_H
#define ITESTS_H
#include <fstream>
#include "GroupsTests.h"
#include "GroupTest.h"
#include "SubGroupTest.h"
#include "Test.h"
#include "TestLine.h"
#include "queryDB.h"
#include <boost/locale.hpp>

class ITests
{
private:
	//std::vector<GroupsTests>* allTests{ nullptr };

public:
	ITests();

	void getAllTests();
	void setAllTest();

	~ITests();
};

#endif // !ITESTS_H
