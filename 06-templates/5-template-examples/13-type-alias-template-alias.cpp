#include <iostream>


// Type Alias Declaration in C++
// There is no difference between a type alias declaration and typedef declaration.
using uint = unsigned int;

template<typename T>
class Vector {
public:
    using value_type = T; // Alias for the class Template T
    
    void print(value_type x) {
        std::cout << "x = " << x << "\n";
    }
    
    // ...
};


template <typename Key, typename Value>
class Map {
private:
    Key key_;
    Value value_;
};


// Alias Template
template<typename Value>
using StringMap = Map<std::string, Value>;


template <class T>
    constexpr T viscosity = 0.4;
auto vis2 = 2 * viscosity<double>;
auto vis3 = 2 * viscosity<int>;

template<typename T, typename T2>
    constexpr bool Assignable = std::is_assignable<T&, T2>::value; 
    // is_assignable is a type trait (§13.9.1)

template<typename T>
void testing()
{
    static_assert(Assignable<T&,double>, "can't assign a double");
    static_assert(Assignable<T&,std::string>, "can't assign a string");
}

template<typename T>
void update(T& target)
{
    // ...
    if constexpr(std::is_pod<T>::value)
        std::cout << "POD value: " << target << std::endl; // for "plain old data"
    else
        std::cout << "Non POD value: " << target << std::endl;
    // ...
}

int main() {
    Vector<int> v;
    v.print(10);
    uint i = 5;

    StringMap<int> m; // m is a Map<std::string, int>

    std::cout << vis2 << std::endl;
    std::cout << vis3 << std::endl;
    std::cout << "testing:" << testing<std::string> << std::endl;

    update(i);
    update(vis2);
    
    return 0;
}
