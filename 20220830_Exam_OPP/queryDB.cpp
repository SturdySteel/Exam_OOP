#include "queryDB.h"

QueryDB* QueryDB::instance = nullptr;

int QueryDB::callback(void* NotUsed, int argc, char** argv, char** azColName) {
	for (int i{}; i < argc; i++)
		    {        
		        std::cout << std::setw(15) << azColName[i] << " : " 
		            << (argv[i] ? argv[i] : "NULL") << "\n";
		    }
		    std::cout << "\n";
		    return 0;
}

QueryDB* QueryDB::getInstance() {
	if (instance == nullptr)
        instance = new QueryDB();
	return instance;
}

int QueryDB::querySQL(const std::string& query, int(*method)(void*, int, char**, char**)) {
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
        //std::cout << "rc = " << rc << "\n";
        sqlite3_free(zErrMsg);
        return 0;
    }
    sqlite3_close(db);
    return 1;
}

sqlite3_stmt* QueryDB::selectSQL(const std::string& query) {
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
    sqlite3_close_v2(db);
    return stmt;
}
int QueryDB::getIdByLogin(std::string login) {
    sqlite3_stmt* stmt{ nullptr };
    std::string query = "SELECT id FROM users WHERE login ='" + login + "';";
    stmt = selectSQL(query);
    return sqlite3_column_int(stmt, 0);
}

bool QueryDB::updateData(std::string tabName, std::string colName, std::string sel, int id, auto& val) {
    std::string query = "UPDATE " + tabName + " SET " + colName +
        "='" + val + "' WHERE " + sel + "='" + id + "';";
    int rc = querySQL(query);
    if (rc != 1)
        return false;
    return true;
}
