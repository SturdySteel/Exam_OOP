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
	"��������",
	"�������"
};


std::vector<std::string> userMenu
{
	"������������ ����",
	"������������ �����",
	"�������"
};

std::vector<std::string> userUserMenu
{
	"�������� ������������",
	"������������� ������������",	
	"�������"
};

std::vector<std::string> userTestsMenu
{
	"��������/����� ������",
	"����������",
	"�������"
};

std::vector<std::vector<std::string>*> admMenuArr
{
	&adminMenu,
	&admUsersMenu,
	&admTestsMenu
};

std::vector<std::vector<std::string>*> userMenuArr
{
	&userMenu,
	&userUserMenu,
	&userTestsMenu,

};

#endif // !ARRAYMENU_H
