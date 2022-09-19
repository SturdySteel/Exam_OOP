#ifndef QUERYDB_H
#define QUERYDB_H
#include <iostream>
#include <iomanip>
#include "sqlite3/sqlite3.h"
#include <string>
#include <cstring>
#include "UserLogin.h"
#include "UserData.h"


class QueryDB
{
private:
    static QueryDB* instance;
    std::string dbName { "db/testsystem.db" };
    QueryDB() {}
    int callback(void* NotUsed, int argc, char** argv, char** azColName);

public:
    static QueryDB* getInstance();
    int querySQL(const std::string& query, int(*method)(void*, int, char**, char**) = 0);
    sqlite3_stmt* selectSQL(const std::string& query);
    int getIdByLogin(std::string login);
    
};
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
#endif // !QUERYDB_H
