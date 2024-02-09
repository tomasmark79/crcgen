#include "Options.h"

using std::cout;
using std::endl;

std::string Options::app_name = R"(
CrcGen 0.0.1 - 2024 - T.Mark - sw@digitalspace.name
)";
std::string Options::help = R"(Available options: --crc16 --crc_ccitt --crc_xmodem --crc_32)";

std::map<std::string, Options::p_crc_fun> Options::option
{
    { "--crc_16", Checksums::crc_16},
    { "--crc_ccitt", Checksums::crc_ccitt},
    { "--crc_xmodem", Checksums::crc_xmodem},
    { "--crc_32", Checksums::crc_32},
};

Options::Options(int argc, char **argv)
{
    //ctor
    try
    {
        if ( (argc < 3) || (argv[1][0] != '-' || argv[1][1] != '-') )
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
            auto size = is.tellg();
            std::string str(size, '\0');
            is.seekg(0);

            // if (is.read(&str[0], size).good())
            if (is.get(&str[0], size).good())
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
            else
            {
                std::cerr << "Processing file " << argv[2] << " failed." << endl;
                cout << is.gcount();
            }

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
