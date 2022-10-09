#include "ITests.h"

ITests::ITests() :	
	grTest{ new GroupTest },
	subGrTest{ new SubGroupTest },
	test{ new Test },
	tesLine{ new TestLine }
	//allTests{ new std::vector<GroupsTests> }
{}

ITests::~ITests()
{
	if (grTest != nullptr)
		delete grTest;
	if (subGrTest != nullptr)
		delete subGrTest;
	if (test != nullptr)
		delete test;
	if (tesLine != nullptr)
		delete tesLine;
	/*if (allTests != nullptr)
		delete allTests;*/
}


void ITests::getAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;
		
	/*std::string nameGroupS{ "јстрономи€2" }, tableNameS{ "astro0003" };
	int countTestS{ 4 };
	
	select = "INSERT INTO tableGroupsTests(nameGroup, countTest, tableName) VALUES('"
		+ nameGroupS + "', '" + std::to_string(countTestS) + "', '" + tableNameS + "');";
	db->querySQL(select);*/
	
	sqlite3_stmt* stmt{ nullptr };
	select = "SELECT * FROM tableGroupsTests;";	
	stmt = db->selectSQL(select);
	if (sqlite3_column_int(stmt, 0) == 0)
		return;
	do {
		std::cout << sqlite3_column_int(stmt, 0) << "  "
			<< reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
			<< "  " << sqlite3_column_int(stmt, 2) << "  "
			<< (sqlite3_column_text(stmt, 3)) << " \n ";
		
	} while (sqlite3_step(stmt) != SQLITE_DONE);
	
	sqlite3_finalize(stmt);

	//fout.close();
	
}

void ITests::setAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	std::string	query{};
	std::string str;
	std::regex rgX{ "(\[A-яа-€A-Za-z]{5,})" };			
	str = dataEd->inputStr("¬ведите название группы тестов (ru/en): ", rgX, 0);
	//grTests->setNameGroup(str);
	rgX= R"(\w{5,})";
	str = dataEd->inputStr("¬ведите название таблицы группы тестов (en): ", rgX, 1);
	//grTests->setTableName(str);
	//grTests->setCountTest(0);

	//grTest->setNameGroupTest();


	//allTests.push_back(*grTests);
	//grTests = new GroupsTests;
}



Test ITests::setTest()
{	
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	std::string	query{};
	std::string str;
	std::regex rgX{ R"(\w{5,})" };
	str = dataEd->inputStr("¬ведите название таблицы теста (en): ", rgX, 0);
	//query = "SELECT tableNameTest FROM ";
	return Test();
}

void ITests::setGrTest(GroupTest& val) {
	this->arrTests.push_back(val);
}

std::vector<GroupTest>& ITests::getGrTest() {
	return this->arrTests;
}

ITests& ITests::getGroupTest() {
	return *this;
}

