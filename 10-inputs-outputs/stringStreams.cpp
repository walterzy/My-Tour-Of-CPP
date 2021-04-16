#include <iostream>
#include <sstream>
#include <ios>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ios_base;

void test()
{
    std::ostringstream oss;
    oss << "{temperature," << std::scientific << 123.4567890 << "}";
    cout << oss.str() << '\n';
}

template<typename Target = string, typename Source = string>
Target to(Source arg) // convert Source to Target
{
    std::stringstream interpreter;
    Target result;
    if (!(interpreter << arg) // write arg into stream
        || !(interpreter >> result) // read result from stream
        || !(interpreter >> std::ws).eof()) // stuff left in stream?
        throw std::runtime_error{"to<>() failed"};
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    // avoid significant overhead

    test();

    auto x1 = to<string,double>(1.2); // very explicit (and verbose)
    auto x2 = to<string>(1.2); // Source is deduced to double
    auto x3 = to<>(1.2); // Target is defaulted to string; Source is deduced to double
    auto x4 = to(1.2); // the <> is redundant;
    // Target is defaulted to string; Source is deduced to double
    cout << x1 << ", " << x2 << ", "  << x3 << ", "  << x4 << endl;

    return 0;
}
