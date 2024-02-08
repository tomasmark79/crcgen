#include "Options.h"

std::map<std::string, Options::p_crc_fun> Options::option
{
    { "--crc16", Checksums::crc16},
    { "--crc32", Checksums::crc32},
};

Options::Options(int argc, char **argv)
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

Options::~Options()
{
    //dtor
}
