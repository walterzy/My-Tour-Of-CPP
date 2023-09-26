#include <iostream>
#include <cmath>
#include <cerrno>

using namespace std;

int main()
{
    errno = 0; // clear old error state
    double d = sqrt(-1);

    if (errno == EDOM)
        cerr << "sqrt() not defined for negative argument\n";
    
    errno = 0; // clear old error state
    double dd = pow(numeric_limits<double>::max(), 2);
    
    if (errno == ERANGE)
        cerr << "result of pow() too large to represent as a double\n";
}