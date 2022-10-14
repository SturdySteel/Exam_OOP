#include "ITests.h"

int ITests::counter = 0;

//grTest{ new GroupTest },
	//subGrTest{ new SubGroupTest },
	//test{ new Test }
	//testLine{ new TestLine }
	//allTests{ new std::vector<GroupsTests> }

ITests::ITests()	//need uncomment !!!!
{
	QueryDB* db = QueryDB::getInstance();
	ITests::counter = db->getCountTest();	
}

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
	int j{ (arrTests.size() > 0) ? (int)(arrTests.size() - 1) : -1 };
	int k{ -1 };
	std::string	query{};
	std::string str;
	std::regex rgX;
	bool find{ false }, subFind{false};
	
	//----Group----
	GroupTest* grTest{ new GroupTest };
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название группы тестов: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	if (arrTests.size() > 0)
		for (int i{}; i < arrTests.size(); ++i)
			if (arrTests[i].getNameGroup() == str)
			{
				j = i;
				arrTests[j].setCountTest((arrTests[j].getCountTest()) + 1);
				find = true; 
				break;
			}
	
	if (!find) 
	{
		grTest->setNameGroup(str);
		grTest->setTableName(dataEd->translitStr(str));
		
		int idGrTest = db->getMaxID("tableGroupsTests", "idGrTest"); 
		idGrTest = (idGrTest == -1) ? 1 : ++idGrTest;

		//grTest->setCountTest(1);
		grTest->setIdGrTest(idGrTest);

		arrTests.push_back(*grTest);
		++j;		
	}
			
	//----SubGroup-----	
	SubGroupTest* subGrTest{ new SubGroupTest };
	rgX = "(\[A-яа-€A-Za-z]{5,})";
	str = dataEd->inputStr("¬ведите название подгруппы тестов: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	if (find)
	{
		if (arrTests[j].getArrSubGrTest().size() > 0)
			for (int i{}; i < arrTests[j].getArrSubGrTest().size(); ++i)			
				if (arrTests[j].getArrSubGrTest().at(i).getNameGroupTest() == str)
				{
					k = i;
					find = true;
					subFind = true;
					break;
				}
		k = arrTests[j].getArrSubGrTest().size() - 1;
	}	
	
	if (!find || !subFind)
	{
		subGrTest->setNameGroupTest(str);
		subGrTest->setTableGroupTest(dataEd->translitStr(str));

		int numGrTest = db->getMaxID(arrTests[j].getTableName(), "numGrTest");
		numGrTest = numGrTest == -1 ? 1 : ++numGrTest;

		subGrTest->setNumGrTest(numGrTest);

		arrTests[j].getArrSubGrTest().push_back(*subGrTest);
		++k;
	}
	
	//-----Test-----
	//find = false;	
	Test* test{ new Test };
	rgX = "(\[A-яа-€A-Za-z0-9]{4,})";
	str = dataEd->inputStr("¬ведите название теста: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	test->setNameTest(str);
	str = dataEd->translitStr(str);
	int numTest{ (db->getMaxID(arrTests[j].getArrSubGrTest().at(k).getTableGroupTest(), "numTest"))};
	if ( numTest == -1 )
	{ 
		numTest = arrTests[j].getArrSubGrTest().at(k).getNumGrTest();
		if (find)
			++numTest;			
	}	
	
	test->setNumTest(numTest);
	test->setTableNameTest(str+std::to_string(ITests::counter++));
	
	rgX = R"(\d{1,})";
	int countQuestions = std::stoi(dataEd->inputStr("¬ведите колличество вопросов теста: ", rgX, 0));
	test->setCountQuestions(countQuestions);
	//ITests::counter += countQuestions-1;

	for (int i{}; i < countQuestions; ++i)
	{
		test->setTestLine(setTest(i));
		system("cls");
	}
	
	arrTests[j].getArrSubGrTest().at(k).getArrTests().push_back(*test);
	
	delete grTest;
	delete subGrTest;
	delete test;
}

//db->createGroupTest(grTest->getTableName());
//db->insertTableGroupsTest(grTest->getNameGroup(), grTest->getCountTest(), grTest->getTableName());
//idGrTest = db->getMaxID("tableGroupsTests", "idGrTest");

TestLine* ITests::setTest(int i)
{		
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
	rgX = "(\[1-4]{1})";
	tL->setRightAnswer(std::stoi(dataEd->inputStr("¬ведите правильный ответ: ", rgX, 5)));

	return tL;
}


void ITests::insertTestToDB(GroupTest* grTest)
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;
	for (auto i : arrTests)
	{
		db->createGroupTest(i.getTableName());
		for (auto j : i.getArrSubGrTest())
		{
			db->createSubGroupTest(j.getTableGroupTest());
			for (auto k : j.getArrTests())
			{
				db->createTest(k.getTableNameTest());
				for (auto l : k.getArrTestLines())
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

void ITests::getGroupTest() 
{	
	if (arrTests.empty())
		return;
	
	for (auto i : arrTests)
	{
		std::cout << "idGrTest = " << i.getIdGrTest() << " ";
		std::cout << "nameGroup = " << i.getNameGroup() << " ";
		std::cout << "countTest = " << i.getCountTest() << " ";
		std::cout << "tableName = " << i.getTableName() << "\n";
		for (auto j : i.getArrSubGrTest())
		{
			std::cout << " numGrTest = " << j.getNumGrTest() << " ";			
			std::cout << " nameGroupTest = " << j.getNameGroupTest() << " ";
			std::cout << " tableGroupTest = " << j.getTableGroupTest() << "\n";
			for (auto k : j.getArrTests())
			{
				std::cout << "\n  numTest = " << k.getNumTest() << " ";
				std::cout << "  nameTest = " << k.getNameTest() << " ";
				std::cout << "  tableNameTest = " << k.getTableNameTest() << " ";
				std::cout << "  countQuestions = " << k.getCountQuestions() << "\n";

				std::cout << "\n" << "  Ќазвание теста: " << k.getNameTest() << std::endl;
				for (auto l : k.getArrTestLines())
				{					
					std::cout << l.getNumQ() << "." << l.getQuestion() << ":";
					std::cout << "\n   ¬арианты:\n   1: " << l.getAnswer01() << "\n   2: "
						<< l.getAnswer02() << "\n   3: " << l.getAnswer03()
						<< "\n   4: " << l.getAnswer04() << "\n" << "   Right: " 
						<< l.getRightAnswer() <<"\n" << std::endl;
				}
			}
		}
	}
 
	//return *this;
}

