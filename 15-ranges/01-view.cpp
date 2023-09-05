#include <iostream>
#include <ranges>
#include <vector>

using namespace std::ranges;

void user(forward_range auto& r)
{
    filter_view v {r, [](int x) { return x % 2; } }; // view (only) odd numbers from r
    take_view tv {v, 100 };

    std::cout << "odd numbers: ";
    for (int x : v)
        std::cout << x <<' ';

    for (int x : take_view{v, 3})
        std::cout << x <<' ';
}

int main()
{
    std::vector v = {1,2,3,4,5};

    auto odd = [](int x) { return 0 != (x & 1); };
    filter_view(v, odd);

    return 0;
}
