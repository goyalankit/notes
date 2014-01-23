## lecture 3: constructors, templates

Following code gives a run time exception. Since `new` allocates and initializes the memory for an array of objects of type foo. It stores extra information (size of the array) at index -1. Pointer p points to 0th index.

```
#include<iostream>
#include<cstdint>

class Foo{
    public:
        Foo(void) { std::cout << "default constructor\n"; }
        ~Foo(void) { std::cout << "destructor\n"; }
};

int main(void){
    Foo * p = new Foo[100]; 
    delete p;
}

```

Above code can be easily fixed using:
```
delete[] p
```

---

### Operator syntax and Function Syntax

There is no difference between operator syntax and function call syntax for any method **except** `new` and `delete`

**`new`**
`new` used with **operator syntax**: space is **allocated** and **initialized**.

`new` used with **function syntax**: splice is just **allocated**. Not initialized.


