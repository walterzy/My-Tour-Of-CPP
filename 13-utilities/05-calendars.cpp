#include <iostream>
#include <chrono>
#include <format>

int main()
{
    using namespace std::chrono; // in sub-namespace std::chrono; see ¡ì3.3

    auto spring_day = April/7/2018;
    std::cout << weekday(spring_day) << '\n'; // Sat
    std::cout << std::format("{:%A}\n", weekday(spring_day)); // Saturday

    auto spring_day2 = 2018y/April/7;
    auto bad_day = January/0/2024;
    if (! bad_day.ok())
        std::cout << bad_day << "\n";

    sys_days t = sys_days{February/25/2022}; // get a time point with the precision of days
    t += days{7}; // one week after February 25, 2022
    auto d = year_month_day(t); // convert the time point back to the calendar
    std::cout << d << '\n'; // 2022-03-04
    std::cout << std::format("{:%B}/{}/{}\n", d.month(), d.day(), d.year()); // March/04/2022

    static_assert(weekday(April/7/2018) == Saturday); // true
}
