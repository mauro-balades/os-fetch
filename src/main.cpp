#include <iostream>

#include "system_info.hpp"
#include "utils.hpp"

int main() {

    std::cout << header::header1 << "   " << system_info::system_name_at_hostname() << std::endl;
    std::cout << header::header2 << std::endl;
    std::cout << header::header3 << "   " << sections::system_os_section << system_info::system_os() << std::endl;
    std::cout << header::header4 << std::endl;
    std::cout << header::header5 << std::endl;
    std::cout << header::header6 << std::endl;
    std::cout << header::header7 << std::endl;
    utils::print_half_line();
    return 0;
}
