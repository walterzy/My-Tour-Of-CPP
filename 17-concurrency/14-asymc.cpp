#include <iostream>
#include <vector>
#include <numeric>
#include <future>

using namespace std;

double accum(vector<double>::iterator beg, vector<double>::iterator end, double init)
// compute the sum of [beg:end) starting with the initial value init
{
    return accumulate(&*beg, &*end, init);
}

double comp2(vector<double>& v)
{
    packaged_task pt0 {accum}; // package the task
    packaged_task pt1 {accum};

    future<double> f0 {pt0.get_future()}; // get hold of pt0's future
    future<double> f1 {pt1.get_future()}; // get hold of pt1's future

    auto first = v.begin();
    thread t1 {move(pt0), first, first + v.size() / 2, 0}; // start a thread for pt0
    thread t2 {move(pt1), first + v.size() / 2, first + v.size(), 0}; // start a thread for pt1
    // ...

    t1.join();
    t2.join();
    
    return f0.get() + f1.get(); // get the results
}


double comp4(vector<double>& v)
// spawn many tasks if v is large enough
{
    if (v.size() < 10'000) // is it worth using concurrency?
        return accum(v.begin(), v.end(), 0.0);
    
    auto v0 = v.begin();
    auto sz = v.size();
    auto f0 = async(accum, v0, v0 + sz / 4, 0.0); // first quarter
    auto f1 = async(accum, v0 + sz / 4, v0 + sz / 2, 0.0); // second quarter
    auto f2 = async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0); // third quarter
    auto f3 = async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0); // fourth quarter
    
    return f0.get() + f1.get() + f2.get() + f3.get(); // collect and combine the results
}

int main() {
    // Create a vector of doubles
    std::vector<double> numbers{1, 100'000'000};

    // Print the final sum
    std::cout << "comp4 Sum: " << comp4(numbers) << std::endl;

    // Print the final sum
    std::cout << "comp2 Sum: " << comp2(numbers) << std::endl;

    return 0;
}
