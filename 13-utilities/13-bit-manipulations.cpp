#include <iostream>
#include <bit>
#include <cinttypes>

using namespace std;

void use(unsigned int ui)
{
    int x0 = bit_width(ui); // the smallest number of bits needed to represent
    unsigned int ui2 = rotl(ui, 8); // rotate left 8 bits (note: doesn't change ui)
    int x1 = popcount(ui); // the number of 1s in ui
    // ...
}

int main()
{
    double val = 7.2;
    auto x = bit_cast<uint64_t>(val); // get the bit representation of a 64-bit floating point number
    auto y = bit_cast<uint64_t>(&val); // get the bit representation of a 64-bit pointer

    struct Word { std::byte b[8]; };
    std::byte buffer[1024];
    // ...
    auto p = bit_cast<Word *>(& buffer[8]); // p points to 8 bytes
    auto i = bit_cast<int64_t>(* p); // convert those 8 bytes to an integer

    std::cout << "x = " << x << "; y = " << y << "; p = " << p << "; i = " << i << std::endl;
}