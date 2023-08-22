#include <string>
#include <iostream>
#include <iterator>     // std::ostream_iterator

std::ostream_iterator<std::string> oo {std::cout}; // write strings to cout

int main()
{
    // *oo = "Hello, "; // meaning cout << "Hello, "
    *oo = "Hello, "; // meaning cout << "Hello, "
    ++oo;
    *oo = "world!\n"; // meaning cout << "world!\n"

    return 0;
}

