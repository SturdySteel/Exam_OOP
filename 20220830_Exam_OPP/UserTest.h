#ifndef USERTEST_H
#define USERTEST_H
#include <vector>

struct DataTest {
	int num;			// ����� � ������� ��������� ������
	int groupNum;		// ����� ������ ������
	int subGroupNum;	// ����� ��������� ������
	int testNum;		// ����� �����
	int countAnswers;	// ����������� ��������� ��������
	int countRightAns;	// ����������� ���������� 
	int countTry;		// ����������� ������� �����
	bool passed;		// ������/��������
};

class UserTest
{
protected:
	int id;
	int count{};
	std::vector<DataTest> dataT;
	
public:
	UserTest(int id, int num, int groupNum, int subGroupNum, int testNum,
		int countAnswers, int countRightAns, int countTry, bool passed); 
	
	int getCount();

	~UserTest();
};

#endif // !USERTEST_H


/*UserTest(int id, int num, int groupNum,	int suGroupNum, int testNum,
		int countAnswers, int countRightAns, int countTry, bool passed) :
		id{id}, num{num},groupNum{groupNum}, subGroupNum{subGroupNum},
		testNum{testNum}, countAnswers{countAnswers}, countRightAns{countRightAns},
		countTry{countTry}, passed{passed}*/
