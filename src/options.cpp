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

        // get selected pointer to the function
        checksum = option.at(argv[1]);

        cout << app_name << endl;
        cout << "processing\t: " << argv[1] << endl;
        cout << "at\t\t: " << argv[2] << endl;
        if (std::ifstream is {argv[2], std::ios::binary | std::ios::ate})
        {

// todo huge file size support
            auto size = is.tellg();
            std::string str(size, '\0');
            is.seekg(0);
            if (is.read(&str[0], size))
            {
                try
                {
                    cout << "result\t\t: " << std::hex << "0x" << checksum((char*)str.c_str(), size) << endl;
                }
                catch (std::exception &e)
                {
                    cout << e.what() << endl;
                }

            }
            cout << is.gcount();
        }
    }
    catch (std::exception &e)
    {
        cout << app_name << endl << help << endl;
        cout << "-> Wrong option?\t Exiting" << endl;
    }
}

Options::~Options()
{
    //dtor
}
