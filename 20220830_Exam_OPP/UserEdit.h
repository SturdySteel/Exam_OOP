#ifndef USEREDIT_H
#define USEREDIT_H
#include <string>
#include <vector>
#include <regex>
#include <iterator>
//#include "UserData.h"
#include "Menu.h"
#include "MD5.h"
#include "queryDB.h"
#include "ManipulCursor.h"
#include "UserLogin.h"


class UserEdit
{
private:
	static UserEdit* instance;
	UserEdit() {}

public:
	static UserEdit* getInstance();
	bool create();
	std::string inputStr(std::string&& text, std::regex rgX, int y, bool sw = true);
	bool edit(auto& obj);	
};

#endif // !USEREDIT_H
