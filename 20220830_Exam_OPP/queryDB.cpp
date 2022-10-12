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
        std::cout << "\nrc = " << rc << std::endl;
        system("pause");
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
    return stmt == nullptr ? -1 : sqlite3_column_int(stmt, 0);
}

int QueryDB::getMaxID(std::string tabName, std::string id)
{
    sqlite3_stmt* stmt{ nullptr };
    std::string query = "SELECT MAX(" + id + ") FROM " + tabName + ";";
    if(checkExistTable(tabName))
    {
        stmt = selectSQL(query);
        return sqlite3_column_int(stmt, 0);
    }
    return -1;
}

//int QueryDB::getPrKeyByTabName(std::string tabName, std::string colName)
//{
//    sqlite3_stmt* stmt{ nullptr };
//    std::string query = "SELECT " + colName + " FROM " + tabName +" WHERE login = '" + login + "'; ";
//    stmt = selectSQL(query);
//    sqlite3_column_int(stmt, 0);
//}

bool QueryDB::updateData(std::string tabName, std::string colName, std::string sel, int id, auto& val) {
    std::string query = "UPDATE " + tabName + " SET " + colName +
        "='" + val + "' WHERE " + sel + "='" + id + "';";
    int rc = querySQL(query);
    if (rc != 1)
        return false;
    return true;
}

int QueryDB::checkExistTable(std::string tabName)
{
    sqlite3_stmt* stmt{ nullptr };
    stmt = selectSQL("SELECT count(*) FROM sqlite_master WHERE type = 'table' AND name = '" + tabName + "';");
    return sqlite3_column_int(stmt, 0);    
}

bool QueryDB::createGroupTest(std::string str)
{
    std::string query = "CREATE TABLE IF NOT EXISTS " + str + 
        " (numGrTest Integer NOT NULL PRIMARY KEY AUTOINCREMENT," +
        "nameGroupTest Text NOT NULL, " +
        "tableGroupTest Text NOT NULL, " +
        "CONSTRAINT unique_numGrTest UNIQUE(numGrTest)," +
        "CONSTRAINT unique_tableGroupTest UNIQUE(tableGroupTest));";
    int rc = querySQL(query);
    if (rc != 1)
        return false;
    return true;
}

bool QueryDB::createSubGroupTest(std::string str)
{
    std::string query = "CREATE TABLE IF NOT EXISTS " + str +
        " (numTest Integer NOT NULL PRIMARY KEY AUTOINCREMENT, " + 
	    "nameTest Text,	" +
        "tableNameTest Text NOT NULL, " +
        "countQuestions Integer NOT NULL, " + 
        "CONSTRAINT unique_tableNameTest UNIQUE(tableNameTest));";
    int rc = querySQL(query);
    if (rc != 1)
        return false;
    return true;
}

bool QueryDB::createTest(std::string str)
{
    std::string query = "CREATE TABLE IF NOT EXISTS " + str +
        " (numQ Integer NOT NULL PRIMARY KEY AUTOINCREMENT," +
        " question Text, answer01 Text,	answer02 Text, answer03 Text," +
        " answer04 Text, rightAnswer Integer); ";
    int rc = querySQL(query);
    if (rc != 1)
        return false;
    return true;
}

void QueryDB::insertTableGroupsTest(std::string& nameGroup, int& countTest, std::string& tableName)
{
    std::string query = "INSERT INTO tableGroupsTests(nameGroup, countTest, tableName) VALUES('"+ 
        nameGroup + "', '" + std::to_string(countTest) + "', '" + tableName + "');";
}

void QueryDB::insertTableGroupTest(std::string& tableName, 
    std::string& nameGroupTest, std::string& tableGroupTest)
{
    std::string query = "INSERT INTO " + tableName  + " (nameGroupTest, tableGroupTest) VALUES('" +
        nameGroupTest + "', '" + tableGroupTest + "');";
}

void QueryDB::insertTableSubGroupTest(std::string& tableGroupTest, 
    std::string& nameTest, std::string& tableNameTest, int& countQuestions)
{
    std::string query = "INSERT INTO " + tableGroupTest + " (nameTest, tableNameTest, countQuestions) VALUES('" +
        nameTest + "', '" + tableNameTest + "', '" + std::to_string(countQuestions) + "');";
}

void QueryDB::insertTableTests(std::string& tableNameTest, std::string& question, 
    std::string& answer01, std::string& answer02, std::string& answer03, 
    std::string& answer04, int& rightAnswer)
{
    std::string query = "INSERT INTO " + tableNameTest + " (question, answer01, answer02," +
        " answer03, answer04, rightAnswer) VALUES('" + question + "', '" + answer01 + 
        "', '" + answer02 + "', '" + answer03 + "', '" + answer04 + "', '" + 
        std::to_string(rightAnswer) + "');";
}
