#ifndef USERTEST_H
#define USERTEST_H

class UserTest
{
protected:
	int id;
	int num;			// номер в таблице пройденых тестов
	int groupNum;		//номер группы тестов
	int subGroupNum;	// номер подгруппы тестов
	int testNum;		// номер теста
	int countAnswers;	// колличество пройденых вопросов
	int countRightAns;	// колличество правильных 
	int countTry;		// колличество попыток теста
	bool passed;		// прошел/непрошел
	
public:
	UserTest(int id, int num, int groupNum,	int suGroupNum, int testNum, 
		int countAnswers, int countRightAns, int countTry, bool passed) :
		id{id}, num{num},groupNum{groupNum}, subGroupNum{subGroupNum},
		testNum{testNum}, countAnswers{countAnswers}, countRightAns{countRightAns},
		countTry{countTry}, passed{passed}
	{}

};

#endif // !USERTEST_H
