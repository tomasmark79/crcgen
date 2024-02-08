#ifndef OPTIONS_H
#define OPTIONS_H

// Standard C++ Libraries
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

#include "Checksums.h"

class Options
{
    public:
        using p_crc_fun = unsigned(*)(void*, size_t);
        Options(int argc, char **argv);
        virtual ~Options();

    protected:

    private:
        static std::map<std::string, p_crc_fun> option;
        static std::string app_name;
        static std::string help;

        p_crc_fun checksum;
};

#endif // OPTIONS_H
