#ifndef CHECKSUMS_H
#define CHECKSUMS_H
#include "boost\crc.hpp"
class Checksums
{
    public:

        Checksums();
        virtual ~Checksums();

        static unsigned crc16(void *b, size_t s);
        static unsigned crc32(void *b, size_t s){};
        static unsigned crc64(void *b, size_t s){};

    protected:

    private:
};

#endif // CHECKSUMS_H
