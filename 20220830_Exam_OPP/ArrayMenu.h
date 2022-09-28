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
	"Добавить",
	"Возврат"
};


std::vector<std::string> userMenu
{
	"Пользователь инфо",
	"Пользователь тесты",
	"Возврат"
};

std::vector<std::string> userUserMenu
{
	"Просмотр пользователя",
	"Редактировать пользователя",	
	"Возврат"
};

std::vector<std::string> userTestsMenu
{
	"Просмотр/выбор тестов",
	"Результаты",
	"Возврат"
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
