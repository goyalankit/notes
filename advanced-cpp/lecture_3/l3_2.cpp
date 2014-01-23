#include<iostream>
#include<cstdint>

class Foo{
    public:
        Foo(void) { std::cout << "default constructor\n"; }
        ~Foo(void) { std::cout << "destrcutor\n"; }
};

int doit(void){
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




template <Typename T>
class TemplateFoo{
    T x; //java: replaces T with void* i.e., generic type in c++
};

int main(void){
    TemplateFoo<Foo> f;
}

//JAVA: machine code produces is using the generic type. 
// In C++ generic type is void*
// x can hold any object. Any object can be translated.
// exactly 1 implementation.
//
// C++: template doens't lead to any machine code. template is a recipie. 
// WHen client specifies an argument, replaces T with Foo.
//


template <Typename T>
class Vector{
    T* buffer;
    T& operator[](int k){
        return buffer[k];
    }

    T oops(void){
        T::var_name = 42; //you need to make a guess what T:: is going to be.
                            //Assumes that T:: is going to be static compilation.
        T::type_name my_var;
        T k = *buffer;
        *k = k.does_not_exist(); //While writing a template you don't get any c++ code or machine code.
                                    //Never called so won't produce compilation error.
                                    //However this is syntax checked.
    }
};

int main(void){
    //no c++ code is generated until you use the template.
    //two different entire set of machine code is producesd if invoked with two different types.
    Vector<Foo> f;
    //default constructors
    //destrcutors
    Vector<int> g;

    f[10] = Foo{};

    g[3] = 42;
    //f = g; Error different type.
}

//In case of templates only methos is being called is instantiated.

class Bar{

    //cannot default construct it.
    public:
        Bar(int){}
        Bar(const Bar&){}
}


template <Typename T>
class Vector{
    Vector(void){   //places no restriction whatsover.
    }

    explicit Vector(int initial_size){
        buffer = new T[initial_size]; //assumes can be default construced.
    }
};

int main(void){
    //no c++ code is generated until you use the template.
    //two different entire set of machine code is producesd if invoked with two different types.
    Vector<Foo> f;
    //default constructors
    //destrcutors
    Vector<int> g;

    f[10] = Foo{};

    g[3] = 42;
    //f = g; Error different type.
    Vector<Bar> h; //not an error
    Vector<Bar> h2(10); //fails since required default constructor.
}


//only methods that are used are created. code will get compiled even if the method doesn't exists if it isn't called.
// templates are expanded at compiler time. can be expanded recursively.

template <typename T1, typename T2>

//template <class T1, class T2> only class was accepted in original version. they didn't do anything useful with class.
//typename was introduced to remove ambuguity.




class Fred{
    T1 x;
    T2 y;
};

int main(void){


}
