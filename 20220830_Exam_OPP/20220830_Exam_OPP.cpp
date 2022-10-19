#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <locale>
#include "ArrayMenu.h"
#include "UserLogin.h"
#include "UserExten.h"
#include "DataEdit.h"
#include "ITests.h"

//#include "UserData.h"
//#include "sqlite3/sqlite3.h"
//#include "MD5.h"
//#include "SubMenu.h"
//#include "UserTest.h"
//#include "queryDB.h"
//#include "Menu.h"

//std::string dbName{ "db/testsystem.db" };

/*menu*/
//void menu(std::vector<std::string> menu, bool mainM = false)
//{
//	while (true)
//	{
//		system("cls");
//		int c = Menu::select_vertical(menu);
//		switch (c)
//		{
//		case 0: 
//			system("pause"); 
//            break;
//		case 1: 
//			system("pause"); 
//            break;
//		case 2: 
//            if (menu.size() == 3) { if (mainM) exit(0); else return; }
//
//			system("pause"); 
//            break;
//		case 3:
//            if (menu.size() == 4) { if (mainM) exit(0); else return; }
//
//            system("pause"); 
//            break;
//        case 4:                        
//            exit(0);
//            break;
//		default:
//			break;
//		}
//	}
//	return;
//}


int main()
{
    setlocale(LC_ALL, "ru");   
    //std::locale::global(std::locale(""));

    UserLogin usr;
    AdminExten adm{ admMenuArr };
    UserExten user{ userMenuArr };

    
    //system("pause");
    //DEBUG. comment for run normaly 
    //adm.menu();
    //exit(0);
    //////////////////////////////
    
    while (true) {       
        usr.menuMain(mainMenu);
        //user.show();

        switch (UserLogin::superuser) {
        case true:
            
            adm.menu();
            //std::cout << usr.getLogin() << "\n";
            break;
        case false:
            user.menu();
            //std::cout << usr.getLogin() << "\n";
            break;        
        }
    }

	return 0;
}
