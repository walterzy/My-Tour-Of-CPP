#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& v)
{
    int s = 0;
    for (const int i : v)
        s += i;
    return s;
}

void test(vector<int> v, vector<int>& rv)
{
    v[1] = 99;
    rv[2] = 66;
}

int main()
{
    vector<int> fib = {1,2,3,5,8,13,21};
    cout << "sum of fib = " << sum(fib) << endl;
    test(fib,fib);
    cout << fib[1] << " " << fib[2] << endl;
}
