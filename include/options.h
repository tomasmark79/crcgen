#ifndef OPTIONS_H
#define OPTIONS_H

// Standard C++ Libraries
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

#include "Checksums.h"

class options
{
    public:
        using p_crc_fun = void(*)(void);
        options(int argc, char **argv);
        virtual ~options();

    protected:

    private:
        static std::map<std::string, p_crc_fun> option;
        p_crc_fun checksum;


};

#endif // OPTIONS_H
