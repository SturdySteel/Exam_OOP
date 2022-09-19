#include "UserEdit.h"

UserEdit* UserEdit::instance = nullptr;

UserEdit* UserEdit::getInstance()
{
	if (instance == nullptr)
		instance = new UserEdit();
	return nullptr;
}

bool UserEdit::create()
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

std::string UserEdit::inputStr(std::string&& text, std::regex rgX, int y, bool sw) //if false text printed Black
{
	std::string val;
	do {
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

//bool UserEdit::edit(auto& obj)
//{
//    return false;
//}
//
//UserEdit::~UserEdit() {	if (uM != nullptr) delete uM; }
