#pragma once

#include <iostream>

template<typename T>
void PrintIp(T ipAddress);

template<>
void PrintIp<short>(short ipAddress) {
    std::cout << ipAddress << "\tshort\n";
}

template<>
void PrintIp<int>(int ipAddress) {
    std::cout << ipAddress << "\tint\n";;
}

template<>
void PrintIp<long>(long ipAddress) {
    std::cout << ipAddress << "\tlong\n";;
}

template<>
void PrintIp<const char *>(const char *ipAddress) {
    std::cout << ipAddress << "\tchar*\n";;
}

