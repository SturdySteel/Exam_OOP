#include "ITests.h"

void ITests::getAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;

	//std::string nameGroupS{ "Астрономия" }, tableNameS{ "astro" };
	//int countTestS{ 4 };

	//std::string	select = "INSERT INTO tableGroupsTests(nameGroup, countTest, tableName) VALUES('"
	//	+ nameGroupS + "', '" + std::to_string(countTestS) + "', '" + tableNameS + "');";
	//db->querySQL(select);

	sqlite3_stmt* stmt{ nullptr };
	select = "SELECT * FROM tableGroupsTests;";
	
	stmt = db->selectSQL(select);

	//std::ofstream fout("test.txt", std::ios::app);
	//std::string s = sqlite3_column_text(stmt, 3);
	setlocale(LC_ALL,"ru_RU.UTF-8");
	do {
		std::cout << sqlite3_column_int(stmt, 0) << "  "
			<< reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
			<< "  " << sqlite3_column_int(stmt, 2) << "  "
			<< (sqlite3_column_text(stmt, 3)) << " \n ";

			//sqlite3_column_text(stmt, 3);

	} while (sqlite3_step(stmt) != SQLITE_DONE);
	setlocale(LC_ALL, "ru");
	sqlite3_finalize(stmt);

	//fout.close();
	
}
