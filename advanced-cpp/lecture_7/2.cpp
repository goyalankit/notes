#include <iostream>
#include <cstdint>
#include <vector>

template <typename Ptr>
void printSequence(Ptr b, Ptr e){
    const char* prefix = "";
    while(b!=e){
        std::cout << prefix << *b;
        ++b; //
        prefix = ", ";
    }
    std::cout << std::endl;
}


namespace epl{
    template <typename Ptr>
        uint64_t distance(Ptr b, Ptr e){
            uint64_t result=0;
            while(b!=e){
                ++result;
                ++b;
            }
            return result;
        }

    template <typename Ptr, typename CompType>
        Ptr partition(Ptr b, Ptr e, CompType comp){
            if(b==e) { return b; }
            Ptr p = b;
            Ptr k = b;
            ++k;
            while(k!=e){
                //To inlnie: need to know the type of comp and what method needs to be called exactly
                if(comp.operator()(*k, *p)){ //NOT GENERIC W.R.T element type OR ::::::::: comp(*k, *p)
                     //comp is a function object. Inlining will not happen in case of pointer
                    /*swap * into pivot spot*/
                    std::swap(*p, *k);
                    /* increase the number of smalls */
                    ++p;
                    /* and swap the pivot value back wher eit belongs */
                    std::swap(*p, *k);
                }
                ++k;
            }
            return p;
        }

    template <typename Ptr, typename CompFun>
        void sort(Ptr b, Ptr e, const CompFun& comp){
            /*if(e - b < 2){ //subtracting two pointers to get back their difference is a random access concept.
            return;         //Hence can't be used with linked lists.
            }
            */
            if(epl::distance(b,e) < 2 ) { return; }
            decltype(*b) pivot = *b;
            Ptr p = partition(b, e, comp);
            sort(b,p, comp);
            ++p;
            sort(p,e, comp);
        }
}//END namespace epl

//This will help inlining the method.

struct IntCompFun{
    bool operator()(int x, int y){
        if (y < x ) { return true; }
        return false;
    }
};

int main(void){

    int x[10] = {5, 2, 3, 9, 1, 6, 8, 2, 3, 4};
    printSequence(&x[0], &x[10]);
    std::vector<int> y {1, 4, 2, 5, 6};

    epl::sort(&y[0], &y[10], IntCompFun{});
    printSequence(y.begin(), y.end());


    return 0;
}
