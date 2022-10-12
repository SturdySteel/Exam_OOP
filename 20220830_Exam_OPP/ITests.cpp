#include "ITests.h"

//ITests::ITests() :	
//	grTest{ new GroupTest },
//	subGrTest{ new SubGroupTest },
//	test{ new Test }
//	//testLine{ new TestLine }
//	//allTests{ new std::vector<GroupsTests> }
//{}

//ITests::~ITests()
//{
//	if (grTest != nullptr)
//		delete grTest;
//	if (subGrTest != nullptr)
//		delete subGrTest;
//	if (test != nullptr)
//		delete test;
//	/*if (testLine != nullptr)
//		delete testLine;*/
//	/*if (allTests != nullptr)
//		delete allTests;*/
//}


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
	int j{-1},k{-1};
	std::string	query{};
	std::string str;
	std::regex rgX;
	bool find{ false };
	
	//Group
	GroupTest* grTest{ new GroupTest };
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название группы тестов: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	if (arrTests.size() > 0)
		for (int i{}; i < arrTests.size(); ++i)
			if (arrTests[i].getNameGroup() == str)
			{
				j = i; 
				find = true; 
				break;
			}
	
	if (!find) 
	{
		setIgrTest(grTest, str); 
		++j;
	}
		
	//SubGroup
	find = false;
	auto sGj = arrTests[j].getSubGrTest();
	SubGroupTest* subGrTest{ new SubGroupTest };
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название подгруппы тестов: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	
	if(sGj.size()>0)
		for (int i{}; i < sGj.size(); ++i)
			if(sGj[j].getNameGroupTest() == str)
			{				
				k = i;
				find = true;
				break;
			}
	if (!find)
	{
		setIsubGrTest(subGrTest, str, sGj);
		++k;
	}
	

	//Test
	find = false;
	auto testK = sGj[k].getTests();
	Test* test{ new Test };
	rgX = "(\[A-яа-€A-Za-z0-9]{4,})";
	str = dataEd->inputStr("¬ведите название теста: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	test->setNameTest(str);
	int numTest = db->getMaxID(test->getTableNameTest(), "numTest");
	if (numTest == -1)
	{ /* need create table */ }
	else
		test->setNumTest(numTest);
	test->setTableNameTest(dataEd->translitStr(str) + std::to_string(numTest));
	rgX = R"(\d{1,})";
	int countQuestions = std::stoi(dataEd->inputStr("¬ведите колличество вопросов теста: ", rgX, 0));
	test->setCountQuestions(countQuestions);
	
	for (size_t i{}; i < countQuestions; ++i)
	{
		test->setTestLine(setTest(i));
		system("cls");
	}

	testK.push_back(*test);

	delete grTest;
	delete subGrTest;
	delete test;
}

TestLine* ITests::setTest(int i)
{	
	//QueryDB* db = QueryDB::getInstance();
	//std::string	query{};
	TestLine* tL{ new TestLine };
	DataEdit* dataEd = DataEdit::getInstance();	
	std::string str;	
	std::regex rgX; // { R"(\w{5,})" };	
	tL->setNumQ(i);	
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

void ITests::setIgrTest(GroupTest*& grTest, std::string str)
{
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	grTest->setNameGroup(str);
	grTest->setTableName(dataEd->translitStr(str));
	grTest->setCountTest(0);
	int idGrTest = db->getMaxID(grTest->getTableName(), "idGrTest");
	if (idGrTest == -1)
	{ 
		/* need create table */
	}
	else
		grTest->setIdGrTest(idGrTest);

	arrTests.push_back(*grTest);		
}

void ITests::setIsubGrTest(SubGroupTest*& subGrTest, std::string str, auto& sGj)
{
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	subGrTest->setNameGroupTest(str);
	subGrTest->setTableGroupTest(dataEd->translitStr(str));
	int numGrTest = db->getMaxID(subGrTest->getTableGroupTest(), "numGrTest");
	if (numGrTest == -1)
	{ 
		/*need create table*/
	}
	else
		subGrTest->setNumGrTest(numGrTest);

	sGj.push_back(*subGrTest);	
}

void ITests::insertTestToDB(GroupTest* grTest)
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;
	for (auto i : arrTests)
	{
		db->createGroupTest(i.getTableName());
		for (auto j : i.getSubGrTest())
		{
			db->createSubGroupTest(j.getTableGroupTest());
			for (auto k : j.getTests())
			{
				db->createTest(k.getTableNameTest());
				for (auto l : k.getArrTest())
				{

				}
			}

		}
	}

}

//void ITests::setGrTest(GroupTest& val) 
//{
//	this->arrTests.push_back(val);
//}

std::vector<GroupTest>& ITests::getGrTest() 
{
	return this->arrTests;
}

ITests& ITests::getGroupTest() 
{	
	for (auto i : arrTests)
	{
		std::cout << "idGrTest = " << i.getIdGrTest() << " ";
		std::cout << "nameGroup = " << i.getNameGroup() << " ";
		std::cout << "countTest = " << i.getCountTest() << " ";
		std::cout << "tableName = " << i.getTableName() << "\n";
		for (auto j : i.getSubGrTest())
		{
			std::cout << "numGrTest = " << j.getNumGrTest() << " ";			
			std::cout << "nameGroupTest = " << j.getNameGroupTest() << " ";
			std::cout << "tableGroupTest = " << j.getTableGroupTest() << "\n";
			for (auto k : j.getTests())
			{
				std::cout << "numTest = " << k.getNumTest() << " ";
				std::cout << "nameTest = " << k.getNameTest() << " ";
				std::cout << "tableNameTest = " << k.getTableNameTest() << " ";
				std::cout << "countQuestions = " << k.getCountQuestions() << "\n";
				for (auto l : k.getArrTest())
				{
					std::cout << "\n" << "Ќазвание теста: " << k.getNameTest() << std::endl;
					std::cout << l.getNumQ() << "." << l.getQuestion() << ":";
					std::cout << "\n¬арианты:\n1: " << l.getAnswer01() << "\n2: "
						<< l.getAnswer02() << "\n3: " << l.getAnswer03()
						<< "\n4: " << l.getAnswer04() << "\n" << "Right: " << l.getRightAnswer() << std::endl;
				}
			}
		}
	}
 
	return *this;
}

