#include <iostream>
// #include <string>
// #include <vector>
#include <iomanip>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using std::cin;
//using std::vector;


using namespace std::chrono; // in sub-namespace std::chrono; see ¡ì3.3

int main()
{
    cout << 1234 << ',' << std::hex << 1234 << ',' << std::oct << 1234 << '\n'; // print 1234,4d2,2322
    
    constexpr double d = 123.456;
    cout << d << "; " // use the default format for d
        << std::scientific << d << "; " // use 1.123e2 style format for d
        << std::hexfloat << d << "; " // use hexadecimal notation for d
        << std::fixed << d << "; " // use 123.456 style format for d
        << std::defaultfloat << d << '\n'; // use the default format for d

    cout.precision(8);
    cout << "precision(8): " << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456.0 << '\n';
    cout.precision(4);
    cout << "precision(4): " << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';
    cout << 1234.56789 << '\n';

    cout << "birthday: " << std::chrono::November/28/2021 << '\n';
    cout << "zt: " << zoned_time{current_zone(), system_clock::now()} <<'\n';

    printf("an int %d and a string '%s'\n",123,"Hello!");

    // default, hexadecimal, octal, decimal, binary
    cout << std::format("{} 0x{:x} 0o{:o} 0b{:d} {:b}\n", 1234,1234,1234,1234,1234);
    cout << std::format("{0:} {0:x} {0:o} {0:d} {0:b}\n", 1234); 

    // default, scientific, hexfloat, fixed, default
    cout << std::format("{0:}; {0:e}; {0:a}; {0:f}; {0:g}\n",123.456);
    
    cout << std::format("precision(8): {:.8} {} {}\n", 1234.56789, 1234.56789, 123456);
    cout << std::format("precision(4): {:.4} {} {}\n", 1234.56789, 1234.56789, 123456);
    cout << std::format("{}\n", 1234.56789);

    auto ymd = 2021y/std::chrono::March/30;
    cout << "birthday: " << ymd << '\n';

    std::chrono::weekday cur_weekday{ std::chrono::sys_days{ ymd } };

    cout << std::format("ymd: {}-{}-{} is: {}\n", 
        ymd.year(), ymd.month(), ymd.day(), 
        std::chrono::weekday { std::chrono::sys_days{ ymd } }) << endl;

    cout << ymd.year() << '-' << std::setw(2) << std::setfill('0')
            << ymd.month() << '-' << ymd.day() << " is " << cur_weekday << endl;

    string buf;
    std::format_to(back_inserter(buf), "iterator: {} {}\n", "Hi! ", 2022);
    cout << buf; // iterator: Hi! 2022

    return 0;
}
