#include <iostream>
#include "list.h"
#include <stdexcept>
// #include "node.cpp"
// #include "node.h"
using namespace std;
List::List(){
    size=0;
    sentinel_head=new(nothrow) Node(true);
    if (sentinel_head==nullptr){
            throw runtime_error("Out of Memory");}
    sentinel_tail=new(nothrow) Node(true);
    if (sentinel_tail==nullptr){
            throw runtime_error("Out of Memory");}
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
}
List::~List(){
    for (int i=1;i<=this->get_size();i++){
        this->delete_tail();
    }
    sentinel_head->next=nullptr;
    sentinel_tail->prev=nullptr;
    delete sentinel_head;
    delete sentinel_tail;

}
void List::insert(int v){
    
    Node *pt =new(nothrow) Node(v,nullptr,nullptr);
    if (pt==nullptr){
            throw runtime_error("Out of Memory");}
    pt->next=sentinel_tail;
    pt->prev=sentinel_tail->prev;
    sentinel_tail->prev->next=pt;
    sentinel_tail->prev=pt;
    size+=1;
    
}
int List::get_size(){
    return size;
}
Node* List::get_head(){
    return sentinel_head;
}
int List::delete_tail(){
    // Node *temp=sentinel_head;
    if (size==0){
        throw runtime_error("Empty Stack");
    }else{
        int temp=sentinel_tail->prev->get_value();
        Node *dele=sentinel_tail->prev;
        sentinel_tail->prev=sentinel_tail->prev->prev;
        sentinel_tail->prev->next=sentinel_tail;
        delete dele;
        size-=1;
        return temp;
    }
}



// int main(){
//     // cout<<"drh";
//     List lst;
//     lst.insert(254);
//     // cout<<lst.get_size();
//     lst.insert(5);
    
//     cout<<lst.get_size()<<endl;
//     cout<<lst.delete_tail()<<endl;
//     // cout<<lst.get_size()<<endl;
//     cout<<lst.delete_tail()<<endl;
//     lst.insert(23);
//     lst.insert(65);
//     cout<<lst.delete_tail()<<endl;
//     // cout<<lst.get_size()<<endl;
// }
