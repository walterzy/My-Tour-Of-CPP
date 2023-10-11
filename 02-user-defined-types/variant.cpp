#include <iostream>
#include <variant>

struct Node{
    float f;
};

struct Entry{
    std::string name;
    std::variant<Node *, int> v;
};

void f(Entry * pe)
{
    if (holds_alternative<int>(pe->v))
        std::cout << pe->name << " holds int: " << std::get<int>(pe->v) << std::endl;

    if (holds_alternative<Node *>(pe->v))
    {
        std::cout << pe->name << " holds Node *: " << std::get<Node *>(pe->v) << std::endl;
        if (nullptr != std::get<Node *>(pe->v))
        {
            std::cout << pe->name << " gets Node : " << (std::get<Node *>(pe->v))->f << std::endl;
        }
    }
}

int main()
{
    Node n {1.0};
    Entry pe1 {"a", &n};
    Entry pe2 {"b", 10};
    Entry pe3 {"c"};
    Entry pe4;
     
    f(&pe1);
    f(&pe2);
    f(&pe3);
    f(&pe4);
    
    return 0;
}
