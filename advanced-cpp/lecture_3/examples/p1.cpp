/*
 * =====================================================================================
 *
 *       Filename:  p1.cpp
 *
 *    Description:  Lecture 2. code snipped.
 *
 *        Version:  1.0
 *        Created:  01/23/2014 14:50:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ankit Goyal
 *   Organization:  UTCS
 *
 * =====================================================================================
 */

#include<iostream>
#include<cstdint>

class Foo{
    public:
        Foo(void) { std::cout << "default constructor\n"; }
        ~Foo(void) { std::cout << "destructor\n"; }
};

int main(void){
    Foo * p = new Foo[10]; 
    //delete p; gives you a compilation error
    delete[] p;
}
