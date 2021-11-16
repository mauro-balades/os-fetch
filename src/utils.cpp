
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

#include "system_info.hpp"
#include "system_info.hpp"

std::string new_line = "\n";
std::string header = R"(
 _______  _______    _______  _______  _______  _______  __   __
|       ||       |  |       ||       ||       ||       ||  | |  |
|   _   ||  _____|  |    ___||    ___||_     _||       ||  |_|  |
|  | |  || |_____   |   |___ |   |___   |   |  |       ||       |
|  |_|  ||_____  |  |    ___||    ___|  |   |  |      _||       |
|       | _____| |  |   |    |   |___   |   |  |     |_ |   _   |
|_______||_______|  |___|    |_______|  |___|  |_______||__| |__|
)";

namespace utils
{

    struct winsize get_term_size() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        return w;
    }

    /* ================================================================ PRINTING UTILS */

    void print_os_fetch_header() {
        size_t pos = 0;
        std::string token;
        while ((pos = header.find(new_line)) != std::string::npos) {

            // Used for better output purposes (like an old machine)
            std::this_thread::sleep_for(std::chrono::milliseconds(60));

            token = header.substr(0, pos);
            std::cout << token << std::endl;

            header.erase(0, pos + new_line.length());
        }

        std::cout << std::endl;
    }

    void print_half_line() {
        struct winsize w = utils::get_term_size();

        for (int i = 0; i < w.ws_col / 1.5; i++) {

            // Used for better output purposes (like an old machine)
            std::this_thread::sleep_for(std::chrono::milliseconds(15));

            std::cout << "━";
            std::cout.flush();

        }

        std::cout << std::endl;
    }
};

