#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <string>
#include <iomanip>

class UserData
{
private:
	int users_id{};
	std::string inn{};
	std::string name{};
	std::string surname{};
	std::string birthday{};
	std::string registerDate{};
	std::string phone{};

public:
	UserData() {}
	UserData(int users_id, std::string inn, std::string name, std::string surname,
		std::string birthday, std::string registerDate, std::string phone);

	//void setUsersId(int users_id);
	void setINN(std::string inn);
	void setName(std::string name);
	void setSurname(std::string surname);
	void setBirthday(std::string birthday);
	void setRegdate(std::string registerDate);
	void setPhone(std::string phone);

	int getUsersId();
	std::string getINN();
	std::string getName();
	std::string getSurname();
	std::string getBirthday();
	std::string getRegdate();
	std::string getPhone();

	void show();
};

#endif // !USERDATA_H
