#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

#include <string>

using namespace std;

//Stack Template Class
template <class T>
class StackTemplate{

public:
    //instance variables
    int size;
    T* stackPointer;
    T s[100];

    //constructor
    StackTemplate(){
        size =  0;
        stackPointer = nullptr;
    }

    ~StackTemplate(){
    }

    // allows for assignment between nodes
    void operator=(StackTemplate<T> &obj){

        size = obj.size;
        empty = obj.empty;

        for(int i = 0; i <= size; i ++){
            s[i] = obj.s[i];
        }

        stackPointer = obj.stackPointer;
    }

    //construct and insert element element
    void emplace(T t){
        stackPointer = new T(t);
        s[size] = t;
        size ++;
    }

    //insert an element
    void push(T val){
        stackPointer = new T(val);
        s[size] = val;
        size ++;
    }

    //remove top element
    void pop(){
        if(stackPointer != nullptr){
            s[size] = NULL;
            size --;
            if(size <= 0){
                stackPointer = nullptr;
            }else{
                stackPointer = new T(s[size-1]);
            }
        }else{
            return;
        }
    }

    //copy the arrays
    void swap(StackTemplate& sT){
        StackTemplate temp = sT;
        sT = this;
        this = temp;
    }

    //access top element
    T* top(){
        return stackPointer;
    }

    bool empty(){
        if(stackPointer == nullptr){
            return true;
        }else {
            return false;
        }
    }

    int get_size(){
        return size;
    }
};
#endif // STACKTEMPLATE_H
