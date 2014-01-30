/*
 * =====================================================================================
 *
 *       Filename:  explicit_keyword.cpp
 *
 *    Description:  Constructor, operator and function syntax for new.
 *
 *        Version:  1.0
 *        Created:  01/29/2014 12:08:47
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

class Foo{

    int var;

    public:
    Foo(void){
        var = 99;
    }

    Foo(int len){
        var = len;
    }

    /* Let's write conversion from Foo* to Foo. Else the compilation fails for Foo first = new Foo();
     * Note that the after writing this method Foo first = new Foo() compiles since we have a conversion from Foo* to Foo.
     * Note that this is in constructor format. So we don't mention return type. 
    */
    Foo(Foo *foo){
        var = foo->var;
    }

    int getVar(){
        return var;
    }
};


int main(void){
    /*
     *  fails to compile. new in operator syntax calls malloc which allocates and then it calls default constructor to initialize.
     *  Note that malloc returns (Foo*). and we don't have any method yet to convert Foo* to Foo 
     */
    //Foo first = new Foo(); --^


   /* this compiles since malloc returns Foo* */
    Foo *first = new Foo();
    std::cout << first->getVar() << std::endl;
    //#output: 99


    /* Note that we can simply call new by function syntax. It will just allocate and won't call constructor. */
    Foo *just_allocation = (Foo *)::operator new (sizeof(Foo)); //this simply calls malloc which returns (void *) -> generic type in c++
    std::cout << just_allocation->getVar() << std::endl; //default value of 0. constructor is not called.
    //#output: 0
    //Question: Are there any other consequences of not calling the default construcor other than the initialization bit in the constructor itself?
    //Ans. I think no.


    /* let's call the constructor on just_allocation manually */
    new (just_allocation) Foo {}; //yes, this is the syntax.
    std::cout << just_allocation->getVar() << std::endl;
    //#output: 99


    /* this code compilers after defining the Foo(Foo *foo) constructor. */
    /* This calls the default constructor */
    Foo second = new Foo();
    std::cout << second.getVar() << std::endl;
    //#output: 99


    return 0;
}


