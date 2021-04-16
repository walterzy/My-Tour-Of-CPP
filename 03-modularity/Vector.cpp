// file Vector.app

module; // this compilation will define a module

export module Vector;   // defining the module called "Vector"

export class Vector {
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
        throw length_error{"Vector constructor: negative size"};
    elem = new double(s);
    sz = s;
}

double & Vector::operator[](int i) 
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size() {return sz;}

export int size(const Vector & v) {return v.size();}

void user(int sz) noexcept
{
    Vector v(sz);
    iota(&v[0], &v[sz], 1); // file v with 1,2,3,4,...
}

void test()
{
    try {
        Vector v(-27);
    }
    catch (std::length_error& err) {
        cerr << "test failed:length error\n";
        throw; // rethrow
    }
    catch (std::bad_alloc& err) {
        std::terminate();   // terminate the program
    }
}

