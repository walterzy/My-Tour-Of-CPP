#include <concepts>
#include <iostream>
#include <string>

using namespace std::literals;
using namespace std::ranges;

template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::same_as<size_t>;
    { std::hash<T>{}(a) } -> std::convertible_to<size_t>;
};

template<Hashable T>
void f(T t) {
    const std::size_t n = std::hash<T>{}(t);
    std::cout << t << ": " << n << std::endl;
};

struct meow {};

template<typename Seq, typename Num>
Num sum(Seq s, Num v)
{
    for (const auto& x : s)
        v += x;
    return v;
};

template<typename T>
concept Equality_comparable = requires (T a, T b) {
    { a == b } -> std::same_as<bool>; // compare Ts with ==
    { a != b } -> std::same_as<bool>; // compare Ts with !=
};

struct S { int a; };

template<typename T, typename T2 = T>
concept Equality_comparable2 = requires (T a, T2 b) {
    { a == b } -> std::same_as<bool>; // compare a T to a T2 with ==
    { a != b } -> std::same_as<bool>; // compare a T to a T2 with !=
    { b == a } -> std::same_as<bool>; // compare a T2 to a T with ==
    { b != a } -> std::same_as<bool>; // compare a T2 to a T with !=
};

template<class S>
using Value_type = typename S::value_type; // the type of C's elements
//using Iterator_type = typename S::iterator_type; // the type of C's iterator


template<typename T, typename U = T>
concept Number =
    requires(T x, U y) { // Something with arithmetic operations and a zero
        x + y; x - y; x * y; x / y;
        x += y; x -= y; x *= y; x /= y;
        x = x; // copy
        x = 0;
};

template<typename T, typename U = T>
concept Arithmetic = Number<T,U> && Number<U,T>;

template<typename S>
concept Sequence = requires (S a) {
    typename range_value_t<S>; // S must have a value type
    typename iterator_t<S>; // S must have an iterator typ
    { a.begin() } -> std::same_as<iterator_t<S>>; // S must have a begin() that returns an iterator
    { a.end() } -> std::same_as<iterator_t<S>>;
    requires std::input_iterator<iterator_t<S>>; // S's iterator must be an input_iterator
    requires std::same_as<range_value_t<S>, std::iter_value_t<S>>;
};

int main() {
    f("abc"s);
    //f(meow{});
    
    static_assert(Equality_comparable<int>);

    // fails because structs don't automatically get == and !=
    //static_assert(Equality_comparable<S>);

    static_assert(Equality_comparable2<int,double>); // succeeds
    static_assert(Equality_comparable2<int>); // succeeds (T2 is defaulted to int)
    //static_assert(Equality_comparable2<int,string>); // fails
}
