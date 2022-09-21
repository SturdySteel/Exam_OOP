#ifndef TESTLINE_H
#define TESTLINE_H
#include <string>

class TestLine
{
private:
//public:
	int numQ;
	std::string question;
	std::string answer01;
	std::string answer02;
	std::string answer03;
	std::string answer04;
	int rightAnswer;

public:
	TestLine();	
	//TestLine(TestLine& line);
	
	void setNumQ(int numQ);
	void setQuestion(std::string question);
	void setAnswer01(std::string answer01);
	void setAnswer02(std::string answer02);
	void setAnswer03(std::string answer03);
	void setAnswer04(std::string answer04);
	void setRightAnswer (int rightAnswer);

	int getNumQ();
	std::string getQuestion();
	std::string getAnswer01();
	std::string getAnswer02();
	std::string getAnswer03();
	std::string getAnswer04();
	int getRightAnswer();

	TestLine& getLine();

};

#endif // !TESTLINE_H
