
#include <string>
#include <sstream>
#include <cstdlib>

#include <iostream>
#include <cstdlib>
#include <fstream>

#include <filesystem>
#include <limits.h>
#include <sys/utsname.h>

#include "system_info.hpp"
#include "utils.hpp"

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

    std::string system_name_at_hostname() {
        char *hostname;
        char *name;
        char host_temp[HOST_NAME_MAX+1];
        char name_temp[HOST_NAME_MAX+1];

        if (gethostname(host_temp,HOST_NAME_MAX+1) == -1)
        {
            std::cerr << "gethostname error";
            exit(1);
        }
        // ensure that NUL is at the end of the string
        host_temp[(HOST_NAME_MAX+1)-1] = '\0';

        if (getlogin_r(name_temp,HOST_NAME_MAX+1) == -1)
        {
            std::cerr << "getlogin error";
            exit(1);
        }
        // ensure that NUL is at the end of the string
        name_temp[(HOST_NAME_MAX+1)-1] = '\0';
        host_temp[(HOST_NAME_MAX+1)-1] = '\0';

        hostname = host_temp;
        name = name_temp;

        std::string res_name = name;
        std::string res_host = hostname;
        std::string at = "@";

        return res_name + at + res_host;
    }

    std::string system_hostname_line() {

        std::string hostname = system_name_at_hostname();
        size_t l = hostname.length();

        return utils::repeat(std::move("-"), l);
    }

    std::string system_uptime()
    {
        // Code from https://github.com/ameliaprogs/ponyfetch/blob/main/ponyfetch.cpp#L64

        int time;
        int hours;
        int hremainder;

        int minutes;
        int seconds;
        std::stringstream buffer;

        std::ifstream uptimefile;
        std::string delimiter = ".";
        std::string output;

        std::string result;

        uptimefile.open("/proc/uptime", std::ios::in);
        if(!uptimefile)
        {
            std::cerr << "/proc/uptime not found. Are you living in a time machine?" << std::endl;
        }

        buffer << uptimefile.rdbuf();

        std::string filestring = buffer.str();
        output = filestring.substr(0, filestring.find(delimiter));

        uptimefile.close();
        time = stoi(output);

        hours = (int)time / 3600;
        hremainder = time % 3600;

        minutes = (int)hremainder / 60;
        seconds = hremainder % 60;

        std::stringstream outputstr;
        outputstr << hours << " hours " << minutes << " minutes " << seconds << " seconds ";
        result = outputstr.str();

        return result;
    }

    std::string system_terminal() {
        std::stringstream safereturn;

        std::string var = getenv("TERM");
        safereturn << var;

        std::string res = safereturn.str();

        return res;
    }

    std::string system_version() {
      utsname sys_info;

      uname(&sys_info);
      return sys_info.version;
    }

    std::string system_machine() {
      utsname sys_info;

      uname(&sys_info);
      return sys_info.machine;
    }
};

namespace sections
{
    std::string system_term_section = "TERM    : "; // I know, this is disgusting
    std::string system_os_section = "OS      : ";
    std::string system_uptime_section = "UPTIME  : ";
    std::string system_version = "VERSION : ";
    std::string system_machine = "MACHINE : ";
};
