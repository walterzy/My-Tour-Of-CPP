#include <vector>
#include <thread>
#include <iostream>

using namespace std;

void f(const vector<double> & v, double * res) {}; // take input from v; place result in * res

class F {
public:
    F(const vector<double> & vv, double * p) :v{vv}, res{p} { }
    void operator()() {}; // place result in *res
private:
    const vector<double> & v; // source of input
    double * res;       // target for output
};

double g(const vector<double> &) {return 0;};   // use return value

void user(vector<double> & vec1, vector<double> vec2, vector<double> vec3)
{
    double res1;
    double res2;
    double res3;

    thread t1 {f, cref(vec1), & res1};   // f(vec1,&res1) executes in a separate
    thread t2 {F{vec2, & res2}};        // F{vec2,&res2}() executes in a separa
    thread t3 { [&](){ res3 = g(vec3); } }; // capture local variables by reference

    t1.join();  // join before using results
    t2.join();
    t3.join();

    std::cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
}

int main()
{
    vector<double> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2 {10, 11, 12, 13, 14};
    vector<double> vec3 {10, 11, 12, 13, 14};
    
    user(vec1, vec2, vec3);
}
