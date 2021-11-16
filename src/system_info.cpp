
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>

#include "system_info.hpp"
#include "system_info.hpp"

#define SYSTEM_RELEASE_PATH "/etc/os-release"
#define SYSTEM_RELEASE_DECL "PRETTY_NAME" // PRETTY_NAME="..."

namespace system_info
{
    void system_info_path_check() {

        if (!std::filesystem::exists(SYSTEM_RELEASE_PATH)) {
            std::cerr << "/etc/os-release does not release, did you install your linux distro correctly?" << std::endl;
        }
    }

    std::string system_os() {
        // We already check if file exists
        std::ifstream file(SYSTEM_RELEASE_PATH);
        std::string   line;

        while(std::getline(file, line))
        {
            std::stringstream   linestream(line);
            std::string         data;
            int                 val1;
            int                 val2;

            // If you have truly tab delimited data use getline() with third parameter.
            // If your data is just white space separated data
            // then the operator >> will do (it reads a space separated word into a string).
            std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).

            // Read the integers using the operator >>
            linestream >> val1 >> val2;

            if (line.find(SYSTEM_RELEASE_DECL, 0) != std::string::npos) {
                break;
            }
        }

        line.erase(0, 13);
        line.erase(line.size() - 1);

        return line;
    }
};
