#include <iostream>
#include <cstring>

#include "system_info.hpp"
#include "utils.hpp"
#include "colors.hpp"

// we can't make them as a macros
int WITH_COLOR = 1;
int DELAY = 60;

void print_with_color(std::string color, std::string text) {
  if (WITH_COLOR)
    std::cout << color << text << RESET << std::endl;
  else
    std::cout << text << std::endl;
}

// char, printf needs a (char *) not std::string
const char *color(const char *color) {
  return WITH_COLOR ? color : "";
}

void print_help() {
  // Do printf for better string formating
  printf("\nOs-fetch help section\n");
  printf("\n");
  printf("Usage:\n");
  printf("  %sosfetch%s [args...]\n", color(CYN), color(RESET));
  printf("\n");
  printf("Available options:\n");
  printf("  --help, -h         %s#%s Prints out this message\n", color(CYN), color(RESET));
  printf("  --delay, -d        %s#%s Time to sleep before printing out a new line (defaults to 60)\n", color(CYN), color(RESET));
  printf("  --no-color, -n     %s#%s Print message with out color\n\n", color(CYN), color(RESET));
  exit(0);
}

int main(int argc, char *argv[]) {

    if (argc > 1) {

      for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--no-color") == 0 || strcmp(argv[i], "-n") == 0)
          WITH_COLOR = 0;
        else if (strcmp(argv[i], "--delay") == 0 || strcmp(argv[i], "-d") == 0)
          DELAY = atoi(argv[2]);
        else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
          print_help();
        } else {
          std::cout << "Invalid option: " << argv[i] << std::endl;
          print_help();
        }
      }
    }

    // ========================================== HEADER 1
    std::cout << header::header1 << "   ";
    print_with_color(BLU, system_info::system_name_at_hostname());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 2
    std::cout << header::header2 << "   ";
    print_with_color(BOLD, system_info::system_hostname_line());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 3
    std::cout << header::header3 << "   " << sections::system_os_section;
    print_with_color(BLU, system_info::system_os());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 4
    std::cout << header::header4 << "   " << sections::system_uptime_section;
    print_with_color(BLU, system_info::system_uptime());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 5
    std::cout << header::header5 << "   " << sections::system_term_section;
    print_with_color(BLU, system_info::system_terminal());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 6
    std::cout << header::header6 << "   " << sections::system_version;
    print_with_color(BLU, system_info::system_version());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    // ========================================== HEADER 7
    std::cout << header::header7 << "   " << sections::system_machine;
    print_with_color(BLU, system_info::system_machine());

    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

    return 0;
}
