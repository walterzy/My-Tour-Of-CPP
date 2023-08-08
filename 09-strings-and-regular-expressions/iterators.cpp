#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using namespace std::literals::string_literals;

void test()
{
    string input = "aa as; asd ++e^asdf asdfg";
    regex pat {R"(\s+(\w+))"};
    for (std::sregex_iterator p(input.begin(), input.end(), pat); p != std::sregex_iterator{}; ++p)
            cout << (*p)[1] << '\n';
}

int main()
{
    test();

    return 0;
}
