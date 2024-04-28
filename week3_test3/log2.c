#include <stdint.h>
#include <stddef.h>

int ilog2_v1(int i)
{
    int log = -1;
    while (i) {
        i >>= 1;
        log++;
    }
    return log;
}

static size_t ilog2_v2(size_t i)
{
    size_t result = 0;
    while (i >= 65536) {
        result += 16;
        i >>= 16;
    }
    while (i >= 256) {
        result += 8;
        i >>= 8;
    }
    while (i >= 16) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}
int ilog32_v3(uint32_t v)
{
    return (31 - __builtin_clz(v));
}