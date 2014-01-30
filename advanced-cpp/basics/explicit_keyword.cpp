/*
 * =====================================================================================
 *
 *       Filename:  explicit_keyword.cpp
 *
 *    Description:  explicit keyword
 *
 *        Version:  1.0
 *        Created:  01/29/2014 12:37:14
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
    private:
        int var;
        char var2;
    public:
        Foo(void) {}

        Foo(int i) {var = i;}
        explicit Foo(char a) {var2 = a;}

        int getVar(){ return var; }
        char getVar2(){ return var2; }
};

class Bar{

    private:
        int var;

    public:
        Bar(void) {}
        explicit Bar(int i) {var = i;}

        int getVar() {return var;}
};


void barme1(Bar b){
    std::cout << b.getVar() << std::endl;
}

void foome1(Foo f){
    std::cout << f.getVar() << std::endl;
}

void foome2(Foo f){
    std::cout << f.getVar2() << std::endl;
    std::cout << f.getVar() << std::endl;
}

int main(void){
    Foo *f = new Foo();

    /*
     * note that parameter to bar expects Foo object, however this passes due to implicit conversion in c++.
     *
     */
    foome1(23);

    /* Technically this should fail. However it used the Foo(int) construcor and passed the ASCII value of 'a'. Interesting! */
    /* Note that var2 is not initialized when called using foome2('a'); instead var1 was initialized using constructor for int*/
    foome2('a');

    /*  This fails to compile, since the conversion needs to be explicit */
   // barme1(23);

   /* let's make the conversion explicit */
    barme1(Bar(23));
    return 0;
}
