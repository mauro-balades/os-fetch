
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

#define SYSTEM_RELEASE_PATH "/etc/os-release"

namespace utils
{
    void print_os_fetch_header();
    void print_half_line();
};

namespace colors
{

};

#endif /* __OS_FETCH_SYSTEM_UTILS_H__ */

