#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <vector>
//#include "sqlite3/sqlite3.h"
#include "ArrayMenu.h"
//#include "SubMenu.h"
#include "MD5.h"
#include "UserData.h"
#include "UserTest.h"
#include "UserLogin.h"
#include "queryDB.h"
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

//static int callback(void* NotUsed, int argc, char** argv, char** azColName) 
//{
//    int i;
//    for (i = 0; i < argc; i++) 
//    {
//        std::cout << std::boolalpha;
//        std::cout << std::setw(15)<< azColName[i] << " : " << (argv[i] ? argv[i] : "NULL") << "\n";
//    }
//    std::cout << "\n";
//    return 0;
//}
//
//static int extractData(void* NotUsed, int argc, char** argv, char** azColName) 
//{
//    int i;
//    for (i = 0; i < argc; i++) 
//    {        
//        UserLogin::id = std::stoi(argv[i]);     
//    }
//    
//    return 0;
//}
//
//int querySql(const std::string& query, int(*method)(void* NotUsed, int argc, char** argv, char** azColName) = 0)  /*bool flag = false,*/
//{
//    sqlite3* db;
//    char* zErrMsg{};
//    int rc{};
//    //const char* sql;
//    
//    rc = sqlite3_open(dbName.c_str(), &db);
//
//    if (rc) 
//    {
//        std::cerr << "Can't open database" << sqlite3_errmsg(db);
//        return 0;
//    }
//        
//    //sql = query.c_str();
//    
//    rc = sqlite3_exec(db, query.c_str(), method, 0, &zErrMsg); //sqlite3_exec(db, sql, callback, 0, &zErrMsg)
//    //rc = sqlite3_exec(db, query.c_str(), (flag ? callback : 0), 0, &zErrMsg); //sqlite3_exec(db, sql, callback, 0, &zErrMsg)
//
//    if (rc != SQLITE_OK)
//    {
//        std::cerr << "SQL error " << zErrMsg << "\n";
//        sqlite3_free(zErrMsg);
//    }
//    
//    sqlite3_close(db);
//    return 0;
//}

//void selectSql(const std::string& query)
//{
//    sqlite3* db;
//    char* zErrMsg = 0;
//    int rc;
//    const char* sql;
//    //const char* data = "Callback function called";
//
//    rc = sqlite3_open(dbName.c_str(), &db);
//
//    if (rc) {
//        std::cerr << "Can't open database: " << sqlite3_errmsg(db);
//        return;
//    }
//    
//    sql = query.c_str();
//       
//    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg); //(db, sql, callback, (void*)data, &zErrMsg);
//
//    if (rc != SQLITE_OK) {
//        std::cerr << "SQL error: " << zErrMsg;
//        sqlite3_free(zErrMsg);
//    }
//    sqlite3_close(db);
//    //return;
//}


int main()
{
    setlocale(LC_ALL, "ru");

    UserLogin user;

	user.menuMain(mainMenu);
      
    user.show();



    /*std::string str{"123456"};
    std::string login{ "test002" };
    std::string pass{ md5(str) };
    bool su{ false };*/

    /*size_t inn{ 1234567881 };
    std::string name{ "Petya"};
    std::string surname{ "Vasiliev" };
    std::string birthday{ "2000-02-01" };
    std::string registerDate{ "2022-09-01" };
    size_t phone{ 380671112234 };*/

    //UserLogin obj;

    /*std::string insert = "INSERT INTO USERS(login,password,superuser) VALUES ('" + login + "','" + pass +"','" + std::to_string(su) + "');";
    querySQL(insert);*/

    /*std::string select = "SELECT MAX(id) FROM USERS";*/
    
   /* std::string select = "SELECT * FROM USERS JOIN USERDATA ON users_id = id";
    
    std::string select1 = "SELECT id FROM USERS WHERE login='" + user + "';";
    querySql(select1, extractData);

    std::string insert = "INSERT INTO USERDATA(users_id,inn,name,surname,birthday,registerDate,phone) VALUES ('"
        + std::to_string(UserLogin::id) + "','" + std::to_string(inn) + "','" + name + "','" + surname + "','" 
        + birthday +"','" + registerDate + "','" + std::to_string(phone) + "');";*/

           
    
	return 0;
}
