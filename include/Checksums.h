#ifndef CHECKSUMS_H
#define CHECKSUMS_H

#include "boost\crc.hpp"

class Checksums
{
    public:

        Checksums();
        virtual ~Checksums();

        static unsigned crc_16 (void *b, size_t s);
        static unsigned crc_ccitt (void *b, size_t s);
        static unsigned crc_xmodem (void *b, size_t s);
        static unsigned crc_32 (void *b, size_t s);

    protected:

    private:
};

#endif // CHECKSUMS_H
