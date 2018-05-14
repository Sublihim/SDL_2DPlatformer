/*
    Классы для отладочного вывода.
*/

#include<iostream>

//#define DEBUG_MESSAGES_SHOW

namespace dbg
{

// определяем типы, чтобы работал std::endl
typedef std::basic_ostream<char, std::char_traits<char> > CoutType;
typedef CoutType& (*StandardEndLine)(CoutType&);

class Debug
{
public:
    Debug operator << (const std::string& outStr) { std::cout << outStr; return *this;}
    Debug operator << (const char* OutCptrChar) { std::cout << OutCptrChar; return *this;}
    Debug operator << (int outInt) { std::cout << outInt; return *this;}
    Debug operator << (unsigned int outUInt) { std::cout << outUInt; return *this;}
    Debug operator << (long outLong) { std::cout << outLong; return *this;}
    Debug operator << (float outFloat) { std::cout << outFloat; return *this;}
    Debug operator << (StandardEndLine manip) { manip(std::cout); return *this;}
};

// При сбобрке с оптимизацией, оптимизатор должен выкинуть использование
// этого класса со всеми причитающимися
class NoDebug
{
public:
    NoDebug operator << (const std::string& outStr) { return *this;}
    NoDebug operator << (const char* OutCptrChar) { return *this;}
    NoDebug operator << (int outInt) { return *this;}
    NoDebug operator << (unsigned int outUInt) { return *this;}
    NoDebug operator << (long outLong) { return *this;}
    NoDebug operator << (float outFloat) { return *this;}
    NoDebug operator << (StandardEndLine manip) { return *this;}
};

} // namespace dbg

#define NO_DEBUG_CALL while (false) dbg::NoDebug

#ifndef DEBUG_MESSAGES_SHOW
    #define debug NO_DEBUG_CALL
#else
    #define debug dbg::Debug
#endif