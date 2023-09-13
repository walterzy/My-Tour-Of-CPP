#include <iostream>
#include <ranges>
#include <vector>
#include <tuple>

using namespace std::ranges;

void user(forward_range auto& r)
{
    auto odd = [](int x) { return x % 2; };
    for (int x : r | views::filter(odd) | views::take(3))
        std::cout << x <<' ';

    std::cout << std::endl;
}


int main()
{
    std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    user(v);

    return 0;
}
