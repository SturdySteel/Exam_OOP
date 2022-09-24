#ifndef USEREXTEN_H
#define USEREXTEN_H
#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include "queryDB.h"
#include "ManipulCursor.h"
#include "Menu.h"
#include "ITests.h"
//#include "ArrayMenu.h"

class UserExten
{
protected:
	std::vector<std::vector<std::string>> menuArr;
	//std::vector<void(*)()> swArr;

public:
	UserExten(std::vector<std::vector<std::string>>& menuArr);

	virtual void menu();
	virtual void usersMenu();
	virtual void testsMenu();
	//virtual void switcher(int c);
};

class AdminExten : public UserExten
{
private:
	
public:
	AdminExten(std::vector<std::vector<std::string>>& menuArr) : UserExten(menuArr) {}

};

#endif // !USEREXTEN_H
