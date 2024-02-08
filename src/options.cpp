#include "Options.h"

using std::cout;
using std::endl;

std::string Options::app_name = R"(CrcGen 0.0.1 - 2024 - T.Mark - sw@digitalspace.name
)";
std::string Options::help = R"(Available options: --crc16 --crc32 --crc64)";

std::map<std::string, Options::p_crc_fun> Options::option
{
    { "--crc16", Checksums::crc16},
    { "--crc32", Checksums::crc32},
    { "--crc64", Checksums::crc64},
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

        if (argv[1][0] != '-' || argv[1][1] != '-')
        {
            throw std::runtime_error("!");
        }

        checksum = option.at(argv[1]);


        cout << app_name << endl;

        // cout << "Work folder\t: " << argv[0] << endl;
        cout << "processing\t: " << argv[1] << endl;
        cout << "at\t\t: " << argv[2] << endl;
        cout << "result\t\t: " << "AAA" << endl;
    }
    catch (std::exception &e)
    {
        cout << app_name << endl << help << endl;
        // cout << endl << "Exception occured: " << e.what() << ". -> Wrong option?" << endl;
        cout << "-> Wrong option?\t Exiting" << endl;
    }
}

Options::~Options()
{
    //dtor
}
