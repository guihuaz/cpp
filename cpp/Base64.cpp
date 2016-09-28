#include "Base64.h"


// reference: https://github.com/google/closure-compiler/blob/master/src/com/google/debugging/sourcemap/Base64.java

const char BASE64_MAP[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

namespace zgh {
char to_base64(int value)
{

    if (value >= 0 && value <= 63)
        return BASE64_MAP[value];

    throw std::invalid_argument("Value must be in range [0, 63]");
}

int from_base64(char c)
{
    static class Base64DecodeMap
    {
    public:
        char _map[256] = { -1 };

        Base64DecodeMap()
        {
            for (int i = 0; i < 64; i++)
            {
                _map[BASE64_MAP[i]] = i;
            }
        }
    } decodeMap;

    int value = decodeMap._map[c];
    
    if (value == -1)
        throw std::invalid_argument("invalid char");

    return value;
}

} // namespace zgh