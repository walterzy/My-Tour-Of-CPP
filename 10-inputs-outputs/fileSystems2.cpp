#include <iostream>
#include <filesystem>
#include <cassert>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using namespace std::filesystem;
using std::string;


void test(path p)
{
    if (is_directory(p)) {
        cout << p << ":\n";
        for (const directory_entry & x : directory_iterator(p)) {
            const path & f = x; // refer to the path part of a directory entry
            if (f.extension() == ".exe")
                cout << f.stem() << " is a Windows executable\n";
            else {
                string n = f.extension().string();
                if (n == ".cpp" || n == ".C" || n == ".cxx")
                    cout << f.stem() << " is a C++ source file\n";
                else
                    cout << f.filename() << " is a unknow type file\n";
            }
        }
    }
}

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        cerr << "arguments expected\n";
        return 1;
    }

    test(argv[1]);

    return 0;
}
