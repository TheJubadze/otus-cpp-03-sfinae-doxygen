#pragma once

#include <iostream>
#include <vector>

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
PrintIp(T ipAddress) {
    auto bytes = reinterpret_cast<unsigned char *>(&ipAddress);
    for (int i = 0; i < sizeof(T); ++i) {
        std::cout << static_cast<short>(bytes[i]) << ".";
    }
    std::cout << "\tintegral: " << sizeof(T) << " bytes\n";
}

template<typename T>
typename std::enable_if<
    std::is_same<
        typename std::remove_reference<T>::type,
        std::vector<int>>::value,
    void>::type
PrintIp(T ipAddress) {
    for (auto i: ipAddress)
        std::cout << i << ".";

    std::cout << "\tvector\n";;
}

template<typename T>
typename std::enable_if<
    std::is_same<T, const char *>::value,
    void>::type
PrintIp(T ipAddress) {
    std::cout << ipAddress << "\tconst char*\n";;
}

