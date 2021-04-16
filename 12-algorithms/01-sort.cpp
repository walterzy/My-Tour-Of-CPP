#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::vector;
using std::string;

void printIntVector(const vector<int>& v) {
    for (auto x : v)
        cout << " " << x;
    cout << "\n";
}

vector<string::iterator> find_all(string & s, char c) // find all occurrences of c in s
{
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); ++p)
        if (*p == c)
            res.push_back(p);

    return res;
}

void test()
{
    string m {"Mary had a little lamb"};
    for (auto p : find_all(m,'a'))
        if (*p != 'a')
            cerr << "a bug!\n";
}

int main() {
    vector<int> vi = {3, 5, 1, 4, 2};
    cout << "int vector       = ";
    printIntVector(vi);
    
    cout << "ascending order  = ";
    sort(vi.begin(), vi.end()); // in-place sorting
    printIntVector(vi);
    
    cout << "descending order = ";
    sort(vi.begin(), vi.end(), std::greater<>()); // in-place sorting
    printIntVector(vi);
    
    
    return 0;
}