#include <iostream>
#include <string>
#include <cstring>
#include "sqlite3/sqlite3.h"
#include "sqlite3/sqlite3ext.h"
#include "Menu.h"
#include "ArrayMenu.h"


std::string dbName{ "testsystem.db"};

void menu()
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical({ "Show",	"Save",	"Load",	"Exit" });
		switch (c)
		{
		case 0: 
			system("pause"); break;
		case 1: 
			system("pause"); break;
		case 2: 
			system("pause"); break;
		case 3: 
			exit(0);
		default:
			break;
		}
	}
	//return arr;
}



int main()
{
	menu();

	return 0;
}
