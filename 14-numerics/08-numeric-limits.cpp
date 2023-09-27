#include <limits>
#include <iostream>

using namespace std;

int main()
{
    static_assert(numeric_limits<char>::is_signed, "unsigned characters!");
    static_assert(100000 < numeric_limits<int>::max(), "small ints!");
    cout << "max int =" << numeric_limits<int>::max() << endl;
    cout << "max long long = " << numeric_limits<long long>::max() << endl;
    cout << "max float = " << numeric_limits<float>::max() << endl;
    cout << "max double float = " << numeric_limits<double>::max() << endl;
}

