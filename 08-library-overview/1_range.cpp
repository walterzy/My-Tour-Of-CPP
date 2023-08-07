#include <vector>
#include <algorithm>

using namespace std;

void f(vector<int>& v)
{
    sort(v.begin(),v.end()); // OK
    //sort(v); // error: no matching function (in std)

    ranges::sort(v); // OK

    using ranges::sort; // sort(v) OK from here on
    sort(v); // OK
}

main()
{
    std:vector v = {2,3,1,4,5};

    f(v);
}
