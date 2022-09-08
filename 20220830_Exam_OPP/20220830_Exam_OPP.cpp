#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<sstream>
#include"sqlite3/sqlite3.h"
#include"Menu.h"
#include"ArrayMenu.h"
#include"MD5.h"

std::string dbName{ "db/testsystem.db" };

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
			return; exit(0);
		default:
			break;
		}
	}
	//return arr;
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        std::cout << azColName[i] << " : " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

int insertSql(const std::string& query) 
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    const char* sql;
    
    rc = sqlite3_open(dbName.c_str(), &db);

    if (rc) 
    {
        std::cerr << "Can't open database" << sqlite3_errmsg(db);
        return(0);
    }
        
    sql = query.c_str();
    
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg); //sqlite3_exec(db, sql, callback, 0, &zErrMsg)

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }
    
    sqlite3_close(db);
    return 0;
}

void selectSql(const std::string& query)
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    const char* sql;
    //const char* data = "Callback function called";

    rc = sqlite3_open(dbName.c_str(), &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db);
        return;
    }
    
    sql = query.c_str();
       
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg); //(db, sql, callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);

    return;
}


int main()
{
	//menu();
    std::string str{"123456"};
    std::string user{ "test005" };
    std::string pass{ md5(str) };
    bool su{ false };

    std::string insert = "INSERT INTO USERS(login,password,superuser) VALUES ('" 
        + user + "', '" + pass + "', " + std::to_string(su) + "); ";

    std::string select = "SELECT * FROM USERS";
       
    insertSql(insert);

    selectSql(select);
   
        

	return 0;
}
