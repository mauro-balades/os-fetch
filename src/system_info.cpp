
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
    std::string system_info_path() {

        if (!std::filesystem::exists(SYSTEM_RELEASE_PATH)) {
            std::cerr << "/etc/os-release does not release, did you install your linux distro correctly?" << std::endl;
        }

        return SYSTEM_RELEASE_PATH;
    }

    std::string system_os(std::string info_file) {
        return "test";
    }
};
