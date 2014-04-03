#include <iostream>
using namespace std;

#include "vector"


vector<int> myvector;


#define ADD_DEF(i) { myvector.push_back(i); }
//#define GET_DEF() { 21 + 12 }

#ifdef DB
    #define DEBUG(msg) { cerr << "DEBUG: " << msg << endl; }
#else
    #define DEBUG(msg) {}
#endif

int main ()
{

    ADD_DEF(1);
    std::cout << "Hello people" << std::endl;

    DEBUG("This is a debug message");
    
    DEBUG("coo");
    DEBUG("coo");
    return 0;
}

