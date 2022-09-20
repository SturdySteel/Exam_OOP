#ifndef GROUPSTESTS_H
#define GROUPSTESTS_H
#include <string>
#include <array>
#include <vector>

class GroupsTests
{
public:
//private:
	int idGrTest;
	std::string nameGroup;
	std::string tableName;
	int countTest;
	//std::vector<GroupTest> grTest;

public:

};

class GroupTest
{
public:
//private:
	int numGroupTest;
	std::string nameGroupTest;
	std::string tableGroupTest;
	//std::vector<SubGroupTest> subGrTest;

public:

};

class SubGroupTest
{
public:
//private:
	int numTest;
	std::string nameTest;
	std::string tableNameTest;
	int countQuestions;
	//std::vector<Test> tests;

public:
};

class Test
{
public:
//private:
	//std::array<TestLine, 20> arrTest;
	
public:

};

class TestLine
{
public:
	int numQ;
	std::string question;
	std::string answer01;
	std::string answer02;
	std::string answer03;
	std::string answer04;
	std::string rightAnswer;
};
#endif // !GROUPSTESTS_H
