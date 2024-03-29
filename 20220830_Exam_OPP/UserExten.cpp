#include "UserExten.h"

UserExten::UserExten(std::vector<std::vector<std::string>*> menuArr) :
	menuArr{ menuArr }
{}

void UserExten::menu()
{	
	while (true)
	{		
		system("cls");
		int c = Menu::select_vertical(*menuArr[0], HorizontalAlignment::Left, 0);
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
		int c = Menu::select_vertical(*menuArr[1], HorizontalAlignment::Left, 0);		
		switch (c)
		{
		case 0:

			break;
		case 1:

			break;
		case 2:
			if ((*menuArr[1]).size() == 3)
				return;

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
	ITests* tst = new ITests;
	while (true) 	
	{
		system("cls");
		int c = Menu::select_vertical(*menuArr[2], HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:					
			//tst->getAllTests();
			tst->getGroupTest();
			system("pause");
			break;
		case 1:
			
			system("pause");
			break;
		case 2:
			if ((*menuArr[2]).size() == 3)
				return;
			
			//system("pause");			
			break;
		case 3:
			return;
		default:
			break;
		}
	}
	delete tst;
}


void AdminExten::testsMenu()
{
	ITests* tst = new ITests;
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(*menuArr[2], HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:
			tst->getAllTests();

			system("pause");
			break;
		case 1:
			tst->getGroupTest();

			system("pause");
			break;
		case 2:
			if ((*menuArr[2]).size() == 3)
				return;

			tst->setAllTests();

			system("pause");
			break;
		case 3:
			return;
		default:
			break;
		}
	}
	delete tst;
}

