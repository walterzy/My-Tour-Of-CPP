#include <iostream>
#include <cstdio>
#include <string>

using std::cout;
using std::endl;
using std::string;
using namespace std::literals::string_literals;

string compose(const string& name, const string& domain)
{
    return name + '@' + domain;
}


int main() {
    string first_name1 = "Joao";
    string last_name1 = "Martins";
    string name1 = first_name1 + " " + last_name1;
    
    cout << "Name1: " << name1 << "\n";
    printf("Name1 (C-style string): %s\n\n", name1.c_str());
    
    string first_name2 = "Maria";
    string last_name2 = "Souza";
    string name2 = first_name2 + " " + last_name2;
    
    cout << "Name2: " << name2 << "\n\n";
    
    if (first_name1 == first_name2)
        cout << "First Names are equal\n";
    else if (first_name1 == "Joao")
        cout << "First Name is Joao\n";
    
    string last_name1_again = name1.substr(5, 11);
    cout << "last_name1_again = " << last_name1_again << endl;
    
    // there are a lot of other useful functions for strings
    auto addr = compose("dmr","bell-labs.com");
    cout << addr << endl;

    string name = "Niels Stroustrup";
    string s = name.substr(6,10); // s = "Stroustrup"
    name.replace(0,5,"nicholas"); // name becomes "nicholas Stroustrup"
    name[0] = toupper(name[0]); // name becomes "Nicholas Stroustrup"

    cout << name << endl;

    auto s1 = "Cat"s;
    auto p1 = "Dong";

    cout << "s1 = " << s1 << endl;
    cout << "p1 = " << p1 << endl;

    s1.replace(0,2,"TMP");
    cout << "s1 = " << s1 << endl;

    s1 = p1;
    
    return 0;
}
