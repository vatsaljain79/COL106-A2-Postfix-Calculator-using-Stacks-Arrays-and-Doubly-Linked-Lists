#include <iostream>
#include "node.h"
using namespace std;
Node::Node(bool sentinel){
    is_sentinel=true;
    next=nullptr;
    prev=nullptr;
}
Node::Node(int v, Node* nxt, Node* prv){
    if(nxt!=nullptr and prv!=nullptr){
        is_sentinel=false;
    }
    next=nxt;
    prev=prv;
    value=v;
}
bool Node::is_sentinel_node(){
    return is_sentinel;
}
int Node::get_value(){
    return value;
}
