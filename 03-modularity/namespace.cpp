#include <iostream>
#include <cmath>

namespace My_code {
    class complex {
        public:
            complex(double x, double y) : x{x},y{y} {}
            double real() {return x;}
            double imag() {return y;}
        private:
            double x;
            double y;
    // ...
    };

    complex sqrt(complex c) { 
        complex t(std::sqrt(c.real()), std::sqrt(c.imag()));
        return t;
    };
    // ...
    int main();
}

int My_code::main()
{
    complex z {1,2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    // ...
    return 0;
}

constexpr double C = 299792.458; // km/s
void f(double speed)
{
    constexpr double local_max = 160.0 / (60 * 60); // 160 km/h == 160.0/(60*60) km/s
    static_assert(speed < C,"can't go that fast"); // error : speed must be a constant
    static_assert(local_max < C,"can't go that fast"); // OK
    // ...
}

int main()
{
    return My_code::main();
}
