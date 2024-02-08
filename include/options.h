#ifndef OPTIONS_H
#define OPTIONS_H

// Standard C++ Libraries
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

#include "Checksums.h"

class Options
{
    public:
        using p_crc_fun = void(*)(void);
        Options(int argc, char **argv);
        virtual ~Options();

    protected:

    private:
        static std::map<std::string, p_crc_fun> option;
        static std::string help;
        p_crc_fun checksum;


};

#endif // OPTIONS_H
