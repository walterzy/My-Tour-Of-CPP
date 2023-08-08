#include <iostream>
#include <cstdio>
#include <string>
#include <string_view>

using std::cout;
using std::endl;
using std::string;
using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

// string_view: {begin(), size()}

string cat(std::string_view sv1, std::string_view sv2)
{
    string res(sv1.length() + sv2.length(), ' ');
    char * p = &res[0];
    
    for (char c : sv1) // one way to copy
        *p++ = c;
    
    std::copy(sv2.begin(), sv2.end(), p); // another way
    
    return res;
}


std::string_view bad()
{
    string s = "Once upon a time";
    return {&s[5],4}; // bad: returning a pointer to a local
}


void print_lower(std::string_view sv1)
{
    // Like all other functions from <cctype>, the behavior of std::tolower is undefined
    // if the argument's value is neither representable as unsigned char nor equal to EOF.
    // To use these functions safely with plain chars (or signed chars), the argument 
    // should first be converted to unsigned char: 
    for (char ch : sv1)
        cout << static_cast<char>(tolower(static_cast<unsigned char>(ch)));
}


int main() {
    string king = "Harold";
    auto s1 = cat(king, "William"); // string and const char*
    auto s2 = cat(king, king); // string and string
    auto s3 = cat("Edward", "Stephen"sv); // const char * and string_view
    auto s4 = cat("Canute"sv, king);
    auto s5 = cat({&king[0],2}, "Henry"sv); // HaHenry
    auto s6 = cat({&king[0],2}, {&king[2],4}); // Harold

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s5 << endl;
    cout << "s6 = " << s6 << endl;

    cout << bad() << endl;
    
    print_lower({&king[0], king.size()});

    return 0;
}
