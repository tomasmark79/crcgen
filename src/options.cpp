#include "options.h"

std::map<std::string, options::p_crc_fun> options::option
{
    { "--crc16", Checksums::crc16},
    { "--crc32", Checksums::crc32},
};

options::options(int argc, char **argv)
{
    //ctor
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("!");
        }
        if (argv[1][0] == '/')
        {
            argv[1][0] = '-'; argv[2][0] = '-';
        }
        checksum = option.at(argv[1]);
        std::cout << checksum << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "wrong input" << std::endl;
        exit (1);

    }
}

options::~options()
{
    //dtor
}
