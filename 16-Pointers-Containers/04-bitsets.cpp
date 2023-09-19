#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
 
int main()
{
    typedef std::size_t length_t, position_t; // the hints
 
    // constructors:
    constexpr std::bitset<4> b1;
    constexpr std::bitset<4> b2{0xA}; // == 0B1010
    std::bitset<4> b3{"0011"}; // can also be constexpr since C++23
    std::bitset<8> b4{"ABBA", length_t(4), /*0:*/'A', /*1:*/'B'}; // == 0B0000'0110
 
    // bitsets can be printed out to a stream:
    std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';
 
    std::bitset<8> b5(0xfff);      // [1,1,1,1,1,1,1,1]
    std::bitset<8> b6(0xfff0);      // [1,1,1,1,0,0,0,0]
    std::cout << "b5:" << b5 << "; b6:" << b6 << '\n';

    // char* constructor using custom digits (5)
    std::bitset<8> b7("YXXXYYXY", 8, 'X', 'Y'); // [1,0,0,0,1,1,0,1]
    std::bitset<8> b8{"ABBA", length_t(4), /*0:*/'B', /*1:*/'A'}; // == 0B0000'1001
    std::cout << "b7:" << b7 << "; b8:" << b8 << '\n';

    // bitset supports bitwise operations:
    b3 |= 0b0100; assert(b3 == 0b0111);
    b3 &= 0b0011; assert(b3 == 0b0011);
    b3 ^= std::bitset<4>{0b1100}; assert(b3 == 0b1111);
 
    // operations on the whole set:
    b3.reset(); assert(b3 == 0);
    b3.set(); assert(b3 == 0b1111);
    assert(b3.all() && b3.any() && !b3.none());
    b3.flip(); assert(b3 == 0);
 
    // operations on individual bits:
    b3.set(position_t(1), true); assert(b3 == 0b0010);
    b3.set(position_t(1), false); assert(b3 == 0);
    b3.flip(position_t(2)); assert(b3 == 0b0100);
    b3.reset(position_t(2)); assert(b3 == 0);
 
    // subscript operator[] is supported:
    b3[2] = true; assert(true == b3[2]);
 
    // other operations:
    assert(b3.count() == 1);
    assert(b3.size() == 4);
    assert(b3.to_ullong() == 0b0100ULL);
    assert(b3.to_string() == "0100");
}
