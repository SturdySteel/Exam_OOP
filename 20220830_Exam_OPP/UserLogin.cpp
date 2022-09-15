#include "UserLogin.h"

int UserLogin::id{ 0 };

void UserLogin::menuMain(std::vector<std::string>& menu)
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menu);
		switch (c)
		{
		case 0:
			autorization();
			system("pause");
			break;
		case 1:

			system("pause");
			break;
		case 2:

			return;
			exit(0);
			break;
		default:
			break;
		}
	}
	//return;
}

std::string UserLogin::input(std::string text, bool sw) //if true text printed White
{
	std::regex rgX(R"(\w+)");
	std::string val;
	do {
		system("cls");
		val = "";		
		std::cout << text;
		setColor(sw ? ConsoleColor::White : ConsoleColor::Black);
		getline(std::cin, val);
		setColor(ConsoleColor::White);
		//std::cin.ignore(32768, '\n');			
	} while (!(std::regex_match(val.data(), rgX)));	
	return val;
}

void UserLogin::setLogin(std::string login)
{
	this->login = login;
}

void UserLogin::setPass(std::string pass)
{
	this->pass = pass;
}

void UserLogin::setSU(bool su)
{
	this->superuser = su;
}

void UserLogin::setDataUL(int users_id, size_t inn, std::string name, std::string surname,
	std::string birthday, std::string registerDate, size_t phone)
{
	delete this->dataUL;
	this->dataUL = new UserData{users_id, inn, name, surname,
		birthday, registerDate, phone };
}

UserData& UserLogin::getDataUL()
{
	return *this->dataUL;
}

std::string UserLogin::getLogin()
{
	return this->login;
}

std::string UserLogin::getPass()
{
	return this->pass;
}

bool UserLogin::getSU()
{
	return this->superuser;
}

UserLogin::~UserLogin()
{
	delete dataUL;
}

bool UserLogin::autorization()
{
	std::string login, pass, select;

	while (this->id == 0)
	{
		//system("cls");
		login = UserLogin::input("Логин: ");		
		pass = UserLogin::input("Пароль: ", false);
		pass = md5(pass);
		
		select = "SELECT * FROM USERS WHERE login='" + login 
			+ "' AND password ='" + pass + "';";
				
		selectSQL(select, *this);
		if (this->id == 0)
		{
			std::cout << "Пользователь не найден...\n";
			Sleep(1500);			
		}
	}
	this->login = login;
	this->pass = pass;

	select = "SELECT * FROM userdata WHERE users_id ='" + std::to_string(this->id)+ "';";

	extractSQL(select, *this);

	//querySQL(select, callback);

	//SELECT* FROM USERS JOIN USERDATA ON users_id = id

	return 1;
}
