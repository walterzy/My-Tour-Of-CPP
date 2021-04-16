#include <iostream>
#include <list>

using std::cout;
using std::string;
using std::list;

class NamePhone {
private:
    string name_;
    int phone_;

public:
    NamePhone(string name_in, int phone_in) : name_{name_in}, phone_{phone_in} {};
    string name() const { return name_; }
    int phone() const { return phone_; }
};


list<NamePhone> phone_book = {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Ber trand Ar thur William Russell",345678}
};

int get_number(const string& s)
{
    for (const auto & x : phone_book)
        if (x.name() == s)
            return x.phone();

    return 0; // use 0 to represent "number not found"
}


int get_number2(const string& s)
{
    for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
        if (p->name() == s)
            return p->phone();
            
    return 0; // use 0 to represent "number not found"
}

int main() {

    return 0;
}




