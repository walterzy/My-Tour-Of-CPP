#include <chrono>
#include <iostream>
#include <stop_token>
#include <thread>
#include <vector>

using namespace std;

atomic<int> result = -1; // put a resulting index here

template<class T> struct Range { T* first; T* last; }; // a way of passing a range

void myFind(stop_token tok, const string* base, const Range<string> r, const string & target)
{
    for (string * p = r.first; p != r.last && ! tok.stop_requested(); ++p)
        if (*p == target)
        { 
            // match() applies some matching criteria to the two strings
            result = p - base; // the index of the found element
            return;
        }        
}

void find_all(vector<string>& vs, const string & key)
{
    int mid = vs.size()/2;
    string * pvs = & vs[0];

    stop_source ss1{};
    jthread t1(myFind, ss1.get_token(), pvs, Range{pvs, pvs + mid}, key); 

    stop_source ss2{};
    jthread t2(myFind, ss2.get_token(), pvs, Range{pvs + mid, pvs + vs.size()} , key);

    while (result == -1)
        this_thread::sleep_for(10ms);
    
    ss1.request_stop(); // we have a result: stop all threads
    ss2.request_stop();
    // ... use result ...
}

int main()
{
    return 0;
}