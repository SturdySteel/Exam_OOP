#include "ITests.h"

ITests::ITests() :
	allTests{ new std::vector<GroupsTests> }
{}

void ITests::getAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;
		
	/*std::string nameGroupS{ "Астрономия2" }, tableNameS{ "astro0003" };
	int countTestS{ 4 };
	
	select = "INSERT INTO tableGroupsTests(nameGroup, countTest, tableName) VALUES('"
		+ nameGroupS + "', '" + std::to_string(countTestS) + "', '" + tableNameS + "');";
	db->querySQL(select);*/
	
	sqlite3_stmt* stmt{ nullptr };
	select = "SELECT * FROM tableGroupsTests;";	
	stmt = db->selectSQL(select);

	//std::ofstream fout("test.txt", std::ios::app);
	std::string s = (reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
	//setlocale(LC_ALL,"ru_RU.UTF-8");
	//setlocale(LC_ALL, "cp1251");
	do {
		std::cout << sqlite3_column_int(stmt, 0) << "  "
			<< reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
			<< "  " << sqlite3_column_int(stmt, 2) << "  "
			<< (sqlite3_column_text(stmt, 3)) << " \n ";

		//std::cout << reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))<<"\n";

	} while (sqlite3_step(stmt) != SQLITE_DONE);
	//setlocale(LC_ALL, "ru");
	sqlite3_finalize(stmt);

	//fout.close();
	
}

//void ITests::setAllTest()
//{
//	QueryDB* db = QueryDB::getInstance();
//	std::string	query{};
//
//	std::string nameGroupTest;
//
//	std::cout << "Введите название группы тестов " << "\n";
//	std::cin >> nameGroupTest;
//}

ITests::~ITests() 
{
	if (allTests != nullptr)
		delete allTests;
}

