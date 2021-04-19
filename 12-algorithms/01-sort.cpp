#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::cerr;
using std::vector;
using std::string;
using std::list;

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

template<typename T>
using Iterator = typename T::iterator; // T’s iterator

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v) // find all occurrences of v in c
{
    vector<Iterator<C>> res;
    for (auto p = c.begin(); p != c.end(); ++p)
        if (*p == v)
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


void test2()
{
    string m {"Mary had a little lamb"};
    for (auto p : find_all(m,'a')) // p is a str ing::iterator
        if (*p != 'a')
            cerr << "string bug!\n";

    list<double> ld {1.1, 2.2, 3.3, 1.1};
    for (auto p : find_all(ld, 1.1)) // p is a list<double>::iterator
        if (*p != 1.1)
            cerr << "list bug!\n";

    vector<string> vs { "red", "blue", "green", "green", "orange", "green" };
    for (auto p : find_all(vs, "red")) // p is a vector<str ing>::iterator
        if (*p != "red")
            cerr << "vector bug!\n";

    for (auto p : find_all(vs, "green"))
        *p = "vert";
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
    
    test();
    test2();

    return 0;
}