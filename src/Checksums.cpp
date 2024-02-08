#include "Checksums.h"

Checksums::Checksums()
{
    //ctor
}

Checksums::~Checksums()
{
    //dtor
}

unsigned Checksums::crc16(void *b, size_t s)
{
    boost::crc_basic<16> crc( 0x8005u, 0u, 0u, true, true );
    crc.process_bytes( b, s );
    return crc.checksum();
}

unsigned Checksums::crc32(void *b, size_t s)
{
    boost::crc_basic<32> crc( 0x8005u, 0u, 0u, true, true );
    crc.process_bytes( b, s );
    return crc.checksum();
}

unsigned Checksums::crc64(void *b, size_t s)
{
    boost::crc_basic<64> crc( 0x8005u, 0u, 0u, true, true );
    crc.process_bytes( b, s );
    return crc.checksum();
}
