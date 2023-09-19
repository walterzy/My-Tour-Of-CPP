#include <iostream>
#include <any>
#include <cassert>

using namespace std;

enum class Error_code { range_error, length_error, not_found };

any compose_message(istream& s)
{
    string mess;

    s >> mess;

    // ... read from s and compose message ...
    if (mess == string("test"))
        return mess; // return a string
    else
        return Error_code::not_found; // return an Error_code
}

int main()
{
    auto m = compose_message(cin);
    string& s = any_cast<string &>(m);
    cout << s;
}
