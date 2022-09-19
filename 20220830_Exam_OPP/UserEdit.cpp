#include "UserEdit.h"

//UserEdit* instance = nullptr;
//
//UserEdit* UserEdit::getInstance()
//{
//	if (instance == nullptr)
//		instance = new UserEdit();
//	return nullptr;
//}

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
		login = UserLogin::inputStr("Регистрация\nЛогин: ", rgX, 0);
		select = "SELECT * FROM users WHERE login='" + login + "';";
		stmt = db->selectSQL(select);
		if (sqlite3_column_int(stmt, 0) == 0)
			break;
		else
		{
			std::cout << "Такой логин зарегистрирован"; Sleep(1500);
		}
	} while (true);
	pass = md5(UserLogin::inputStr("Пароль: ", rgX, 2, false));
	insert = "INSERT INTO USERS(login, password, superuser) VALUES('" + login + "', '"
		+ pass + "', '" + std::to_string(superuser) + "'); ";
	if (!db->querySQL(insert))
		return 0;
	int id = db->getIdByLogin(login);

	do {
		rgX = R"(\d{10})";
		inn = UserLogin::inputStr("ИНН (10 цифр): ", rgX, 3);
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
		phone = UserLogin::inputStr("Телефон (10-12 цифр): ", rgX, 4);
		select = "SELECT * FROM userdata WHERE phone='" + phone + "';";
		stmt = db->selectSQL(select);
		if (sqlite3_column_int(stmt, 0) == 0) break;
		else
		{
			std::cout << "Такой телефон зарегистрирован"; Sleep(1500);
		}
	} while (true);

	rgX = R"(\w+)";
	name = UserLogin::inputStr("Имя: ", rgX, 5);
	surname = UserLogin::inputStr("Фамилия: ", rgX, 6);
	rgX = R"(\d{4}\-[01]{1}\d{1}\-[0-3]{1}\d{1})";
	birthday = UserLogin::inputStr("Дата рождения (ГГГГ-ММ-ДД): ", rgX, 7);
	registerDate = UserLogin::inputStr("Дата регистрации (ГГГГ-ММ-ДД): ", rgX, 8);

	insert = "INSERT INTO USERDATA(users_id,inn,name,surname,birthday,registerDate,phone) VALUES ('"
		+ std::to_string(id) + "','" + inn + "','" + name + "','" + surname + "','"
		+ birthday + "','" + registerDate + "','" + phone + "');";
	if (!db->querySQL(insert))
		return 0;

	return 1;

}

//bool UserEdit::edit(UserLogin& obj)
//{
//    return false;
//}
//
//UserEdit::~UserEdit() {	if (uM != nullptr) delete uM; }
