#include "Options.h"

using std::cout;
using std::endl;

std::string Options::app_name = R"(CrcGen 0.0.1 - 2024 - T.Mark - sw@digitalspace.name
)";
std::string Options::help = R"(Available crc algorithms: --crc16 --ccitt --xmodem --crc32)";

std::map<std::string, Options::p_crc_fun> Options::option
{
    { "--crc16", Checksums::crc_16},
    { "--ccitt", Checksums::crc_ccitt},
    { "--xmodem", Checksums::crc_xmodem},
    { "--crc32", Checksums::crc_32},
};

// argv[0] - main exe module path
// argv[1] - argument of crc algo
// argv[2] - destinated file path
Options::Options(int argc, char **argv)
{
    cout << app_name << endl;

    //ctor
    try
    {
        if ( (argc < 3) || (argv[1][0] != '-' || argv[1][1] != '-') )
        {
            throw std::runtime_error("!");
        }
        else
        {
            checksum = option.at(argv[1]);
            cout << "Processing\t: " << argv[1] << endl;
            cout << "For file\t: " << argv[2] << endl;

            if (std::ifstream is {argv[2], std::ios::binary | std::ios::ate})
            {
                auto size = is.tellg();
                std::string str(size, '\0');
                is.seekg(0);

                if (is.get(&str[0], size).good())
                {
                    //C++
                    cout << "result\t\t: " << std::hex << std::uppercase << std::showbase << checksum((char*)str.c_str(), size) << endl;
                    //C
                    // printf("CRC\t\t: 0x%X\n", checksum((char*)str.c_str(), size));
                }
                else
                {
                    std::cerr << "Processing file " << argv[2] << " failed." << endl;
                    cout << is.gcount();
                }
            }
        }
    }
    catch (std::exception &e)
    {
        // cout << app_name << endl << help << endl;
        cout << "Error... Exiting..." << endl;
    }
}

Options::~Options()
{
    //dtor
}
