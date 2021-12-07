#pragma once

#include <iostream>
#include <vector>

template<typename T,
        typename = typename std::enable_if<std::is_integral<T>::value>::type>
void PrintIp(T ipAddress) {
    std::cout << ipAddress << "\tshort\n";
}

template<typename T,
        typename = typename std::enable_if<
                std::is_same<
                        typename std::remove_reference<T>::type,
                        std::vector<int>>::value,
                void>::type,
        typename STUB1 = int>
void PrintIp(T ipAddress) {
    for (auto i: ipAddress)
        std::cout << i << ".";

    std::cout << "\tvector*\n";;
}

template<typename T,
        typename = typename std::enable_if<
                std::is_same<T, const char *>::value,
                void>::type,
        typename STUB1 = int,
        typename STUB2 = int>
void PrintIp(T ipAddress) {
    std::cout << ipAddress << "\tvector*\n";;
}

