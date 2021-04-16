#include <iostream>
// #include <string>
// #include <vector>
// #include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;
//using std::vector;



int main()
{
    cout << 1234 << ',' << std::hex << 1234 << ',' << std::oct << 1234 << '\n'; // pr int 1234,4d2,2322
    
    constexpr double d = 123.456;
    cout << d << "; " // use the default format for d
        << std::scientific << d << "; " // use 1.123e2 style format for d
        << std::hexfloat << d << "; " // use hexadecimal notation for d
        << std::fixed << d << "; " // use 123.456 style format for d
        << std::defaultfloat << d << '\n'; // use the default format for d

    cout.precision(8);
    cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456.0 << '\n';
    cout.precision(4);
    cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';
    cout << 1234.56789 << '\n';

    return 0;
}
