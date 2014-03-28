template<typename T>
class Foo{
    public:
        Foo(){}
       ~Foo(){}
   protected:
       virtual T doit() = 0;

};
