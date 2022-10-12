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

public:
    static QueryDB* getInstance();
    int querySQL(const std::string& query, int(*method)(void*, int, char**, char**) = 0);
    sqlite3_stmt* selectSQL(const std::string& query);
    int getIdByLogin(std::string login);
    //int getPrKeyByTabName(std::string tabName, std::string colName);
    int getMaxID(std::string tabName, std::string id);

    bool updateData(std::string tabName, std::string colName, 
        std::string sel, int id, auto& val);
    
    int checkExistTable(std::string tabName);

    //void createUsersTable();
    //void createUserDataTable();
    //void createTestPassedTable();
    //void createTableGroupsTests();
        
    bool createGroupTest(std::string str);
    bool createSubGroupTest(std::string str);
    bool createTest(std::string str);
    
    void insertTableGroupsTest(std::string& nameGroup, int& countTest, std::string& tableName);

    void insertTableGroupTest(std::string& tableName, std::string& nameGroupTest, 
        std::string& tableGroupTest);

    void insertTableSubGroupTest(std::string& tableGroupTest, std::string& nameTest, 
        std::string& tableNameTest, int& countQuestions);
    
    void insertTableTests(std::string& tableNameTest, std::string& question, 
        std::string& answer01, std::string& answer02, std::string& answer03, 
        std::string& answer04, int& rightAnswer);
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
