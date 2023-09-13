#include <iostream>
#include <ranges>
#include <complex>
#include <cmath>

void test()
{
    for (auto const x : std::ranges::iota_view(42, 52)) // 42 43 44 45 46 47 48 49 50 51
        std::cout << x << ' ';
    
    std::cout << '\n';

//    for (auto x : std::ranges::istream_view<std::complex<double>>(std::cin))
//        std::cout << x << '\n';

    auto cplx = std::ranges::istream_view<std::complex<double>>(std::cin);
    for (auto x : std::ranges::transform_view(cplx, [](auto z){ return z * z * z;}))
        std::cout << x << '\n';

    std::cout << '\n';
}

int main()
{
    test();

    return 0;
}
