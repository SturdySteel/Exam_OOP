#ifndef QUERYDB_H
#define QUERYDB_H
#include <iostream>
#include <iomanip>
#include "sqlite3/sqlite3.h"
#include <string>
#include <cstring>
#include "querryString.h"
//#include "UserLogin.h"
//#include "UserData.h"


class QueryDB
{
private:
    static QueryDB* instance;
    std::string dbName { "db/testsystem.db" };

private:
    QueryDB() {}
    int callback(void* NotUsed, int argc, char** argv, char** azColName);
    int checkExistTable(std::string tabName);

public:
    static QueryDB* getInstance();
    int querySQL(const std::string& query, int(*method)(void*, int, char**, char**) = 0);
    sqlite3_stmt* selectSQL(const std::string& query);
    int getIdByLogin(std::string login);
    //int getPrKeyByTabName(std::string tabName, std::string colName);
    int getCountTest();

    int getMaxID(std::string tabName, std::string id);

    bool updateData(std::string tabName, std::string colName, 
        std::string sel, int id, auto& val);
    
    //void createUsersTable();
    //void createUserDataTable();
    //void createTestPassedTable();
    //void createTableGroupsTests();
        
    void createGroupTest(std::string str);
    void createSubGroupTest(std::string str);
    void createTest(std::string str);
    
    void insertTableGroupsTests(const std::string& nameGroup, const int& countTest, 
        const std::string& tableName);

    void insertTableGroupTest(const std::string& tableName, const std::string& nameGroupTest, 
        const std::string& tableGroupTest);

    void insertTableSubGroupTest(const std::string& tableGroupTest, const std::string& nameTest, 
        const std::string& tableNameTest, const int& countQuestions);
    
    void insertTableTests(const std::string& tableNameTest, const std::string& question, 
        const std::string& answer01, const std::string& answer02, 
        const std::string& answer03, const std::string& answer04, 
        const int& rightAnswer);
};

#endif // !QUERYDB_H

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
