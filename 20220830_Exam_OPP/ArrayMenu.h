#ifndef ARRAYMENU_H
#define ARRAYMENU_H
//#include <string>
//#include <vector>

std::vector<std::string> mainMenu 
{	
	"�����������",
	"�����������",
	"�����" 
};

std::vector<std::string> adminMenu
{
	"������������",
	"�����",
	"�������"
};

std::vector<std::string> admUsersMenu 
{
	"��������",
	"�������������",
	"��������",
	"�������"
};

std::vector<std::string> admTestsMenu
{
	"��������",
	"�������������",
	"��������"
	"�������"
};


std::vector<std::string> userMenu
{
	"�������� �����",
	"������� ����",
	"�������"
};

std::vector<std::vector<std::string>> admMenuArr
{
	adminMenu,
	admUsersMenu,
	admTestsMenu
};

std::vector<std::vector<std::string>> userMenuArr
{
	userMenu
};

//std::vector<std::string> userTestsMenu
//{
//	"�������� ������",
//	"",
//	"�������"
//};

//class ShowMenu
//{
//private:
//	std::vector<std::string> menu;
//	bool mainM;
//
//public:
//	ShowMenu(std::vector<std::string> menu, bool mainM = false) :
//		menu{ menu },
//		mainM{ mainM }
//	{}
//
//	void menu(std::vector<std::string> menu);
//	
//};


#endif // !ARRAYMENU_H
