#include <string>
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <vector>
#include <algorithm>
#include <fstream>      // ifstream

using namespace std;

int main()
{
    string from, to;
    cin >> from >> to; // get source and target file names

    ifstream is {from}; // input stream for file "from"
    istream_iterator<string> ii {is}; // input iterator for stream
    istream_iterator<string> eos {}; // input sentinel

    ofstream os {to}; // output stream for file "to"
    ostream_iterator<string> oo {os, "\n"}; // output iterator for stream plus a separator

    vector<string> b {ii, eos}; // b is a vector initialized from input
    sort(b.begin(), b.end()); // sort the buffer

    unique_copy(b.begin(), b.end(), oo); // copy the buffer to output, discard repllicated values

    return ! is.eof() || ! os; // return error state (§1.2.1, §11.4)
}

