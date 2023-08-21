#include <iostream>
#include "stack_c.h"
#include <stdexcept>
#include "list.h"
// #include "list.cpp"
// #include "node.cpp"
using namespace std;
Stack_C::Stack_C(){
    stk=new(nothrow) List();
    if (stk==nullptr){
            throw runtime_error("Out of Memory");}
}
Stack_C::~Stack_C(){
    delete stk;
}
void Stack_C::push(int data){
    // cout<<4;
    stk->insert(data);
    // cout<<4;
}
int Stack_C::pop(){
    return stk->delete_tail();
}
int Stack_C::get_element_from_top(int idx){
    int sixe=stk->get_size();
    int indexx=sixe-idx;
    if (indexx<1 || indexx>sixe ){
        throw std::runtime_error("Index out of range");
    }else{
        Node *temp=stk->get_head();
        temp=temp->next;
        int cnt=1;
        while (cnt<indexx){
            temp=temp->next;
            cnt+=1;
        }
        int get=temp->get_value();
        return get;
    }
}
int Stack_C::get_element_from_bottom(int idx){
    int indexx=idx+1;
    int sixe=stk->get_size();
    if (indexx<1 || indexx>sixe ){
        throw std::runtime_error("Index out of range");
    }else{
        Node *temp=stk->get_head();
        temp=temp->next;
        int cnt=1;
        while (cnt<indexx){
            temp=temp->next;
            cnt+=1;
        }
        int get=temp->get_value();
        return get;
    }
}
void Stack_C::print_stack(bool top){
    if (!top){
        Node* temp=stk->get_head();
        temp=temp->next;
        int i=0;
        int p=stk->get_size();
        while (i<p){
            cout<<temp->get_value()<<endl;
            temp=temp->next;
            i+=1;
        }
    }else{
        int p=stk->get_size();
        int arr[p];
        Node* temp=stk->get_head();
        temp=temp->next;
        int  i=0;
        while (i<p){
            arr[i]=temp->get_value();
            temp=temp->next;
            i+=1;
        }
        i-=1;
        while (i+1){
            cout<<arr[i]<<endl;
            i-=1;
        }

    }
}
int Stack_C::add(){
    int size=stk->get_size();
    if (size<2){
        throw runtime_error ("Not Enough Arguments");
    }else{
    
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    int c=b+a;
    stk->insert(c);
    return c;}
}
int Stack_C::multiply(){
    int size=stk->get_size();
    if (size<2){
        throw runtime_error ("Not Enough Arguments");
    }else{
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    int c=b*a;
    stk->insert(c);
    return c;}
}
int Stack_C::subtract(){
    int size=stk->get_size();
    if (size<2){
        throw runtime_error ("Not Enough Arguments");
    }else{
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    int c=b-a;
    stk->insert(c);
    return c;}
}
int Stack_C::divide(){
    int size=stk->get_size();
    if (size<2){
        throw runtime_error ("Not Enough Arguments");
    }else{
    int a=stk->delete_tail();
    int b=stk->delete_tail();
    if (a == 0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
        else
        {
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
                    
                }stk->insert(temp);
                return temp;
    
}}}
List* Stack_C::get_stack(){
    return stk;
}
int Stack_C::get_size(){
    int p=stk->get_size();
    return p;
}

// int main(){
//     Stack_C st;
//     // cout<<4;
//     // cout<<st.pop();
//     // st.push(5);
//     // st.push(2);
//     // st.push(9);
//     // int p=st.get_size(); 
//     // cout<<p<<endl;
//     // st.print_stack(1);
//     // st.pop();
//     // cout<<st.get_element_from_bottom(0)<<endl;
// //     st.print_stack(1);
// // int q=st.get_size(); 
// //     cout<<q<<endl;
// }