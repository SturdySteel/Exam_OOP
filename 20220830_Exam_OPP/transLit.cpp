#include "DataEdit.h"

std::string DataEdit::translitChar(const char ch)
{
    switch (ch)
    {
    case '�': return "A";
    case '�': return "B";
    case '�': return "V";
    case '�': return "G";
    case '�': return "D";
    case '�': return "E";
    case '�': return "JE";
    case '�': return "ZH";
    case '�': return "Z";
    case '�': return "I";
    case '�': return "Y";
    case '�': return "K";
    case '�': return "L";
    case '�': return "M";
    case '�': return "N";
    case '�': return "O";
    case '�': return "P";
    case '�': return "R";
    case '�': return "S";
    case '�': return "T";
    case '�': return "U";
    case '�': return "F";
    case '�': return "KH";
    case '�': return "C";
    case '�': return "CH";
    case '�': return "SH";
    case '�': return "JSH";
    case '�': return "HH";
    case '�': return "IH";
    case '�': return "JH";
    case '�': return "EH";
    case '�': return "JU";
    case '�': return "JA";
    case '�': return "a";
    case '�': return "b";
    case '�': return "v";
    case '�': return "g";
    case '�': return "d";
    case '�': return "e";
    case '�': return "je";
    case '�': return "zh";
    case '�': return "z";
    case '�': return "i";
    case '�': return "y";
    case '�': return "k";
    case '�': return "l";
    case '�': return "m";
    case '�': return "n";
    case '�': return "o";
    case '�': return "p";
    case '�': return "r";
    case '�': return "s";
    case '�': return "t";
    case '�': return "u";
    case '�': return "f";
    case '�': return "kh";
    case '�': return "c";
    case '�': return "ch";
    case '�': return "sh";
    case '�': return "jsh";
    case '�': return "hh";
    case '�': return "ih";
    case '�': return "jh";
    case '�': return "eh";
    case '�': return "ju";
    case '�': return "ja";
    default: return std::to_string(ch);
    }
}


std::string DataEdit::translitStr(const std::string& str)
{
    std::string ts{};
    for (size_t i{}; i < str.length(); ++i)
    {
        ts += translitChar(str[i]);
    }
    return ts;
}