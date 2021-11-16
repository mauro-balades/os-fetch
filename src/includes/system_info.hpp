
#ifndef __OS_FETCH_SYSTEM_INFO_H__
#define __OS_FETCH_SYSTEM_INFO_H__

#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>

#include "system_info.hpp"

#define SYSTEM_RELEASE_PATH "/etc/os-release"

namespace system_info
{
    void system_info_path_check();
    std::string system_os();
};

#endif /* __OS_FETCH_SYSTEM_INFO_H__ */