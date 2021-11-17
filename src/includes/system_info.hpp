
#ifndef __OS_FETCH_SYSTEM_INFO_H__
#define __OS_FETCH_SYSTEM_INFO_H__

#include <string>
#include <sstream>
#include <cstdlib>

#include <iostream>
#include <cstdlib>
#include <fstream>

#include <filesystem>
#include <chrono>
#include <thread>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include <limits.h>

#define SYSTEM_RELEASE_PATH "/etc/os-release"

namespace system_info
{
    void system_info_path_check();
    std::string system_os();
    std::string system_name_at_hostname();
};

namespace sections
{
    extern std::string system_os_section;
};

#endif /* __OS_FETCH_SYSTEM_INFO_H__ */