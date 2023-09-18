#include <span>

using namespace std;

void fs(span<int> p)
{
    for (int& x : p)
        x = 0;
}

void use(int x)
{
    int a[100];
    
    fs(a); // implicitly creates a span<int>{a,100}
    //fs(a, 1000); // error: span expected
    fs({a + 10, 100}); // a range error in fs
    fs({a, x}); // obviously suspect
}

int main()
{

}
