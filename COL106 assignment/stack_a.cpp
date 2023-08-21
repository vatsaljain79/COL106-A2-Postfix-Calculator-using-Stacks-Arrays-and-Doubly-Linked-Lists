#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
Stack_A::Stack_A(){
    size=0;
}
// int myfloor(int a, int b){
//     int c;
//     if (a*b>=0){
//         c=a/b;
//     }else{
//         if (a%b==0){
//             c=a/b;
//         }else{
//         c=(a/b)-1;
//     }}
//     return c;
// }
void Stack_A::push(int data){
    if (size==1024){
            throw std::runtime_error("Stack Full");
        }else{
        this->stk[size]=data;
        size+=1;
        }
}
int Stack_A::pop(){
    if (size==0){
        throw std::runtime_error("Empty Stack");
    }else{
        size-=1;
        return stk[size];
        
    }
}
int Stack_A::get_element_from_top(int idx){
    int get=size-idx-1;
    if (get<0 || get>size-1){
        throw std::runtime_error("Index out of range");
    }else{
        return stk[get];
    }
}
int Stack_A::get_element_from_bottom(int idx){
    if (idx<0 || idx>size-1){
        throw std::runtime_error("Index out of range");
    }else{
        return stk[idx];
    }
}
void Stack_A::print_stack(bool top){
    if (top){
        int p=size;
        // cout<<p<<endl;
        while (p){
            cout<<stk[p-1]<<endl;
            p-=1;
        }
    }else{
        int p=0;
        while (p<size){
            cout<<stk[p]<<endl;
            p+=1;
        }
    }
}
int Stack_A::add(){
    if (size<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int a=stk[size-1];
        int b=stk[size-2];
        int c=a+b;
        stk[size-2]=c;
        size--;
        return c;
    }
}
int Stack_A::subtract(){
    if (size<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int a=stk[size-1];
        int b=stk[size-2];
        int c=b-a;
        stk[size-2]=c;
        size--;
        return c;
    }
}
int Stack_A::multiply(){
    if (size<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int a=stk[size-1];
        int b=stk[size-2];
        int c=a*b;
        stk[size-2]=c;
        size--;
        return c;
    }
}
int Stack_A::divide(){
    if (size<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int a=stk[size-1];
        int b=stk[size-2];
        if (a==0){
            throw std::runtime_error("Divide by Zero Error");
        }else{
        // int c=myfloor(b,a);
        int temp;
            if ((a>0 and b>0) || (a<0 and b<0))
                {
                    temp = b / a;
                }
                else
                {
                    if (b % a == 0)
                    {
                        temp = b / a;
                    }
                    else
                    {
                        temp = (b / a) - 1;
                    }
                }
        stk[size-2]=temp;
        size--;
        return temp;}
    }
}
int* Stack_A::get_stack(){
    return stk;
}
int Stack_A::get_size(){
    return size;
}
// int main(){}
// int main(){
//     Stack_A st;
//     // cout<<st.pop()<<endl;
//     st.push(-5);
//     st.push(4);
//     st.push(3);
//     cout<<st.pop()<<endl;
//     cout<<st.divide()<<endl;
//     // cout<<st.pop()<<endl;
//     // cout<<st.get_element_from_bottom(-1)<<endl;
//     // st.print_stack(true);
//     // cout<<st.divide()<<endl;
//     // int *temp=st.get_stack();
//     // cout<<temp;
//     cout<<st.get_size();
//     // cout<<st.add()<<endl;
// }