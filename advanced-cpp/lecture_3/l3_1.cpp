#include<iostream>
#include<cstdint>

class Foo{
    public:
        Foo(void) { std::cout << "default constructor\n"; }
        ~Foo(void) { std::cout << "destrcutor\n"; }
};

int main(void){
    Foo* p = (Foo*) ::operator new(10*sizeof(Foo)); //malloc is called. just allocation no initialization.

//    p->Foo();  illegal. tries to allocate space and then call constructor.

    for (uint32_t k= 0; k < 10; k++) {
        new (p + k) Foo{}; //you have clready allocated the space. just need to call constructor.
    }

    for (uint32_t i = 0; i < 10; i++) {
        p[i].~Foo();
    }
    //delete[] p; this works

    ::operator delete(p);
    //operator syntax destroy the object and deallocate. function call syntax just deallocate
}

/*  */int main(void){
    doit();
}*/
