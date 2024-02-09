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

#include "Checksums.h"

Checksums::Checksums()
{
    //ctor
}

Checksums::~Checksums()
{
    //dtor
}

unsigned Checksums::crc_16(void *b, size_t s)
{
    // BISYNCH, ARC, LHA, ZOO
    boost::crc_basic<16> crc( 0x8005u, 0u, 0u, true, true );
    crc.process_bytes( b, s );
    return crc.checksum();
}

unsigned Checksums::crc_ccitt(void *b, size_t s)
{
    // Designated by CCITT (Comité Consultatif International Télégraphique et Téléphonique), KERMIT
    boost::crc_optimal<16, 0x1021, 0, 0, true, true> crc;
    crc.process_bytes( b, s );
    return crc.checksum();
}

unsigned Checksums::crc_xmodem(void *b, size_t s)
{
    // XMODEM, ZMODEM, ACORN
    boost::crc_optimal<16, 0x1021, 0, 0, false, false> crc;
    crc.process_bytes( b, s );
    return crc.checksum();
}

unsigned Checksums::crc_32(void *b, size_t s)
{
    // ADCCP, PKZip, libPNG, AUTODIN II, Ethernet, FDDI
    boost::crc_optimal<32, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, true, true> crc;
    crc.process_bytes( b, s );
    return crc.checksum();
}
