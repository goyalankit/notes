/*
 * =====================================================================================
 *
 *       Filename:  virtual_methods.cpp
 *
 *    Description:  pure virtual, virtual methods
 *
 *        Version:  1.0
 *        Created:  02/03/2014 15:52:08
 *       Revision:  none
 *       Compiler:  g++ -std=c++11
 *
 *         Author:  Ankit Goyal
 *   Organization:  University of Texas at Austin
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdint>

/* abstract class */
class Foo{

    int a;
    public:
    Foo(void) = default;

    /* Pure virtual method. MUST be defined by a base class. This class cannot be instantiated now. It's an abstract class now.*/
    virtual void method1() = 0 ;

    /* Virtual method. Which method to call is decided at run time. fetch-fetch-call : vptr -> method -> call */
    virtual void method2() { std::cout << "method2: Hello from Foo" << std::endl; }

    /* Normal method. Method to be called is decided at compile time. fetch-call : method -> call */
    void method3() { std::cout << "method3: Hello from Foo" << std::endl; }
};

class Bar : public Foo{

    public:

        virtual void method1(){
            std::cout << "Method4: Hello from bar" << std::endl;
        }

        virtual void method2(){
            std::cout << "method2: Hello from bar" << std::endl;
        }

        void method3(){
            std::cout << "method3: Hello from bar" << std::endl;
        }

};

/* Not an abstract class */
class Foo1{
    public:
        virtual void method1(){ std::cout << "method1: Hello from Foo1" << std::endl; }
        void method2(){ std::cout << "method2: Hello from Foo1" << std::endl; }
};

class Bar1 : public Foo1{
    public:
        virtual void method1(){ std::cout << "method1: Hello from Bar1" << std::endl; }
        void method2(){ std::cout << "method2: Hello from Bar1" << std::endl; }
};

int main(void){
    /* Foo cannot be instantiated. Since it's an abstract class */
    //Foo f;
    /* FOO-BAR START */
    Bar b;
    b.method3(); //derived method is called.
    b.method2(); //derived method is called
    /* FOO-BAR END */

    Foo1 foo1;
    Bar1 bar1;

    foo1.method1(); //parent method is called.
    bar1.method1(); //derived method is called.

    foo1.method2(); //parent method is called.
    bar1.method2(); //derived method is called.
/*
     Bar1 * bar2;
      Foo1 *foo2 = dynamic_cast<Foo1*>(bar2);
       foo2->method2(); parent method is called
    foo2->method1(); Segmentation fault

        Foo1 * tfoo;
    Bar1 * tbar;
    if((tbar = dynamic_cast<Bar1*>(tfoo)))
        std::cout << "tbar is not null" << std::endl;
    tbar->method1();
    tbar->method2();
*/
    return 0;
}
