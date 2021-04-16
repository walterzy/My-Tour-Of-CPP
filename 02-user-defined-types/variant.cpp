#include <iostream>

struct Entry{
    string name;
    variant<Node *, int> v;
}

void f(Entry * pe)
{
    if (holds_alternative<int>(pe->v))
        std::cout << std::get<int>(pe->v);
}

int main()
{
    return 0;
}