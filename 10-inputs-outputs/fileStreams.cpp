#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
    std::ofstream ofs {"target"}; // ‘‘o’’ for ‘‘output’’
    if (!ofs)
        cout << "couldn't open 'target' for writing" << endl;
    else
        ofs << "test\n";

    std::ifstream ifs {"source"}; // ‘‘i’’ for ‘‘input’’
    if (!ifs)
        cout << "couldn't open 'source' for reading" << endl;;

    return 0;
}
