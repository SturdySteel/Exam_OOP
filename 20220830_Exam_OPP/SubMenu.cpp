//#include "SubMenu.h"
//
//
//void menuMain(std::vector<std::string>& menu)
//{
//	while (true)
//	{
//		system("cls");
//		int c = Menu::select_vertical(menu);
//		switch (c)
//		{
//		case 0:
//			autorization();
//			system("pause");
//			break;
//		case 1:
//
//			system("pause");
//			break;
//		case 2:
//			
//			return;
//			exit(0);						
//		default:
//			break;
//		}
//	}
//	//return;
//}
//
//void autorization()
//{
//	std::string login;
//	std::string pass;
//	std::cout << "Логин: ";
//	getline(std::cin, login);
//	std::cout << "Пароль: ";
//	getline(std::cin, pass);
//	pass = md5(pass);
//	//std::cout << pass << "\n";
//	std::string select1 = "SELECT id FROM USERS WHERE login='" + login + "';";
//	//querySQL(select1, callback);
//	selectSQL(select1);
//
//}