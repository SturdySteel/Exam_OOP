#include "UserLogin.h"

int UserLogin::id{ 0 };

UserLogin::UserLogin(UserLogin& obj)
{
	this->operator=(obj);
}

UserLogin& UserLogin::operator=(UserLogin& obj)
{
	this->id = obj.id;
	this->login = obj.login;
	this->pass = "";
	this->superuser = obj.superuser;
	if (dataUL != nullptr) delete dataUL;
	auto ptr = obj.getDataUL();
	this->dataUL = new UserData{ ptr.getUsersId(), ptr.getINN(), ptr.getName(),
		ptr.getSurname(), ptr.getBirthday(), ptr.getRegdate(), ptr.getPhone() };
	
	return *this;
}

void UserLogin::menuMain(std::vector<std::string>& menu)
{
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical(menu, HorizontalAlignment::Left, 0);
		switch (c)
		{
		case 0:
			if (!autorization())
			{
				system("cls");
				setColor(ConsoleColor::Red);
				std::cout << "\nВозможно попытка подбора пользователя или пароля\n";
				setColor(ConsoleColor::White);
				Sleep(1500);
				exit(0);			
			}			
			std::cout << "\nПользователь '" << this->login << "' вошел в систему.\n\n";
			Sleep(1500);
			system("cls");			
			return;			
		case 1:
			if (!registration())
			{
				std::cout << "\nПользователь не зарегистрирован в системе.\n\n";
				Sleep(1500);
			}
			std::cout << "\nПользователь зарегистрирован в системе.\n\n";
			Sleep(1500);			
			break;
		case 2:
			/*if (this->id != 0)
				return;*/
			exit(0);			
		default:
			break;
		}
	}	
}

void UserLogin::setLogin(std::string login) { this->login = login; }

void UserLogin::setPass(std::string pass) { this->pass = pass; }

void UserLogin::setSU(bool su) { this->superuser = su; }

void UserLogin::setDataUL(int users_id, std::string inn, std::string name, std::string surname,
	std::string birthday, std::string registerDate, std::string phone)
{
	delete this->dataUL;
	this->dataUL = new UserData{users_id, inn, name, surname,
		birthday, registerDate, phone };
}

UserData& UserLogin::getDataUL() { return *this->dataUL; }

std::string UserLogin::getLogin() { return this->login; }

std::string UserLogin::getPass() { return this->pass; }

bool UserLogin::getSU() { return this->superuser; }

void UserLogin::show()
{
	if (this->id == 0)
		return;
	std::cout << std::setw(15) << "id = " << this->id << "\n"
		<< std::setw(15) << "login = " << this->login << "\n"
		<< std::setw(15) << "hash/pass = " << this->pass << "\n"
		<< std::setw(15) << "superuser = " << this->superuser << "\n";
	if(dataUL != nullptr)
		dataUL->show();
}

UserLogin::~UserLogin() { if(dataUL != nullptr) delete dataUL; }

bool UserLogin::autorization()
{
	UserEdit* usEd = UserEdit::getInstance();
	QueryDB* db = QueryDB::getInstance();
	this->id = 0;
	std::string login, pass, select;
	std::regex rgX;
	sqlite3_stmt* stmt{ nullptr };
	int i{};
	while (this->id == 0)
	{
		if (i++ >= 3) return 0;
		system("cls");
		rgX = R"(\w{5,})";
		login = usEd->inputStr("Авторизация\nЛогин: ", rgX, 0);
		pass = md5(usEd->inputStr("Пароль: ", rgX, 2, false));				
		select = "SELECT * FROM users WHERE login='" + login + "' AND password ='" + pass + "';";				
		stmt = db->selectSQL(select);
		this->id = sqlite3_column_int(stmt, 0);
		if (this->id == 0 || stmt == nullptr)
		{			
			std::cout << "\nПользователь/пароль не верен...\n";
			Sleep(1500);
		}		
	}
	this->login = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
	this->pass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
	this->superuser = sqlite3_column_int(stmt, 3);
	stmt = nullptr;
	select = "SELECT * FROM userdata WHERE users_id ='" + std::to_string(this->id)+ "';";
	stmt = db->selectSQL(select);
	if (stmt == nullptr || sqlite3_column_int(stmt, 0) == 0)
	{
		this->dataUL = new UserData;
		return 1;
	}
	setDataUL(sqlite3_column_int(stmt, 0),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)),
		reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));

	return 1;
}

bool UserLogin::registration()
{	
	UserEdit* usEd = UserEdit::getInstance();
	return usEd->create();
}
