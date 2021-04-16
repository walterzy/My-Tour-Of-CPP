#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;

class NamePhone {
private:
    string name_;
    int phone_;

public:
    NamePhone(string name_in, int phone_in) : name_{name_in}, phone_{phone_in} {};
    string name() const { return name_; }
    int phone() const { return phone_; }
};


unordered_map<string,int> phone_book {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Ber trand Ar thur William Russell",345678}
};


int get_number(const string& s) {
    return phone_book[s]; // access the value based on the key s
}


struct Record {
    string name;
    int product_code;
    // ...
};

struct Rhash { // a hash function for Record
    size_t operator()(const Record& r) const
    {
        return std::hash<string>()(r.name) ^ std::hash<int>()(r.product_code);
    }
};

unordered_set<Record,Rhash> my_set; // set of Records using Rhash for lookup

int main() {
    cout << get_number("David Hume") << endl;

    return 0;
}




