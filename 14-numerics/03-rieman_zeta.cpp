#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
 
int main()
{
    constexpr auto pi = std::numbers::pi;
 
    // spot checks for well-known values
    for (const double x : {-1.0, 0.0, 0.5, 1.0, 2.0})
        std::cout << std::format("rz({})\t= {:+.5f}\n", x, std::riemann_zeta(x));
    std::cout << std::format("pi*pi/6\t= {:+.5f}\n", pi * pi / 6);
}
