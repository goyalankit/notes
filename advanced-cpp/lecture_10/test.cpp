/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  Ankit Goyal
 *
 *        Version:  1.0
 *        Created:  04/01/2014 16:02:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankit Goyal
 *   Organization:  University of Texas at Austin
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdint>

class A{
    public:
        void doIt(void){ std::cout << "A's doit" << std::endl; }
};

class B : public A{
    public:
        void doIt(int) { std::cout << "B's doit" << std::endl; }
};

int main(void){
    B a;
    a.doIt(12);
    return 0;
}
