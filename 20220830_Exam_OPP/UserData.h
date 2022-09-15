#ifndef USERDATA_H
#define USERDATA_H
#include <string>

class UserData
{
private:
	int users_id;
	size_t inn;
	std::string name;
	std::string surname;
	std::string birthday;
	std::string registerDate;
	size_t phone;

public:
	UserData(int users_id, size_t inn, std::string name, std::string surname,
		std::string birthday, std::string registerDate, size_t phone) :
		users_id{ users_id }, inn{ inn }, name{ name }, surname{ surname },
		birthday { birthday }, registerDate { registerDate }, phone { phone }
	{}
};

#endif // !USERDATA_H
