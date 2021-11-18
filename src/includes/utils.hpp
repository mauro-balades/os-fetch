
#ifndef __OS_FETCH_SYSTEM_UTILS_H__
#define __OS_FETCH_SYSTEM_UTILS_H__

#include <string>

#include <sstream>
#include <cstdlib>
#include <iostream>

#include <cstdlib>
#include <fstream>
#include <filesystem>

#include <chrono>
#include <thread>
#include <cstddef>

#define SYSTEM_RELEASE_PATH "/etc/os-release"

namespace utils
{
    void print_half_line();
    std::string repeat(std::string str, const std::size_t n);
};

namespace header
{
    extern std::string header1;
    extern std::string header2;
    extern std::string header3;
    extern std::string header4;
    extern std::string header5;
    extern std::string header6;
    extern std::string header7;
}

// TODO
namespace colors
{

};

#endif /* __OS_FETCH_SYSTEM_UTILS_H__ */

