/*
 * =====================================================================================
 *
 *       Filename:  smart_pointers.cpp
 *
 *    Description:  smart pointer implementation
 *
 *        Version:  1.0
 *        Created:  02/04/2014 12:59:25
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

template <typename T>

class SmartPointer{
    private:
        struct ControlBlock{
            T *object = nullptr;
            uint32_t refs = 0;

            public:
            ControlBlock(T * _object, uint32_t _ref) : object{ _object }, refs(_ref) {}
            ControlBlock() : object{nullptr}, refs{ 0 }{}
            ControlBlock(const ControlBlock&) = delete;
            ControlBlock& operator=(const ControlBlock&) = delete;
        };

        ControlBlock *ctrl;

        void destroy(){
            if(ctrl){
                ctrl -> refs -= 1;
                if(ctrl->refs == 0){
                    delete ctrl->object;
                    delete ctrl; //will free the memory associated with ctrl. Will call destructor.
                }
                /* in case refs != 0 we don;t want to free the memory associated with ctrl */
                ctrl = nullptr;
            }
        }

        void copy(const SmartPointer<T> &rhs){
            this->ctrl = rhs.ctrl;
            ctrl->refs += 1;
        }

        void move(SmartPointer<T> &&rhs){
            //TODO
        }

    public:
        SmartPointer(){ ctrl = nullptr; }

        SmartPointer(T* native){
            ctrl = new ControlBlock{native, 1};
        }

        ~SmartPointer(){
            destroy();
        }

        SmartPointer(const SmartPointer<T>& rhs){
            copy(rhs);
        }

        SmartPointer<T>& operator=(const SmartPointer<T>& rhs){
            if(this != &rhs){
                destroy();
                copy(rhs);
            }
            return *this;
        }

        SmartPointer(SmartPointer<T> &&rhs){
            ctrl = rhs.ctrl;
            rhs.ctrl = nullptr;
        }

        SmartPointer<T>& operator=(SmartPointer<T> &&rhs){
            this->move(std::move(rhs));
        }

        T& operator*(){
            return (*ctrl->object);
        }

        T* operator->(){
            return (ctrl->object);
        }

};

int main(void){
    //    SmartPointer<T> p; //no memory is associated with p.
    int a[10];
    9[a] = 23;
    return 0;
}
