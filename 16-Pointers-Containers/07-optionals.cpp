#include <iostream>
#include <optional>

using namespace std;

optional<string> compose_message(istream & s)
{
    string mess;

    s >> mess;

    // ... read from s and compose message ...
    if (mess == string("test"))
        return mess;
    
    return {}; // the empty optional
}

int sum(optional<int> a, optional<int> b)
{
    int res = 0;

    if (a) res += *a;
    if (b) res += *b;

    return res;
}

int main()
{
    if (auto m = compose_message(cin))
        cout << *m; // note the dereference (*)
    else {
        // ... handle error ...
        cout << "empty result" << endl;
    }

    cout << compose_message(cin).value_or("empty") << endl;

    int x = sum(17, 19); // 36
    int y = sum(17, {}); // 17
    int z = sum({}, {}); // 0
}
