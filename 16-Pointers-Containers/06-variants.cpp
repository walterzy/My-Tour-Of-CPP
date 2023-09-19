#include <iostream>
#include <variant>
#include <cassert>

using namespace std;

enum class Error_code { range_error, length_error, not_found };

variant<string, Error_code> compose_message(istream& s)
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
    if (holds_alternative<string>(m)) {
        cout << get<string>(m);
    }
    else {
        auto err = get<Error_code>(m);
        // ... handle error ...
        if (err == Error_code::not_found)
            cout << "error cod is: not_found" << endl;
    }

    using namespace std::literals;
 
    std::variant<std::string> x("abc");
    // converting constructors work when unambiguous
    x = "def"; // converting assignment also works when unambiguous
 
    std::variant<std::string, void const *> y("abc");
    // casts to void const * when passed a char const *
    assert(std::holds_alternative<void const *>(y)); // succeeds
    y = "xyz"s;
    assert(std::holds_alternative<std::string>(y)); // succeeds
}
