#include <math.h>
#include <iostream>

bool isSquare(unsigned long y)
{
    unsigned long w = 1729 * y * y + 1;

    unsigned long u = sqrt(w);

    std::cout << "y = " << y << ", w = " << w << ", u = " << u << ", w - u**2 = " << w - u * u << std::endl;

    return (u * u == w) ? true : false;
}


int main()
{
    unsigned long i = 90175380;

    while (1)
    {
        if (isSquare(i))
        {
            std::cout << "found " << i << std::endl;
            break;
        }
        i++;
    }

    return 0;
}