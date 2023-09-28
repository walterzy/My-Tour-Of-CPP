#include <thread>
#include <iostream>

using namespace std;

void f() { cout << endl << "f() ..." << endl; } // function

struct F { // function object
    void operator()() { cout << endl << "F's call () ..." << endl;}; // F's call operator (¡ì7.3.2)
};

void user()
{
    thread t1 {f};  // f() executes in separate thread
    thread t2 {F{}};    // F{}() executes in separate thread
    t1.join();  // wait for t1
    t2.join();  // wait for t2
}

void user2()
{
    jthread t1 {f}; // f() executes in separate thread
    jthread t2 {F{}}; // F{}() executes in separate thread
}

int main()
{
    //user();
    user2();
}