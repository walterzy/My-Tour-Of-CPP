#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void f()
{
    int i;
    std::cin >> i; // read an integer into i
    double d;
    std::cin >> d; // read a double-precision floating-point number into d

    std::cout << "i = " << i << " d = " << d << std::endl;
}

void hello_line()
{
    cout << "Please enter your name\n";
    string str;
    getline(cin,str);
    cout << "Hello, " << str << "!\n";
}

int main()
{
    // f();
    hello_line();

    return 0;
}