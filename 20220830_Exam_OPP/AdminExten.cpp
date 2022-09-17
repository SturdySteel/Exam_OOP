#include "AdminExten.h"


void AdminExten::admMenu(std::vector<std::string>& menu)
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menu, HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:
			//admUserMenu(admUsersMenu);
			break;
		case 1:
			
			break;
		case 2:
			return;			
		default:
			break;
		}
	}
}

void AdminExten::admUserMenu(std::vector<std::string>& menu)
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menu, HorizontalAlignment::Left, 0);
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

void AdminExten::admTestMenu(std::vector<std::string>& menu)
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menu, HorizontalAlignment::Left, 0);
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
