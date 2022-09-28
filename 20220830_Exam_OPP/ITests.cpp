#include "ITests.h"

ITests::ITests() :
	grTests{ new GroupsTests },
	grTest{ new GroupTest },
	subGrTest{ new SubGroupTest },
	test{ new Test }
	//tesLine{ new TestLine },
	//allTests{ new std::vector<GroupsTests> }
{}

ITests::~ITests()
{
	if (grTests != nullptr)
		delete grTests;
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
	std::cout << str << "\n";
	grTests->setNameGroup(str);
	rgX= R"(\w{5,})";
	grTests->setTableName(dataEd->inputStr("¬ведите название таблицы группы тестов (en): ", rgX, 0));
	std::cout << grTests->getNameGroup() << " " << grTests->getTableName();
	allTests.push_back(*grTests);
	grTests = new GroupsTests;
}

void ITests::getGroupsTest()
{
	if(grTests != nullptr)
		std::cout << grTests->getNameGroup() << " " << grTests->getTableName() << "\n";
	if(allTests.size() != 0)
		std::cout << allTests[0].getNameGroup() << "\n";
}


