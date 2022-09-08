#ifndef USERTEST_H
#define USERTEST_H

class UserTest
{
protected:
	int id;
	int num;			// ����� � ������� ��������� ������
	int groupNum;		//����� ������ ������
	int subGroupNum;	// ����� ��������� ������
	int testNum;		// ����� �����
	int countAnswers;	// ����������� ��������� ��������
	int countRightAns;	// ����������� ���������� 
	int countTry;		// ����������� ������� �����
	bool passed;		// ������/��������
	
public:
	UserTest(int id, int num, int groupNum,	int suGroupNum, int testNum, 
		int countAnswers, int countRightAns, int countTry, bool passed) :
		id{id}, num{num},groupNum{groupNum}, subGroupNum{subGroupNum},
		testNum{testNum}, countAnswers{countAnswers}, countRightAns{countRightAns},
		countTry{countTry}, passed{passed}
	{}

};

#endif // !USERTEST_H
