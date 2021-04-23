#include <string>
#include <iostream>
#include <iterator>     // std::ostream_iterator

std::ostream_iterator<string> oo {std::cout}; // wr ite str ings to cout

int main()
{
    // *oo = "Hello, "; // meaning cout<<"Hello, "
    *oo = "Hello, "; // meaning cout << "Hello, "
    // ++oo;
    // *oo = "world!\n"; // meaning cout<<"wor ld!\n"

    return 0;
}

