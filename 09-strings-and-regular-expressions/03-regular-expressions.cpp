#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using namespace std::literals::string_literals;

void use()
{
    std::ifstream in("file.txt"); // input file
    if (!in) // check that the file was opened
        std::cerr << "no file\n";
    regex pat {R"(\w{2}\s∗\d{5}(−\d{4})?)"}; // U.S. postal code pattern
    int lineno = 0;
    for (string line; getline(in, line); ) {
        ++lineno;
        std::smatch matches; // matched strings go here
        if (regex_search(line, matches, pat)) {
            cout << lineno << ": " << matches[0] << '\n'; // the complete match
            if (1 < matches.size() && matches[1].matched) // if there is a sub-pattern
                // and if it is matched
                cout << "\t: " << matches[1] << '\n'; // submatch
        }
    }
}


bool is_identifier(const string& s)
{
    // regex pat {"[_[:alpha:]]\\w∗"}; // underscore or letter
    // followed by zero or more underscores, letters, or digits

    regex pat {R"([_[:alpha:]]\w∗)"};
    return regex_match(s,pat);
}

int main() {
    regex pat {R"(\w{2}\s*\d{5}(−\d{4})?)"}; 
    // U.S. postal code pattern: XXddddd-dddd and var iants

    // regex pat {R"(^A*B+C?$)"}; 

    int lineno = 0;
    for (string line; getline(std::cin, line); ) { // read into line buffer
        if (0 == line.length()) exit(0);        

        ++lineno;
        std::smatch matches; //matched strings go here

        if (regex_search(line, matches, pat)) // search for pat in line
            cout << lineno << ": " << matches[0] << '\n';
            cout << "matches size" << ": " << matches.size() << '\n'; // the complete match
            if (1 < matches.size() && matches[1].matched) // if there is a sub-pattern
                // and if it is matched
                cout << "\t: " << matches[1] << '\n'; // submatch
        
    }

    return 0;
}
