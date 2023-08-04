#include <iostream>
#include <string>

using namespace std::literals;

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

// template<typename C>
// using Value_type = typename C::value_type; // the type of C’s elements
// using Iterator_type = typename C::iterator_type; // the type of C’s elements

// template<typename S>
// concept Sequence = requires(S a) {
//     typename Value_type<S>; // S must have a value type.
//     typename Iterator_type<S>; // S must have an iterator type.
//     { begin(a) } -> Iterator_type<S>; // begin(a) must return an iterator
//     { end(a) } -> Iterator_type<S>; // end(a) must return an iterator
//     requires Same_type<Value_type<S>,Value_type<Iterator_type<S>>>;
//     requires Input_iterator<Iterator_type<S>>;
// };


int main() {
    f("abc"s);
    //f(meow{});
    
    static_assert(Equality_comparable<int>);

    // fails because structs don’t automatically get == and !=
    //static_assert(Equality_comparable<S>);

    static_assert(Equality_comparable2<int,double>); // succeeds
    static_assert(Equality_comparable2<int>); // succeeds (T2 is defaulted to int)
    //static_assert(Equality_comparable2<int,string>); // fails
}
