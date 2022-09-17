#ifndef ADMINEXTEN_H
#define ADMINEXTEN_H
#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include "queryDB.h"
#include "ManipulCursor.h"
#include "Menu.h"
//#include "ArrayMenu.h"

class AdminExten
{
private:

public:
	AdminExten() {}

	void admMenu(std::vector<std::string>& menu);
	void admUserMenu(std::vector<std::string>& menu);
	void admTestMenu(std::vector<std::string>& menu);
};
#endif // !ADMINEXTEN_H
