#include "foo.h"

class Bar : public Foo<int>{
    typedef int T;
    virtual T doit(){ return 0; }

};

int main(void){
    Bar b;
return 0;

}
