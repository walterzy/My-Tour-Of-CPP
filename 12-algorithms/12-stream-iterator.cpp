#include <string>
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <set>
#include <algorithm>
#include <fstream>      // ifstream

using namespace std;

int main()
{
    string from, to;
    cin >> from >> to; // get source and target file names

    ifstream is {from}; // input stream for file "from"
    ofstream os {to}; // output stream for file "to"

    set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}}; // collect strings from input
    ranges::copy(b, ostream_iterator<string>{os, "\n"}); // copy buffer to output

    return ! is.eof() || ! os; // return error state (§1.2.1, §11.4)
}

