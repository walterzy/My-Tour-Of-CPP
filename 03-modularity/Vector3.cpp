#include <iostream>
#include <numeric>

class Vector {
public:
    Vector(int s);
    double & operator[](int i);
    int size();
private:
    double * elem;  // elem points to an array of sz doubles
    int sz;
};

Vector::Vector(int s)
{
    if (s < 0)
        throw std::length_error{"Vector constructor: negative size"};
    elem = new double(s);
    sz = s;
}

double & Vector::operator[](int i) 
{
    if (i < 0 || size() <= i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size() {return sz;}

/*
int size(const Vector & v) {return v.size();}

bool operator==(const Vector& v1, const Vector& v2)
{
    if (v1.size() != v2.size())
        return false;
        
    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;

    return true;
}
*/

void user(int sz) noexcept
{
    Vector v(sz);
    std::iota(&v[0], &v[sz], 1); // file v with 1,2,3,4,...
}

void test(int n)
{
    try {
        Vector v(n);
    }
    catch (std::length_error& err) {
        std::cerr << "test failed:length error\n";
        throw; // rethrow
    }
    catch (std::bad_alloc& err) {
        std::cerr << "calling std::terminate()\n";
        std::terminate();   // terminate the program
    }
}

int main()
{
    test(-27);
    test(1'000'000'000);

    return 0;
}
