#include <iostream>
#include <chrono>
#include <string_view>

int main()
{
    using namespace std::chrono; // in sub-namespace std::chrono; see ¡ì3.3

    auto tp = system_clock::now(); // tp is a time_point
    std::cout << tp << '\n'; 
    zoned_time ztp { current_zone(), tp }; 
    std::cout << ztp << '\n';
//    const time_zone est {"Europe/Copenhagen"};
    constexpr std::string_view est {"Asia/Shanghai"};
    std::cout << zoned_time{ est, tp } << '\n';
}
