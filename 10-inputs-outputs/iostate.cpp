#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;

vector<int> read_ints(std::istream & is)
{
    vector<int> res;

    for (int i; is >> i; )
        res.push_back(i);
    
    return res;
}

vector<int> read_ints(std::istream & is, const string& terminator)
{
    vector<int> res;

    for (int i; is >> i; )
        res.push_back(i);

    if (is.eof()) // fine: end of file
        return res;

    if (is.fail()) { // we failed to read an int; was it the terminator?
        is.clear(); // reset the state to good()
        is.unget(); // put the non-digit back into the stream
        string s;
        if (cin>>s && s == terminator)
            return res;
        cin.setstate(std::ios_base::failbit); // add fail() to cin's state
    }
    
    return res;
}

struct Entry {
    string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\", " << e.number << "}";
}


std::istream& operator>>(std::istream& is, Entry& e)
// read { "name" , number } pair. Note: for matted with { " " , and }
{
    char c, c2;
    
    if (is >> c && c == '{' && is >> c2 && c2 == '"') { // star t with a { "
        string name; // the default value of a string is the empty string: ""
        while (is.get(c) && c != '"') // anything before a " is part of the name
            name+=c;

        if (is >> c && c == ',') {
            int number = 0;
            if (is >> number >> c && c == '}') { // read the number and a }
                e = {name ,number}; // assign to the entry
                return is;
            }
        }
    }

    is.setstate(std::ios_base::failbit); // register the failure in the stream
    
    return is;
}


int main()
{
    // read_ints(std::cin);
    auto v = read_ints(cin,"stop");

    for (Entry ee; cin >> ee; ) // read from cin into ee
        cout << ee << '\n'; // wr ite ee to cout

    return 0;
}
