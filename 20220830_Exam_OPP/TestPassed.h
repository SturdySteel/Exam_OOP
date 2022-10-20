#ifndef TESTPASSED_H
#define TESTPASSED_H

class TestPassed
{
private:
	int num{};
	int groupNum{};
	int subGroupNum{};
	int testNum{};
	int countAnswers{};
	int countRightAnswers{};
	int countTry{};
	bool passed{};

public:
	TestPassed() {}
	TestPassed(int num, int groupNum, int subGroupNum, int testNum, int countAnswers,
		int countRightAnswers, int countTry, bool passed);

	void setNum(int num);
	void setGroupNum(int groupNum);
	void setSubGroupNum(int	subGroupNum);
	void setTestNum(int testNum);
	void setCountAnswers(int countAnswers);
	void setCountRightAnswers(int countRightAnswers);
	void setCountTry(int countTry);
	void setPassed(bool passed);

	int getNum();
	int getGroupNum();
	int getSubGroupNum();
	int getTestNum();
	int getCountAnswers();
	int getCountRightAnswers();
	int getCountTry();
	bool getPassed();

};

#endif // !TESTPASSED_H
