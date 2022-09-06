#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "ManipulCursor.h"

//using namespace std;

enum HorizontalAlignment
{
	Center, Left, Right
};

class Menu
{
public:
	static int select_vertical(std::vector<std::string> menu, HorizontalAlignment ha, int y = 12)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO start_attribute;
		GetConsoleScreenBufferInfo(hStdOut, &start_attribute);
		int backColor = start_attribute.wAttributes & 15;
		int textColor = (start_attribute.wAttributes >>= 4) & 15;
		int maxLen = 0;
		for (int i = 0; i < menu.size(); i++)
		{
			menu[i] = " " + menu[i] + " ";
			if (menu[i].length() > maxLen)
				maxLen = menu[i].length();
		}
		int x = 0;
		switch (ha)
		{
		case Center: x = 40 - maxLen / 2; break;
		case Left:   x = 0;	              break;
		case Right:  x = 80 - maxLen;     break;
		}
		char c;
		int pos = 0;
		do
		{
			for (int i{}; i < menu.size(); i++)
			{
				if (i == pos)
				{
					setColor(textColor, backColor);
					setPosition(x, y + i);
					std::cout << std::setw(maxLen) << std::left;
					setPosition(x, y + i);
					std::cout << menu[i] << std::endl;
					setColor(backColor, textColor);
				}
				else
				{
					setColor(backColor, textColor);
					setPosition(x, y + i);
					std::cout << std::setw(maxLen) << std::left;
					setPosition(x, y + i);
					std::cout << menu[i] << std::endl;
					setColor(textColor, backColor);
				}
			}
			c = _getch();
			switch (c)
			{
			case 72: if (pos > 0)               pos--; break; // up
			case 80: if (pos < menu.size() - 1) pos++; break; // down
			case 13: break;
			}
		} while (c != 13);

		for (int i = 0; i < 2; i++)
		{
			setColor(backColor, textColor);
			setPosition(x, y + pos);
			std::cout << std::setw(maxLen) << std::left;
			setPosition(x, y + pos);
			std::cout << menu[pos] << std::endl;
			Sleep(200);
			setColor(textColor, backColor);
			setPosition(x, y + pos);
			std::cout << std::setw(maxLen) << std::left;
			setPosition(x, y + pos);
			std::cout << menu[pos] << std::endl;
			setColor(backColor, textColor);
			Sleep(200);
		}
		setColor(backColor, textColor);
		system("cls");
		return pos;
	}

	int select_gorizontal(std::vector<std::string> menu)
	{
		int max_len = 0;
		for (int i{}; i < menu.size(); i++)
			max_len += menu[i].length();
		if (max_len > 80 - menu.size() - 1)
			int a = 1;/////////
	}
};
