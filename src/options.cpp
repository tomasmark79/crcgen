#include "Options.h"

std::string Options::app_name = R"(
CrcGen v 0.0.1 - Tomas Mark - tomas@digitalspace.name
)";

std::string Options::help = R"(
options:
--crc16
--crc32
)";

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
        if (argc < 3)
        {
            throw std::runtime_error("!");
        }
        if (argv[1][0] == '/')
        {
            argv[1][0] = '-'; argv[2][0] = '-';
        }

        checksum = option.at(argv[1]);
        std::cout << app_name << std::endl;

        std::cout << "Work folder\t: " << argv[0] << std::endl;
        std::cout << "Option\t\t: " << argv[1] << std::endl;
        std::cout << "File to process\t: " << argv[2] << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << app_name << std::endl << help << std::endl;
        exit (1);
    }
}

Options::~Options()
{
    //dtor
}
