#include "DataEdit.h"

std::string DataEdit::translitChar(const char ch)
{
    switch (ch)
    {
    case 'À': return "A";
    case 'Á': return "B";
    case 'Â': return "V";
    case 'Ã': return "G";
    case 'Ä': return "D";
    case 'Å': return "E";
    case '¨': return "JE";
    case 'Æ': return "ZH";
    case 'Ç': return "Z";
    case 'È': return "I";
    case 'É': return "Y";
    case 'Ê': return "K";
    case 'Ë': return "L";
    case 'Ì': return "M";
    case 'Í': return "N";
    case 'Î': return "O";
    case 'Ï': return "P";
    case 'Ğ': return "R";
    case 'Ñ': return "S";
    case 'Ò': return "T";
    case 'Ó': return "U";
    case 'Ô': return "F";
    case 'Õ': return "KH";
    case 'Ö': return "C";
    case '×': return "CH";
    case 'Ø': return "SH";
    case 'Ù': return "JSH";
    case 'Ú': return "HH";
    case 'Û': return "IH";
    case 'Ü': return "JH";
    case 'İ': return "EH";
    case 'Ş': return "JU";
    case 'ß': return "JA";
    case 'à': return "a";
    case 'á': return "b";
    case 'â': return "v";
    case 'ã': return "g";
    case 'ä': return "d";
    case 'å': return "e";
    case '¸': return "je";
    case 'æ': return "zh";
    case 'ç': return "z";
    case 'è': return "i";
    case 'é': return "y";
    case 'ê': return "k";
    case 'ë': return "l";
    case 'ì': return "m";
    case 'í': return "n";
    case 'î': return "o";
    case 'ï': return "p";
    case 'ğ': return "r";
    case 'ñ': return "s";
    case 'ò': return "t";
    case 'ó': return "u";
    case 'ô': return "f";
    case 'õ': return "kh";
    case 'ö': return "c";
    case '÷': return "ch";
    case 'ø': return "sh";
    case 'ù': return "jsh";
    case 'ú': return "hh";
    case 'û': return "ih";
    case 'ü': return "jh";
    case 'ı': return "eh";
    case 'ş': return "ju";
    case 'ÿ': return "ja";
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