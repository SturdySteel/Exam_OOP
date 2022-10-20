#include "ITests.h"

int ITests::counter = 0;

ITests::ITests()	//need uncomment !!!!
{
	QueryDB* db = QueryDB::getInstance();
	ITests::counter = db->getCountTest();		
}

void ITests::getAllTests()
{
	QueryDB* db = QueryDB::getInstance();
	std::string	select;
		
	sqlite3_stmt* stmt{ nullptr };
	select = "SELECT * FROM tableGroupsTests;";	
	stmt = db->selectSQL(select);
	if (sqlite3_column_int(stmt, 0) == 0)
		return;
	do {
		std::cout << sqlite3_column_int(stmt, 0) <<"  "
			<< reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) << std::endl;
			/*<< "  " << sqlite3_column_int(stmt, 2) << "  "
			<< (sqlite3_column_text(stmt, 3)) << " \n ";*/
		
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
	rgX = "(\[A-яа-€A-Za-z ]{5,})";
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
		
		int idGrTest{ db->getMaxID("tableGroupsTests", "idGrTest") };
		if (idGrTest == 0) 
			idGrTest = arrTests.size();

		grTest->setCountTest(1);
		grTest->setIdGrTest(idGrTest);

		arrTests.push_back(*grTest);
		++j;		
	}
			
	//----SubGroup-----	
	SubGroupTest* subGrTest{ new SubGroupTest };
	rgX = "(\[A-яа-€A-Za-z ]{5,})";
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

		int numGrTest{ db->getMaxID(arrTests[j].getTableName(), "numGrTest") };
		if(numGrTest == -1)
			numGrTest =  arrTests[j].getArrSubGrTest().size();

		subGrTest->setNumGrTest(numGrTest);

		arrTests[j].getArrSubGrTest().push_back(*subGrTest);
		++k;
	}
	
	//-----Test-----
	//find = false;	
	Test* test{ new Test };
	rgX = "(\[A-яа-€A-Za-z0-9 ]{4,})";
	str = dataEd->inputStr("¬ведите название теста: ", rgX, 0);
	std::transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
	test->setNameTest(str);
	str = dataEd->translitStr(str);
	int numTest{ (db->getMaxID(arrTests[j].getArrSubGrTest().at(k).getTableGroupTest(), "numTest"))};
		numTest = arrTests[j].getArrSubGrTest().at(k).getArrTests().size();
	
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

	insertTestToDB();
	
	delete grTest;
	delete subGrTest;
	delete test;
}

TestLine* ITests::setTest(int i)
{		
	TestLine* tL{ new TestLine };
	DataEdit* dataEd = DataEdit::getInstance();	
	std::string str;	
	std::regex rgX; // { R"(\w{5,})" };	
	tL->setNumQ(i);	
	rgX = "(\[A-яа-€A-Za-z0-9 ]{5,})";
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


void ITests::insertTestToDB()
{
	if (arrTests.empty())
		return;

	QueryDB* db = QueryDB::getInstance();
	//std::string	select;

	for (auto i : arrTests)
	{	
		db->insertTableGroupsTests(i.getNameGroup(), i.getCountTest(), i.getTableName());
		db->createGroupTest(i.getTableName());

		for (auto j : i.getArrSubGrTest())
		{
			db->insertTableGroupTest(i.getTableName(), j.getNameGroupTest(), j.getTableGroupTest());
			db->createSubGroupTest(j.getTableGroupTest());
			for (auto k : j.getArrTests())
			{
				db->insertTableSubGroupTest(j.getTableGroupTest(), k.getNameTest(),
					k.getTableNameTest(), k.getCountQuestions());
				db->createTest(k.getTableNameTest());
				for (auto l : k.getArrTestLines())
				{
					db->insertTableTests(k.getTableNameTest(),
						l.getQuestion(), l.getAnswer01(), l.getAnswer02(),
						l.getAnswer03(), l.getAnswer04(), l.getRightAnswer());
				}
			}
		}
	}
	arrTests.clear();
}

//void ITests::setGrTest(GroupTest& val) 
//{
//	this->arrTests.push_back(val);
//}

std::vector<GroupTest>& ITests::getGrTest() 
{
	return this->arrTests;
}

void ITests::getGroupTest(bool tline) 
{	
	/*if (arrTests.empty())
		return;*/
	fillArrTests();

	for (auto &i : arrTests)
	{
		std::cout << "idGrTest = " << i.getIdGrTest() << " ";
		std::cout << "nameGroup = " << i.getNameGroup() << " ";
		std::cout << "countTest = " << i.getCountTest() << " ";
		std::cout << "tableName = " << i.getTableName() << "\n";
		for (auto &j : i.getArrSubGrTest())
		{
			std::cout << "\n numGrTest = " << j.getNumGrTest() << " ";			
			std::cout << " nameGroupTest = " << j.getNameGroupTest() << " ";
			std::cout << " tableGroupTest = " << j.getTableGroupTest() << "\n";
			for (auto &k : j.getArrTests())
			{
				std::cout << "\n  numTest = " << k.getNumTest() << " ";
				std::cout << "  nameTest = " << k.getNameTest() << " ";
				std::cout << "  tableNameTest = " << k.getTableNameTest() << " ";
				std::cout << "  countQuestions = " << k.getCountQuestions() << "\n";

				std::cout << "\n" << "  Ќазвание теста: " << k.getNameTest() << std::endl;
				if (tline)
					for (auto &l : k.getArrTestLines())
					{
						std::cout << "   " << l.getNumQ() << "." << l.getQuestion() << "";
						std::cout << "\n    ¬арианты:\n    1: " << l.getAnswer01() << "\n    2: "
							<< l.getAnswer02() << "\n    3: " << l.getAnswer03()
							<< "\n    4: " << l.getAnswer04() << "\n" 
							/* << "   Right: " << l.getRightAnswer() << "\n"*/ 
							<< std::endl;
					}
			}
		}
		std::cout << "======================================================" << std::endl;
	} 
	//return *this;
}

void ITests::fillArrTests()
{
	this->arrTests.clear();
	QueryDB* db = QueryDB::getInstance();
	DataEdit* dataEd = DataEdit::getInstance();
	sqlite3_stmt* stmt{ nullptr };
	std::string	select;
	
	GroupTest* grTest{ new GroupTest };
	SubGroupTest* subGrTest{ new SubGroupTest };
	Test* test{ new Test };
	TestLine* tL{ new TestLine };

	select = "SELECT * FROM tableGroupsTests;";
	stmt = db->selectSQL(select);
	do {
		grTest->setIdGrTest(sqlite3_column_int(stmt, 0));
		grTest->setNameGroup(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		grTest->setCountTest(sqlite3_column_int(stmt, 2));
		grTest->setTableName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		arrTests.push_back(*grTest);
	} while (sqlite3_step(stmt) != SQLITE_DONE);
	sqlite3_finalize(stmt);

	for (auto &i : arrTests)
	{
		select = "SELECT * FROM " + i.getTableName() + ";";
		stmt = db->selectSQL(select);
		do {
			subGrTest->setNumGrTest(sqlite3_column_int(stmt, 0));
			subGrTest->setNameGroupTest(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
			subGrTest->setTableGroupTest(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
			i.setSubGrTest(*subGrTest);
		} while (sqlite3_step(stmt) != SQLITE_DONE);
	}
	sqlite3_finalize(stmt);

	for (auto &i : arrTests)
	{
		for (auto &j : i.getArrSubGrTest())
		{
			select = "SELECT * FROM " + j.getTableGroupTest() + ";";
			stmt = db->selectSQL(select);
			do {
				test->setNumTest(sqlite3_column_int(stmt, 0));
				test->setNameTest(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
				test->setTableNameTest(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
				test->setCountQuestions(sqlite3_column_int(stmt, 3));
				j.setTests(*test);
			} while (sqlite3_step(stmt) != SQLITE_DONE);
		}
	}
	sqlite3_finalize(stmt);

	
	for (auto &i : arrTests)
		for (auto &j : i.getArrSubGrTest())
			for (auto &k : j.getArrTests())
			{				
				select = "SELECT * FROM " + k.getTableNameTest() + ";";
				stmt = db->selectSQL(select);
				do {
					tL->setNumQ(sqlite3_column_int(stmt, 0));
					tL->setQuestion(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
					tL->setAnswer01(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
					tL->setAnswer02(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
					tL->setAnswer03(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
					tL->setAnswer04(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
					tL->setRightAnswer(sqlite3_column_int(stmt, 6));
					k.setTestLine(tL);
				} while (sqlite3_step(stmt) != SQLITE_DONE);			
			}
	sqlite3_finalize(stmt);

	delete grTest;
	delete subGrTest;
	delete test;
	delete tL;
}

