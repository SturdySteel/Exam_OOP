#ifndef MANIPULCURSOR_H
#define MANIPULCURSOR_H

#include <windows.h>

enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void setColor(int text, int background);
void setPosition(int x, int y);

#endif // !MANIPULCURSOR_H
