#include <algorithm>
#include <iostream>
#include <ranges>

template<class Iter>
class Sentinel {
public:
    Sentinel(int ee) : end(ee) { }
    Sentinel() :end(0) {} // Concept sentinel_for requires a default constructor
    friend bool operator==(const Iter& p, Sentinel s) { return (*p == s.end); }
    friend bool operator!=(const Iter& p, Sentinel s) { return !(p == s); }

private:
    std::iter_value_t<const char *> end; // the sentinel value
};

int main()
{
    // check the Sentinel for C-style strings
    static_assert(std::sentinel_for<Sentinel<const char *>, const char *>); 

    const char aa[] = "Hello, World!\nBye for now\n";
    std::ranges::for_each(aa, Sentinel<const char*>('\n'), [](const char x) { std::cout << x; });

    return 0;
}
