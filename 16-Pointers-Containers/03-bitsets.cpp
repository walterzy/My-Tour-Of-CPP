#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>

using namespace std;

void binary(int i)
{
    bitset<8 * sizeof(int)> b = i; // assume 8-bit byte (see also ¡ì17.7)
    cout << b.to_string() << '\n'; // write out the bits of i
}


void binary2(int i)
{
    bitset<8 * sizeof(int)> b = i; // assume 8-bit byte (see also ¡ì17.7)
    cout << b << '\n'; // write out the bits of i
}

int main()
{
    bitset<9> bs1 {"110001111"};
    bitset<9> bs2 {0b1'1000'1111}; // binary literal using digit separators (¡ì1.4)
    bitset<9> bs3 = ~bs1; // complement: bs3=="001110000"
    bitset<9> bs4 = bs1&bs3; // all zeros
    bitset<9> bs5 = bs1<<2; // shift left: bs5 = "000111100"

    binary(123);
    binary2(123);
}