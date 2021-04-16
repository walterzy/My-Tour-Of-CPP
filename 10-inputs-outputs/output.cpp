#include <iostream>

void k()
{
    int b = 'b'; // note: char implicitly converted to int
    char c = 'c';
    std::cout << 'a' << b << c << std::endl;;
}

int main()
{
    k();

    return 0;
}