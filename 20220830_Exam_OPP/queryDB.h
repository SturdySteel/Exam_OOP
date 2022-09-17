#ifndef QUERYDB_H
#define QUERYDB_H
#include <iostream>
#include <iomanip>
#include "sqlite3/sqlite3.h"
#include <string>
#include <cstring>
#include "UserLogin.h"
#include "UserData.h"

static std::string dbName{ "db/testsystem.db" };

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{    
    for (int i{}; i < argc; i++)
    {
        std::cout << std::boolalpha;
        std::cout << std::setw(15) << azColName[i] << " : " 
            << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

static int querySQL(const std::string& query, int(*method)(void*, int, char**, char**) = 0)
{
    sqlite3* db;
    char* zErrMsg{};
    int rc = sqlite3_open(dbName.c_str(), &db);

    if (rc)
    {
        std::cerr << "Can't open database" << sqlite3_errmsg(db);
        return 0;
    }
    rc = sqlite3_exec(db, query.c_str(), method, 0, &zErrMsg); //(void*)data

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error " << zErrMsg << "\n";
        std::cout << "rc = " << rc << "\n";
        sqlite3_free(zErrMsg);
        return 0;
    }
    sqlite3_close(db);
    return 1;
}



static sqlite3_stmt* selectSQL(const std::string& query)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    //char* zErrMsg{};
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc)
    {
        std::cerr << "Can't open database" << sqlite3_errmsg(db);
        return nullptr;
    }
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
    sqlite3_step(stmt);    
    sqlite3_close(db);      
    return stmt;
}

static int getIdByLogin(std::string login)
{
    sqlite3_stmt* stmt{ nullptr };
    std::string query = "SELECT id FROM users WHERE login ='" + login + "';";
    stmt = selectSQL(query);
    return sqlite3_column_int(stmt, 0);
}

//"INSERT INTO USERS(login,password,superuser) VALUES ('" + login 
//    + "','" + pass +"','" + std::to_string(su) + "');";
//
//SELECT* FROM USERS JOIN USERDATA ON users_id = id
//"SELECT MAX(id) FROM USERS";
//"SELECT * FROM USERS JOIN USERDATA ON users_id = id";
//SELECT id FROM USERS WHERE login='" + user + "';";
//
//"INSERT INTO USERDATA(users_id,inn,name,surname,birthday,registerDate,phone) VALUES ('"
//     + std::to_string(UserLogin::id) + "','" + std::to_string(inn) + "','" + name + "','" + surname + "','"
//     + birthday +"','" + registerDate + "','" + std::to_string(phone) + "');";
//
//static void selectSQL(const std::string& query, auto& obj)
//{
//    sqlite3* db;
//    sqlite3_stmt* stmt;
//    char* zErrMsg{};
//    int rc = sqlite3_open(dbName.c_str(), &db);
//
//    if (rc)
//    {
//        std::cerr << "Can't open database" << sqlite3_errmsg(db);
//        return;
//    }
//    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
//    sqlite3_step(stmt);
//    obj.id = sqlite3_column_int(stmt, 0);
//    if (obj.id == 0)
//        return;
//    //std::cout << sqlite3_column_text(stmt, 2) << "\n";
//    obj.setSU(sqlite3_column_int(stmt, 3));
//    sqlite3_close(db);
//}

#endif // !QUERYDB_H
