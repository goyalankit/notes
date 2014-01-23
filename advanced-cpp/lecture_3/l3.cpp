#include<iostream>
#include<cstdint>

class Foo{
    public:
        Foo(void) { std::cout << "default constructor\n"; }
        ~Foo(void) { std::cout << "destrcutor\n"; }
};

int main(void){
    Foo * p = new Foo[100]; //new is different from malloc. you allocate and intiailize memory. // new just allocation no initialization.
    //with new square brackets syntax. compiler is permitted to allocate space more than 10. Add more space to array to write the size.
    //delete p; //program crashes because of delete semantics
//    (p+9) -> ~Foo(); explicitly call the destructor

    for (uint32_t i = 0; i < 10; i++) {
        p[i].~Foo();
    }
//    delete[] p; this works
    operator delete(p); //this calls free. Needs to have pointer to the beginning and p crashes.
    //operator syntax destroy the object and deallocate. function call syntax just deallocate
}
