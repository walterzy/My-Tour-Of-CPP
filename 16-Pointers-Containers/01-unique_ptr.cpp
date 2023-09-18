#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using namespace std;


class X {};
class Z {};

void f(int i, int j) // X* vs. unique_ptr<X>
{
    X* p = new X; // allocate a new X
    std::unique_ptr<X> sp {new X}; // allocate a new X and give its pointer to unique_ptr
    // ...
    if (i < 99) throw Z{}; // may throw an exception
    if (j < 77) return; // may return "early"
    // ... use p and sp ..
    delete p; // destroy *p
}


std::unique_ptr<X> make_X()
// make an X and immediately give it to a unique_ptr
{
    //... check i, etc. ...
    return std::unique_ptr<X>{new X};
}

void f(shared_ptr<std::fstream>) {};
void g(shared_ptr<std::fstream>) {};

void user(const string& name, ios_base::openmode mode)
{
    std::shared_ptr<fstream> fp {new fstream(name, mode)};
    if (! *fp) // make sure the file was properly opened
        return;
    
    f(fp);
    g(fp);
    // ...
}

struct S {
    int i;
    string s;
    double d;
    // ...
};

int main()
{
    auto p1 = make_shared<S>(1, "Ankh Morpork", 4.65); // p1 is a shared_ptr<S>
    auto p2 = make_unique<S>(2, "Oz", 7.62); // p2 is a unique_ptr<S>
}


