#include "UserExten.h"

UserExten::UserExten(std::vector<std::vector<std::string>>& menuArr) :
	menuArr{ menuArr }
{}

void UserExten::menu()
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menuArr[0], HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:	usersMenu(); break;
		case 1:	testsMenu(); break;
		case 2:	return;
		default: break;
		}
	}
}

void UserExten::usersMenu()
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menuArr[1], HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:

			break;
		case 1:

			break;
		case 2:

			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void UserExten::testsMenu() 
{
	ITests tst;
	while (true) 	
	{
		system("cls");
		int c = Menu::select_vertical(menuArr[2], HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:
			//listTest();			
			tst.getAllTests();
			system("pause");
			break;
		case 1:

			break;
		case 2:
			//addTest();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}
//void UserExten::switcher(int c)
//{
//
//}
