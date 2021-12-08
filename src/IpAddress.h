#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <tuple>

namespace is_stl_container_impl {
    template<typename T>
    struct is_stl_container : std::false_type {
    };
    template<typename T, std::size_t N>
    struct is_stl_container<std::array<T, N>> : std::true_type {
    };
    template<typename... Args>
    struct is_stl_container<std::vector<Args...>> : std::true_type {
    };
    template<typename... Args>
    struct is_stl_container<std::list<Args...>> : std::true_type {
    };
}

template<typename T>
struct is_stl_container {
    static constexpr bool const value = is_stl_container_impl::is_stl_container<std::decay_t<T>>::value;
};

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
typename std::enable_if<is_stl_container<T>::value>::type
PrintIp(T ipAddress) {
    for (auto i: ipAddress)
        std::cout << i << ".";

    std::cout << "\tcontainer\n";;
}

template<typename T>
typename std::enable_if<std::is_same<T, const char *>::value, void>::type
PrintIp(T ipAddress) {
    std::cout << ipAddress << "\tconst char*\n";;
}

template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
PrintIp(T ipAddress) {
    std::cout << ipAddress << "\tstd::string\n";;
}

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
PrintIp(std::tuple<Tp...> &t) {
    std::cout << "\ttuple\n";
}

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
PrintIp(std::tuple<Tp...> &t) {
    std::cout << static_cast<short>(std::get<I>(t)) << ".";
    PrintIp<I + 1, Tp...>(t);
}
