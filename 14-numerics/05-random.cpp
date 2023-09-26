#include <iostream>
#include <random>

using namespace std;

class Rand_int {
public:
    Rand_int(int low, int high) :dist{low, high} { }
    int operator()() { return dist(re); } // draw an int
    void seed(int s) { re.seed(s); } // choose new random engine seed
private:
    default_random_engine re;
    uniform_int_distribution<> dist;
};

int main()
{
    constexpr int max = 9;
    Rand_int rnd {0, max}; // make a uniform random number gen
    
    vector<int> histogram(max + 1); // make a vector of appropriate size
    for (int i = 0; i != 200; ++i)
        ++histogram[rnd()]; // fill histogram with the frequencies of numbers [0:max]
    
    for (int i = 0; i != histogram.size(); ++i) { // write out a bar graph
        cout << i << '\t' << histogram[i] << '\t';
        for (int j = 0; j != histogram[i]; ++j) cout <<'*' ;
            cout << '\n' ;
    }
}