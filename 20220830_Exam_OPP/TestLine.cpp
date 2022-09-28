#include "TestLine.h"

TestLine::TestLine() :
	numQ{},
	question{},
	answer01{},
	answer02{},
	answer03{},
	answer04{},
	rightAnswer{}
{}

TestLine::TestLine(int numQ, std::string question, std::string answer01, std::string answer02, 
	std::string answer03, std::string answer04, int rightAnswer) :
	numQ{numQ},
	question{ question },
	answer01{ answer01 },
	answer02{ answer02 },
	answer03{ answer03 },
	answer04{ answer04 },
	rightAnswer{ rightAnswer }
{}

void TestLine::setNumQ(int numQ) { this->numQ = numQ; }
void TestLine::setQuestion(std::string question) { this->question = question; }
void TestLine::setAnswer01(std::string answer01) { this->answer01 = answer01; }
void TestLine::setAnswer02(std::string answer02) { this->answer02 = answer02; }
void TestLine::setAnswer03(std::string answer03) { this->answer03 = answer03; }
void TestLine::setAnswer04(std::string answer04) { this->answer04 = answer04; }
void TestLine::setRightAnswer(int rightAnswer) { this->rightAnswer = rightAnswer; }

int TestLine::getNumQ() { return this->numQ; }
std::string TestLine::getQuestion() { return this->question; }
std::string TestLine::getAnswer01() { return this->answer01; }
std::string TestLine::getAnswer02() { return this->answer02; }
std::string TestLine::getAnswer03() { return this->answer03; }
std::string TestLine::getAnswer04() { return this->answer04; }
int TestLine::getRightAnswer() { return this->rightAnswer; }
	
TestLine& TestLine::getLine() { return *this; }
