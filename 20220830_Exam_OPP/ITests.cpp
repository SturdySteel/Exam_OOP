#include "ITests.h"

ITests::ITests() :	
	grTest{ new GroupTest },
	subGrTest{ new SubGroupTest },
	test{ new Test },
	testLine{ new TestLine }
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
	if (testLine != nullptr)
		delete testLine;
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
	
}

void ITests::setAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	std::string	query{};
	std::string str;
	std::regex rgX;
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название группы тестов: ", rgX, 0);
	grTest->setNameGroup(str);
	//rgX= R"(\w{5,})";
	//str = dataEd->inputStr("¬ведите название таблицы группы тестов (en): ", rgX, 1);
	 
	grTest->setTableName(dataEd->translitStr(str));
	grTest->setCountTest(0);
	int idGrTest = db->getMaxID(grTest->getTableName(), "idGrTest");
	if (idGrTest == -1)
	{
		//need create table
	}
	else
		grTest->setIdGrTest(idGrTest);
	
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название подгруппы тестов: ", rgX, 0);
	subGrTest->setNameGroupTest(str);
	subGrTest->setTableGroupTest(dataEd->translitStr(str));
	int numGrTest = db->getMaxID(subGrTest->getTableGroupTest(), "numGrTest");
	if (numGrTest == -1)
	{
		//need create table
	}
	else
		subGrTest->setNumGrTest(numGrTest);

	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название теста: ", rgX, 0);
	test->setNameTest(str);	
	int numTest = db->getMaxID(test->getTableNameTest(), "numTest");
	if (numTest == -1)
	{
		//need create table
	}
	else
		test->setNumTest(numTest);
	test->setTableNameTest(dataEd->translitStr(str)+std::to_string(numTest));
	rgX = R"(\d{1,})";
	int countQuestions = std::stoi(dataEd->inputStr("¬ведите колличество вопросов теста: ", rgX, 0));
	test->setCountQuestions(countQuestions);
	
	for (size_t i{}; i < countQuestions; ++i)
	{
		test->setTestLine(setTest(i));
		system("cls");
	}

	arrTests.push_back(*grTest);
	//grTests = new GroupsTests;
}

TestLine* ITests::setTest(int i)
{	
	//QueryDB* db = QueryDB::getInstance();
	//std::string	query{};
	TestLine* tL{new TestLine};
	DataEdit* dataEd = DataEdit::getInstance();	
	std::string str;	
	std::regex rgX; // { R"(\w{5,})" };	
	testLine->setNumQ(i);
	//rgX = "(\[A-яа-€A-Za-z0-9]{5,})";
	rgX = "(\[A-яа-€A-Za-z0-9]{5,})";
	str = dataEd->inputStr("¬ведите вопрос " + std::to_string(i+1) + " теста : ", rgX, 0);
	tL->setQuestion(str);
	str = dataEd->inputStr("¬ведите ответ 1: ", rgX, 1);
	tL->setAnswer01(str);
	str = dataEd->inputStr("¬ведите ответ 2: ", rgX, 2);
	tL->setAnswer02(str);
	str = dataEd->inputStr("¬ведите ответ 3: ", rgX, 3);
	tL->setAnswer03(str);
	str = dataEd->inputStr("¬ведите ответ 4: ", rgX, 4);
	tL->setAnswer04(str);
	rgX = R"(\d{1})";
	tL->setRightAnswer(std::stoi(dataEd->inputStr("¬ведите правильный ответ: ", rgX, 5)));

	return tL;
}

void ITests::setGrTest(GroupTest& val) {
	this->arrTests.push_back(val);
}

std::vector<GroupTest>& ITests::getGrTest() {
	return this->arrTests;
}

ITests& ITests::getGroupTest() 
{	
	std::cout << "idGrTest = " << this->grTest->getIdGrTest();// << "\n";
	std::cout << "nameGroup = " << this->grTest->getNameGroup();// << "\n";
	std::cout << "countTest = " << this->grTest->getCountTest();// << "\n";
	std::cout << "tableName = " << this->grTest->getTableName() << "\n";

	std::cout << "numGrTest = " << this->subGrTest->getNumGrTest();
	std::cout << "nameGroupTest = " << this->subGrTest->getNameGroupTest();
	std::cout << "tableGroupTest = " << this->subGrTest->getTableGroupTest() << "\n";

	std::cout << "numTest = " << this->test->getNumTest();
	std::cout << "nameTest = " << this->test->getNameTest();
	std::cout << "tableNameTest = " << this->test->getTableNameTest();
	std::cout << "countQuestions = " << this->test->getCountQuestions() << "\n";
 
	return *this;
}

