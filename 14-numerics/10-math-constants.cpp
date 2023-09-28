#include <numbers>
#include <iostream>

template<typename T>
constexpr T tau_v = 2 * std::numbers::pi_v<T>;

void area(float r)
{
    using namespace std::numbers; // this is where the mathematical constants a
    double d = pi * r * r;
    float f = pi_v<float> * r * r;
    
    std::cout << "d = " << d << "; f = " << f << std::endl;
    std::cout << "egamma = " << egamma << std::endl;
    std::cout << "phi = " << phi << std::endl;

    constexpr double tau = tau_v<double>;
    std::cout << "tau = " << tau << std::endl;
}


int main()
{
    area(2);
}