#ifndef DATAEDIT_H
#define DATAEDIT_H
#include <string>
#include <vector>
#include <regex>
#include <locale>
#include <iterator>
//#include "UserData.h"
#include "Menu.h"
#include "MD5.h"
#include "queryDB.h"
#include "ManipulCursor.h"
#include "UserLogin.h"

class DataEdit
{
private:
	static DataEdit* instance;
	DataEdit() {}

public:
	static DataEdit* getInstance();
	bool create();
	std::string inputStr(std::string&& text, std::regex rgX, int y, bool sw = true);
	void cp866_cp1251(std::string& s);

	//bool edit(auto& obj);	

};
#endif // !DATAEDIT_H
