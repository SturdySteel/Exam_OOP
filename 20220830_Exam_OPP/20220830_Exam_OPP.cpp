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
