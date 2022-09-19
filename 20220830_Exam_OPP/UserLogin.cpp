#include "UserLogin.h"

int UserLogin::id{ 0 };

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

std::string UserLogin::inputStr(std::string&& text, std::regex rgX, int y, bool sw) //if false text printed Black
{
	//std::regex rgX{R"(\w{3,})"};
	std::string val;
	do {
		//system("cls");
		setPosition(0, y);
		std::cout << "                                         ";
		val = "";		
		setPosition(0, y);
		std::cout << text;
		setColor(sw ? ConsoleColor::White : ConsoleColor::Black);
		getline(std::cin, val);
		setColor(ConsoleColor::White);
		//std::cin.ignore(32768, '\n');			
	} while (!(std::regex_match(val.data(), rgX)));	
	return val;
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

UserLogin::~UserLogin() { delete dataUL; }

bool UserLogin::autorization()
{
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
		login = inputStr("Авторизация\nЛогин: ", rgX, 0);
		pass = md5(inputStr("Пароль: ", rgX, 2, false));				
		select = "SELECT * FROM users WHERE login='" + login + "' AND password ='" + pass + "';";				
		stmt = db->selectSQL(select);
		this->id = sqlite3_column_int(stmt, 0);
		if (this->id == 0 || stmt == nullptr)
		{			
			std::cout << "\nПользователь '" << login << "' не найден...\n";
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
	QueryDB* db = QueryDB::getInstance();
	std::string select, insert;
	std::string login, pass;
	std::string inn, name, surname, birthday, registerDate, phone;
	bool superuser = false;
	sqlite3_stmt* stmt{ nullptr };
	
	std::regex rgX{ R"(\w{5,})" };
	do {
		system("cls");
		login = inputStr("Регистрация\nЛогин: ", rgX, 0);
		select = "SELECT * FROM users WHERE login='" + login + "';";
		stmt = db->selectSQL(select);		
		if (sqlite3_column_int(stmt, 0) == 0) 
			break;
		else 
		{ 
			std::cout << "Такой логин зарегистрирован"; Sleep(1500); 
		}
	} while (true);
	pass = md5(inputStr("Пароль: ", rgX, 2, false));
	insert = "INSERT INTO USERS(login, password, superuser) VALUES('" + login + "', '" 
		+ pass + "', '" + std::to_string(superuser) + "'); ";
	if (!db->querySQL(insert))
		return 0;
	int id = db->getIdByLogin(login);	

	do {
		rgX = R"(\d{10})";
		inn = inputStr("ИНН (10 цифр): ", rgX, 3);
		select = "SELECT * FROM userdata WHERE inn='" + inn + "';";
		stmt = db->selectSQL(select);
		if (sqlite3_column_int(stmt, 0) == 0) break;
		else
		{
			std::cout << "Такой ИНН зарегистрирован"; Sleep(1500);
		}
	} while (true);

	do {
		rgX = R"(\d{10,12})";
		phone = inputStr("Телефон (10-12 цифр): ", rgX, 4);
		select = "SELECT * FROM userdata WHERE phone='" + phone + "';";
		stmt = db->selectSQL(select);
		if (sqlite3_column_int(stmt, 0) == 0) break;
		else
		{
			std::cout << "Такой телефон зарегистрирован"; Sleep(1500);
		}
	} while (true);

	rgX = R"(\w+)";
	name = inputStr("Имя: ", rgX, 5);
	surname = inputStr("Фамилия: ", rgX, 6);
	rgX = R"(\d{4}\-[01]{1}\d{1}\-[0-3]{1}\d{1})";
	birthday = inputStr("Дата рождения (ГГГГ-ММ-ДД): ", rgX, 7);
	registerDate = inputStr("Дата регистрации (ГГГГ-ММ-ДД): ", rgX, 8);
	
	insert = "INSERT INTO USERDATA(users_id,inn,name,surname,birthday,registerDate,phone) VALUES ('"
		+ std::to_string(id) + "','" + inn + "','" + name + "','" + surname + "','"
		+ birthday + "','" + registerDate + "','" + phone + "');";
	if (!db->querySQL(insert))
		return 0;
	
	return 1;
}
