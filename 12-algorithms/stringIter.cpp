// string::begin/end
#include <iostream>
#include <string>
#include <typeinfo>

int main ()
{
    char c = 'a';
    std::string str ("Mary had a little lamb");
    for ( std::string::iterator it = str.begin(); it != str.end(); ++it)
        std::cout << *it << ", type = " << typeid(*it).name() << std::endl;
    std::cout << '\n';

    std::cout << "c's type = " << typeid(c).name() << std::endl;
    for (auto p = str.begin(); p != str.end(); ++p)
        if (*p == c)
            std::cout << "found " << c << std::endl;

  return 0;
}
