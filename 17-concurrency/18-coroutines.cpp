#include <coroutine>
#include <iostream>
#include <generator>

using namespace std;

std::generator<long long> fib() // generate Fibonacci numbers
{
    long long a = 0;
    long long b = 1;
    while (a < b) {
        auto next = a+b;
        co_yield next; // save state, return value, and wait
        a = b;
        b = next;
    }
    co_return 0; // a fib too far
}

void user(int max)
{
    for (int i=0; i++<max;)
        cout << fib() <<' ';
}

int main()
{

}
