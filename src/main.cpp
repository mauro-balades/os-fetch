#include <iostream>

#include "system_info.hpp"
#include "utils.hpp"

int main() {

    std::cout << header::header1 << "   " << system_info::system_name_at_hostname() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header2 << "   " << system_info::system_hostname_line() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header3 << "   " << sections::system_os_section << system_info::system_os() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header4 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header5 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header6 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << header::header7 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    utils::print_half_line();
    return 0;
}
