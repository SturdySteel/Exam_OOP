#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <string>
#include <iomanip>

class UserData
{
private:
	int users_id{};
	size_t inn{};
	std::string name{};
	std::string surname{};
	std::string birthday{};
	std::string registerDate{};
	size_t phone{};

public:
	UserData() {}
	UserData(int users_id, size_t inn, std::string name, std::string surname,
		std::string birthday, std::string registerDate, size_t phone); 	

	void setUsersId(int users_id);
	void setINN(size_t inn);
	void setName(std::string name);
	void setSurname(std::string surname);
	void setBirthday(std::string birthday);
	void setRegdate(std::string registerDate);
	void setPhone(size_t phone);

	int getUsersId();
	size_t getINN();
	std::string getName();
	std::string getSurname();
	std::string getBirthday();
	std::string getRegdate();
	size_t getPhone();

	void show();
};

#endif // !USERDATA_H
