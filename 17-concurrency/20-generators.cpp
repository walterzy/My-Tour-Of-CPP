#include <generator>
#include <iostream>
#include <ranges>
 
std::generator<char> letters(char first)
{
    for (;; co_yield first++);
}
 
int main()
{
    for (const char ch : letters('a') | std::views::take(26))
        std::cout << ch << ' ';
    std::cout << '\n';
}
