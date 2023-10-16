#include <iostream>
#include <string>
#include <complex>

void print_with_zeros(auto const note, std::string const& s)
{
    std::cout << note;
    for (const char c : s)
        c ? std::cout << c : std::cout << "₀";
    std::cout << " (size = " << s.size() << ")\n";
}

constexpr std::complex<double> operator""i(long double arg) // imaginary literal
{
    return {0, static_cast<double>(arg)};
}

int main()
{
    using namespace std::string_literals;
 
    std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    print_with_zeros("s1: ", s1);
    print_with_zeros("s2: ", s2);
 
    std::cout << "abcdef"s.substr(1,4) << '\n';

    std::complex<double> z = 2.7182818 + 6.283185i;
    std::cout << z << std::endl;
}

