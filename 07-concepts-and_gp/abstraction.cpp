#include <iostream>
#include <vector>
#include <list>
#include <algorithm>    // std::count_if

using std::cout;
using std::endl;

double sum(const std::vector<int>& v)
{
    double res = 0;
    for (auto x : v)
        res += x;
    return res;
}

template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p != last; ++p)
        res += *p;
    return res;
}


template<typename R, typename Val>       // a Range is something with begin() and end()
Val accumulate(const R& r, Val res = 0)
{
    for (auto p = begin(r); p != end(r); ++p)
        res += *p;
    return res;
}


void use(const std::vector<int>& vec, const std::list<double>& lst)
{
    auto sum = accumulate(begin(vec),end(vec),0.0); // accumulate in a double
    auto sum2 = accumulate(begin(lst),end(lst),sum);
    std::cout << sum << ", " << sum2 << std::endl;
}

int main()
{
    std::cout << sum({1,2,3}) << std::endl;
    std::vector<int> v = {1,2,3};
    std::list<double> l = {2,3,4};
    std::cout << accumulate(v.begin(), v.end(), 0) << std::endl;
    std::cout << accumulate(v, 10) << std::endl;

    use(v,l);
}
