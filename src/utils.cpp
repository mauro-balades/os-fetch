
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

#include <cstddef>

#include "system_info.hpp"
#include "system_info.hpp"

std::string new_line = "\n";

namespace header
{
    std::string header1 = " _______  _______    _______  _______  _______  _______  __   __ ";
    std::string header2 = "|       ||       |  |       ||       ||       ||       ||  | |  |";
    std::string header3 = "|   _   ||  _____|  |    ___||    ___||_     _||       ||  |_|  |";
    std::string header4 = "|  | |  || |_____   |   |___ |   |___   |   |  |       ||       |";
    std::string header5 = "|  |_|  ||_____  |  |    ___||    ___|  |   |  |      _||       |";
    std::string header6 = "|       | _____| |  |   |    |   |___   |   |  |     |_ |   _   |";
    std::string header7 = "|_______||_______|  |___|    |_______|  |___|  |_______||__| |__|";
}

namespace utils
{

    struct winsize get_term_size() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        return w;
    }

    std::string repeat(std::string str, const std::size_t n) {
        if (n == 0) {
            str.clear();
            str.shrink_to_fit();
            return str;
        } else if (n == 1 || str.empty()) {
            return str;
        }
        const auto period = str.size();
        if (period == 1) {
            str.append(n - 1, str.front());
            return str;
        }
        str.reserve(period * n);
        std::size_t m {2};
        for (; m < n; m *= 2) str += str;
        str.append(str.c_str(), (n - (m / 2)) * period);
        return str;
    }

    /* ================================================================ PRINTING UTILS */

    void print_half_line() {
        struct winsize w = utils::get_term_size();

        for (int i = 0; i < w.ws_col; i++) {

            // Used for better output purposes (like an old machine)
            std::this_thread::sleep_for(std::chrono::milliseconds(15));

            std::cout << "━";
            std::cout.flush();

        }

        std::cout << std::endl;
    }
};

