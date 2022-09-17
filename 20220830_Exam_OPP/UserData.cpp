#include "UserData.h"

UserData::UserData(int users_id, std::string inn, std::string name, std::string surname,
	std::string birthday, std::string registerDate, std::string phone) :
	users_id{ users_id }, inn{ inn }, name{ name }, surname{ surname },
	birthday{ birthday }, registerDate{ registerDate }, phone{ phone }
{}

void UserData::setUsersId(int users_id) { this->users_id = users_id; }

void UserData::setINN(std::string inn) { this->inn = inn; }

void UserData::setName(std::string name) { this->name = name; }

void UserData::setSurname(std::string surname) { this->surname = surname; }

void UserData::setBirthday(std::string birthday) { this->birthday = birthday; }

void UserData::setRegdate(std::string registerDate) { this->registerDate = registerDate; }

void UserData::setPhone(std::string phone) { this->phone = phone; }

int UserData::getUsersId() { return this->users_id; }

std::string UserData::getINN() { return this->inn; }

std::string UserData::getName() { return this->name; }

std::string UserData::getSurname() { return this->surname; }

std::string UserData::getBirthday() { return this->birthday; }

std::string UserData::getRegdate() { return this->registerDate; }

std::string UserData::getPhone() { return this->phone;}

void UserData::show()
{
	if (this->users_id == 0)
		return;
	std::cout << std::setw(15) << "inn = " << this->inn << "\n"
		<< std::setw(15) << "name = " << this->name << "\n"
		<< std::setw(15) << "surname = " << this->surname << "\n"
		<< std::setw(15) << "birthday = " << this->birthday << "\n"
		<< std::setw(15) << "registerDate = " << this->registerDate << "\n"
		<< std::setw(15) << "phone = " << this->phone << "\n";
}