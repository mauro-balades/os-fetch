
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
    std::string system_hostname_line();
    std::string system_uptime();
    std::string system_terminal();
    std::string system_version();
    std::string system_machine();
};

namespace sections
{
    extern std::string system_os_section;
    extern std::string system_uptime_section;
    extern std::string system_term_section;
    extern std::string system_version;
    extern std::string system_machine;
};

#endif /* __OS_FETCH_SYSTEM_INFO_H__ */
