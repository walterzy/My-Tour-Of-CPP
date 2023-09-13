#include <iostream>
#include <ranges>
#include <vector>
#include <tuple>

using namespace std::ranges;

void user(forward_range auto& r)
{
    filter_view v {r, [](int x) { return x % 2; } }; // view (only) odd numbers from r
    take_view tv {v, 100 };

    std::cout << "odd numbers: " << std::endl;
    for (int x : v)
        std::cout << x <<' ';

    std::cout << std::endl;

    for (int x : take_view{v, 3})
        std::cout << x <<' ';

    std::cout << std::endl;

    for (int x : take_view{ filter_view { r, [](int x) { return x % 2; } }, 3 })
        std::cout << x <<' ';

    std::cout << std::endl;
}

void test()
{
    const std::vector<std::tuple<int, char, std::string>> vt
    {
        {1, 'A', "¦Á"},
        {2, 'B', "¦Â"},
        {3, 'C', "¦Ã"},
        {4, 'D', "¦Ä"},
        {5, 'E', "¦Å"},
    };
 
    for (int const e : std::views::elements<0>(vt))
        std::cout << e << ' ';
    std::cout << '\n';
 
    double s = 0;
    for (auto x: std::views::elements<0>(vt))
        s += x;
    std::cout << "average = " << s / vt.size() << std::endl;

    for (char const e : vt | std::views::elements<1>)
        std::cout << e << ' ';
    std::cout << '\n';
 
    for (std::string const& e : std::views::elements<2>(vt))
        std::cout << e << ' ';
    std::cout << '\n';    
}

int main()
{
    std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    user(v);

    test();

    return 0;
}
