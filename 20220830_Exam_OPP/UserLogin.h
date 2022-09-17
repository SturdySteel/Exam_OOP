#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
#include <vector>
#include <regex>
#include <iterator>
#include "UserData.h"
#include "Menu.h"
#include "MD5.h"
#include "queryDB.h"
#include "ManipulCursor.h"

//typedef std::basic_string <unsigned char> ustring;

class UserLogin
{
private:
	std::string login{};
	std::string pass{};
	bool superuser{ false };
	UserData* dataUL{ nullptr };

public:
	static int id;

public:	
	void menuMain(std::vector<std::string>& menu);	
	bool autorization();
	bool registration();
			
	std::string inputStr(std::string&& text, std::regex rgX, int y, bool sw = true);	

	void setLogin(std::string login);
	void setPass(std::string pass);
	void setSU(bool su);
	void setDataUL(int users_id, std::string inn, std::string name, std::string surname,
		std::string birthday, std::string registerDate, std::string phone);

	UserData& getDataUL();
	std::string getLogin();
	std::string getPass();
	bool getSU();
	
	void show();
	~UserLogin();	
};
#endif // !USERLOGIN_H
