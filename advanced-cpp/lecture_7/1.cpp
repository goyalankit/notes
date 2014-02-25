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

    template <typename Ptr, typename T, typename CompType>
        Ptr partition(Ptr b, Ptr e, CompType comp){
            if(b==e) { return b; }
            Ptr p = b;
            Ptr k = b;
            ++k;
            while(k!=e){
                if(*k < *p){ //NOT GENERIC W.R.T element type
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

    template <typename Ptr>
        void sort(Ptr b, Ptr e, bool (*comp)(decltype(*b), decltype(*b))){
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

bool comp_fun(int x, int y){
    if (y < x ) { return true; }
    return false;
}

int main(void){

    int x[10] = {5, 2, 3, 9, 1, 6, 8, 2, 3, 4};
    printSequence(&x[0], &x[10]);
    epl::sort(&x[0], &x[10], &comp_fun);
    std::vector<int> y {1, 4, 2, 5, 6};

    printSequence(y.begin(), y.end());


    return 0;
}
