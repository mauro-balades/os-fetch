#include <iostream>
#include <cstring>

#include "system_info.hpp"
#include "utils.hpp"
#include "colors.hpp"

int WITH_COLOR = 1;
int DELAY = 60;

void print_with_color(std::string color, std::string text) {
  if (WITH_COLOR)
    std::cout << color << text << RESET << std::endl;
  else
    std::cout << text << std::endl;
}

int main(int argc, char *argv[]) {

    if (argc > 1) {

      if (strcmp(argv[1], "--no-color") == 0 || strcmp(argv[1], "-n") == 0)
        WITH_COLOR = 0;
      else if (strcmp(argv[1], "--delay") == 0 || strcmp(argv[1], "-d") == 0)
        DELAY = atoi(argv[2]);
    }

    // HEADER 1
    std::cout << header::header1 << "   ";
    print_with_color(BLU, system_info::system_name_at_hostname());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 2
    std::cout << header::header2 << "   ";
    print_with_color(BOLD, system_info::system_hostname_line());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 3
    std::cout << header::header3 << "   " << sections::system_os_section;
    print_with_color(BLU, system_info::system_os());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 4
    std::cout << header::header4 << "   " << sections::system_uptime_section;
    print_with_color(BLU, system_info::system_uptime());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 5
    std::cout << header::header5 << "   " << sections::system_term_section;
    print_with_color(BLU, system_info::system_terminal());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 6
    std::cout << header::header6 << "   " << sections::system_version;
    print_with_color(BLU, system_info::system_version());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // HEADER 7
    std::cout << header::header7 << "   " << sections::system_machine;
    print_with_color(BLU, system_info::system_machine());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // utils::print_half_line();
    return 0;
}
