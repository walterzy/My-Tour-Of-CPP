#include <iostream>
#include <vector>
#include <string>

using std::cout;

template<typename ... T>
int sum(T... v)
{
    // right fold
    return (v + ... + 0); // add all elements of v starting with 0
}

template<typename ... T>
int sum2(T... v)
{
    // left fold
    return (0 + ... + v); // add all elements of v to 0
}

template<typename ...T>
void print(T&& ... args)
{
    (std::cout << ... << args) << '\n'; // print all arguments
}


// template<typename Res, typename ... Ts>
// std::vector<Res> to_vector(Ts && ... ts)
// {
//     std::vector<Res> res;
//     (res.push_back(ts) ...); // no initial value needed
//     return res;
// }

// template<typename ... Ts>
// int fct(Ts&& ... ts)
// {
//     auto args = to_vector<string>(ts...); // args[i] is the ith argument
//     // ... use args here ...

//     return sum(args);
// }


int main()
{
    std::cout << sum(1,3,5) << std::endl;
    std::cout << sum2(1,3,5) << std::endl;

    print("Hello!", ' ', "World ", 2021);
    // (((((std::cout << "Hello!") << ’ ’) << "World ") << 2021) << ’\n’);

    // auto x = to_vector<double>(1,2,4.5,'a');
}