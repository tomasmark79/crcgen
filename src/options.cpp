//MIT License
//
//Copyright (c) 2024 Tomas Mark
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#include "Options.h"

using std::cout;
using std::endl;

std::string Options::app_name = R"(CrcGen 0.0.1 - Copyright (c) 2024 Tomas Mark)";
std::string Options::help = R"(
Usage: crcgen [algorithms] [file path to process]

Options:
    --ctc16  (BISYNCH, ARC, LHA, ZOO)
    --ccitt  (Designated by CCITT, KERMIT)
    --xmodem (XMODEM, ZMODEM, ACORN)
    --crc32  (ADCCP, PKZip, libPNG, AUTODIN II, Ethernet, FDDI)
)";

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
        if (argc == 1)
        {
            cout << help;
            return;
        }

        if ( (argc < 3) || (argv[1][0] != '-' || argv[1][1] != '-') )
        {
            throw std::runtime_error("!");
        }
        else
        {
            checksum = option.at(argv[1]);

            cout << "algorithms\t: " << argv[1] << endl;
            cout << "file\t\t: " << argv[2] << endl;

            if (std::ifstream is {argv[2], std::ios::binary | std::ios::ate})
            {
                auto size = is.tellg();
                std::string str(size, '\0');
                is.seekg(0);

                if (is.get(&str[0], size).good())
                {
                    //C++
                    cout << "CRCt\t\t: " << std::hex << std::uppercase << std::showbase << checksum((char*)str.c_str(), size) << endl;
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
        cout << "Error... Exiting..." << endl;
    }
}

Options::~Options()
{
    //dtor
}
