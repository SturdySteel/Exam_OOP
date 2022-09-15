#ifndef QUERYDB_H
#define QUERYDB_H
#include <iostream>
#include <iomanip>
#include "sqlite3/sqlite3.h"
#include <string>
#include <cstring>
#include "UserLogin.h"

static std::string dbName{ "db/testsystem.db" };

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    //std::cerr << (const char*)data;
    int i;
    for (i = 0; i < argc; i++)
    {
        std::cout << std::boolalpha;
        std::cout << std::setw(15) << azColName[i] << " : " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

static int callback1(void* data, int argc, char** argv, char** azColName)
{

    /*if (argc == 0)
        std::cout << "notfound\n";*/
    std::cout << argc << "\n";

    int i;
    for (i = 0; i < argc; i++)
    {
        std::cout << std::boolalpha;
        std::cout << std::setw(15) << azColName[i] << " : " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

static int extractData(void* NotUsed, int argc, char** argv, char** azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        UserLogin::id = std::stoi(argv[i]);
    }

    return 0;
}

static int querySql(const std::string& query/*, int(*method)(void*, int, char**, char**) = 0*/)
{
    sqlite3* db;
    char* zErrMsg{};
    int rc{};
    //const char* data = "Callback function called";
    //const char* sql;

    rc = sqlite3_open(dbName.c_str(), &db);

    if (rc)
    {
        std::cerr << "Can't open database" << sqlite3_errmsg(db);
        return 0;
    }
    
    //sql = query.c_str();

    rc = sqlite3_exec(db, query.c_str(), callback1, 0, &zErrMsg); //(void*)data

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}

#endif // !QUERYDB_H
