#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>
#include "UserData.h"
#include <string>
#include <vector>
#include <regex>
#include <iterator>
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
	
	friend void selectSQL(const std::string& query, auto& obj);
		
	static std::string input(std::string text, bool sw = true);

	void setLogin(std::string login);
	void setPass(std::string pass);
	void setSU(bool su);
	void setDataUL(int users_id, size_t inn, std::string name, std::string surname,
		std::string birthday, std::string registerDate, size_t phone);

	UserData& getDataUL();
	std::string getLogin();
	std::string getPass();
	bool getSU();
	
	~UserLogin();	
};

#endif // !USERLOGIN_H
