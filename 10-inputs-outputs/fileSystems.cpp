#include <iostream>
#include <filesystem>
#include <cassert>

using std::cout;
using std::endl;
using std::cerr;
using namespace std::filesystem;
using std::cin;

void print_directory(path p)
try
{
    if (is_directory(p)) {
        cout << p << ":\n";
        for (const directory_entry & x : directory_iterator{p})
            cout << " " << x.path() << '\n';
    }
}
catch (const filesystem_error & ex) {
    cerr << ex.what() << '\n';
}

void test(path p)
{
    if (is_directory(p)) {
        cout << p << ":\n";
        for (const directory_entry& x : directory_iterator(p)) {
            const path& f = x; // refer to the path part of a directory entry
            if (f.extension() == ".exe")
                cout << f.filename() << " is a Windows executable\n";
            else {
                std::string n = f.extension().string();
                if (n == ".cpp" || n == ".C" || n == ".cxx")
                    cout << f.filename() << " is a C++ source file\n";
            }
        }
    }
}


int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        cerr << "arguments expected\n";
        cerr << "usage: file dir\n";
        return 1;
    }

    path f {argv[1]}; // naming a file
    assert(exists(f)); // f must exist
    if (is_regular_file(f)) // is f an ordinary file?
        cout << f << " is a file; its size is " << file_size(f) << '\n';

    print_directory(argv[2]);
    test(argv[2]);

    return 0;
}
