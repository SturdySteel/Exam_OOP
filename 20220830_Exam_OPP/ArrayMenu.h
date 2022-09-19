#ifndef ARRAYMENU_H
#define ARRAYMENU_H
//#include <string>
//#include <vector>

std::vector<std::string> mainMenu 
{	
	"Авторизация",
	"Регистрация",
	"Выход" 
};

std::vector<std::string> adminMenu
{
	"Пользователи",
	"Тесты",
	"Возврат"
};

std::vector<std::string> admUsersMenu 
{
	"Просмотр",
	"Редактировать",
	"Добавить",
	"Возврат"
};

std::vector<std::string> admTestsMenu
{
	"Просмотр",
	"Редактировать",
	"Добавить"
	"Возврат"
};


std::vector<std::string> userMenu
{
	"Просмотр теста",
	"Выбрать тест",
	"Возврат"
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
//	"Просмотр тестов",
//	"",
//	"Возврат"
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
