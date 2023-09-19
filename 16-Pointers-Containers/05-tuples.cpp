#include <iostream>
#include <tuple>

using namespace std;

template <size_t N = 0, typename... Ts>
constexpr void print(tuple<Ts...> tup)
{
    if constexpr (N < sizeof...(Ts)) { // not yet at the end?
        cout << get<N>(tup) << ' '; // print the Nth element
        print<N + 1>(tup); // print the next element
    }
}

int main()
{
    tuple t0 {}; // empty
    tuple<string, int, double> t1 {"Shark", 123, 3.14}; // the type is explicitly specified
    auto t2 = make_tuple(string{"Herring"}, 10, 1.23); // the type is deduced to tuple<st
    tuple t3 {"Cod"s, 20, 9.99}; // the type is deduced to tuple<st

    print(t0); // no output
    print(t2); // Herring 10 1.23
    print(tuple{ "Norah", 17, "Gavin", 14, "Anya", 9, "Courtney", 9, "Ada", 0 });
}
