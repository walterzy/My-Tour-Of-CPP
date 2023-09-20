#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    using namespace std::chrono; // in sub-namespace std::chrono; see ¡ì3.3

    auto t0 = system_clock::now();
    std::this_thread::sleep_for(200ms);
    auto t1 = system_clock::now();

    std::cout << t1 - t0 << "\n"; // default unit: 
    std::cout << duration_cast<milliseconds>(t1 - t0).count() << "ms\n"; // specify unit:
    std::cout << duration_cast<nanoseconds>(t1 - t0).count() << "ns\n"; // specify unit:

}
