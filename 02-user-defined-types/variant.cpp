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
        std::cout << "holds int: " << std::get<int>(pe->v) << std::endl;

    if (holds_alternative<Node *>(pe->v))
    {
        std::cout << "holds Node *: " << std::get<Node *>(pe->v) << std::endl;
        if (nullptr != std::get<Node *>(pe->v))
        {
            std::cout << "gets Node : " << (std::get<Node *>(pe->v))->f << std::endl;
        }
    }
}

int main()
{
    Node n {1.0};
    Entry pe1 {"abc", &n};
    Entry pe2 {"abc", 10};
    Entry pe3 {"abc"};
    Entry pe4;
     
    f(&pe1);
    f(&pe2);
    f(&pe3);
    f(&pe4);
    
    return 0;
}
