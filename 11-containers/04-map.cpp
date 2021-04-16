#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

class NamePhone {
private:
    string name_;
    int phone_;

public:
    NamePhone(string name_in, int phone_in) : name_{name_in}, phone_{phone_in} {};
    string name() const { return name_; }
    int phone() const { return phone_; }
};

map<string,int> phone_book {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Bertrand Arthur William Russell",345678}
};


int get_number(const string& s) {
    return phone_book[s]; // access the value based on the key s
}


int main() {
    cout << get_number("David Hume") << endl;

    return 0;
}




