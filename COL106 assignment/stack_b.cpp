#include <iostream>
#include <stdexcept>
#include "stack_b.h"
using namespace std;
Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    stk = new int[capacity];
}

Stack_B::~Stack_B() {
    delete[] stk;
}

// int myfloor(int a, int b)
// {
//     int c;
//     if (a * b >= 0)
//     {
//         c = a / b;
//     }
//     else
//     {
//         if (a % b == 0)
//         {
//             c = a / b;
//         }
//         else
//         {
//             c = (a / b) - 1;
//         }
//     }
//     return c;
// }

// catch (std::bad_alloc& excepObj)
//     {
//         throw std::runtime_error("Out of Memory");
//     }

    
void Stack_B::push(int data)
{
    // cout<<"Capacity: "<<capacity<<endl;
    // cout<<"size: "<<size<<endl;

    if (size == capacity)
    {   
        int *arr;
        arr = new(nothrow) int[2 * capacity];
        if (arr==nullptr){
            throw runtime_error("Out of Memory");
        }else{
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = stk[i];
        }
        stk = arr;
        capacity = capacity * 2;
    }}

    this->stk[size] = data;
    size += 1;
    // cout<<"Capacity: "<<capacity<<endl;
    // cout<<"size: "<<size<<endl;
}
int Stack_B::pop()
{
    // cout<<"Capacity: "<<capacity<<endl;
    // cout<<"size: "<<size<<endl;
    if (size == 0)
    {
        throw std::runtime_error("Empty Stack");
    }
    else
    {
        size -= 1;
        int temp = stk[size];
        if (capacity > 4 * size - 1 and capacity >= 2048)
        {
            int *arr;
            arr = new(nothrow) int[capacity / 2];
            if (arr==nullptr){
            throw runtime_error("Out of Memory");
        }else{
            capacity = capacity / 2;
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = stk[i];
            }
            delete stk;
            stk = arr;
        }}

        //     cout<<"Capacity: "<<capacity<<endl;
        // cout<<"size: "<<size<<endl;
        return temp;
    }

    // cout<<"Capacity: "<<capacity<<endl;
    // cout<<"size: "<<size<<endl;
}
int Stack_B::get_element_from_top(int idx)
{
    int get = size - idx - 1;
    // cout<<size<<endl;
    if (get < 0 || get > size - 1)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        // cout<<"sgf"<<endl;
        return stk[get];
    }
}
int Stack_B::get_element_from_bottom(int idx)
{
    if (idx < 0 || idx > size - 1)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        // cout<<stk[idx]<<endl;
        // cout<<"Capacity: "<<capacity<<endl;
        // cout<<"size: "<<size<<endl;
        // cout<<sizeof(stk)<<endl;
        // for (int i=0;i<sizeof(stk);i++){
        //     cout<<stk[i]<<" ";
        // }
        return stk[idx];
    }
}
int Stack_B::add()
{
    if (size < 2)
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {   
        
        int a = stk[size - 1];
        int b = stk[size - 2];
        int temp = a + b;
        stk[size - 2] = temp;
        size -= 1;
        if (capacity > 4 * size - 1 and capacity >=2048)
        {
            int *arr;
            arr = new(nothrow) int[capacity / 2];
            if (arr==nullptr){
            throw runtime_error("Out of Memory");
        }else{
            capacity = capacity / 2;
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = stk[i];
            }
            delete stk;
            stk = arr;
        }}
        //     cout<<"Capacity: "<<capacity<<endl;
        // cout<<"size: "<<size<<endl;
        
        return temp;
    }
}
int Stack_B::multiply()
{
    if (size < 2)
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk[size - 1];
        int b = stk[size - 2];
        int temp = a * b;
        stk[size - 2] = temp;
        size -= 1;
        if (capacity > 4 * size - 1 and capacity >= 2048)
        {
            int *arr;
            arr = new(nothrow) int[capacity / 2];
            if (arr==nullptr){
            throw runtime_error("Out of Memory");
        }else{
            capacity = capacity / 2;
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = stk[i];
            }
            delete stk;
            stk = arr;
        }}
        //     cout<<"Capacity: "<<capacity<<endl;
        // cout<<"size: "<<size<<endl;
        return temp;
    }
}
int Stack_B::subtract()
{
    if (size < 2)
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk[size - 1];
        int b = stk[size - 2];
        int temp = b - a;
        stk[size - 2] = temp;
        size -= 1;
        if (capacity > 4 * size - 1 and capacity >= 2048)
        {
            int *arr;
            arr = new(nothrow) int[capacity / 2];
            if (arr==nullptr){
            throw runtime_error("Out of Memory");
            }else{
            capacity = capacity / 2;
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = stk[i];
            }
            delete stk;
            stk = arr;
        }}
        //     cout<<"Capacity: "<<capacity<<endl;
        // cout<<"size: "<<size<<endl;
        return temp;
    }
}
int Stack_B::divide()
{
    if (size < 2)
    {
        throw std::runtime_error("Not Enough Arguments");
    }
    else
    {
        int a = stk[size - 1];
        int b = stk[size - 2];
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
                }
            stk[size - 2] = temp;
            size -= 1;
            if (capacity > 4 * size - 1 and capacity >= 2048)
            {
                int *arr;
                arr = new(nothrow) int[capacity / 2];
                if (arr==nullptr){
            throw runtime_error("Out of Memory");
        }else{
                capacity = capacity / 2;
                for (int i = 0; i < capacity; i++)
                {
                    arr[i] = stk[i];
                }
                delete stk;
                stk = arr;
            }}
            //     cout<<"Capacity: "<<capacity<<endl;
            // cout<<"size: "<<size<<endl;
            return temp;
        }
    }
}
void Stack_B::print_stack(bool top)
{
    if (top)
    {
        int p = size;
        // cout<<p<<endl;
        while (p)
        {
            cout << stk[p - 1] << endl;
            p -= 1;
        }
    }
    else
    {
        int p = 0;
        while (p < size)
        {
            cout << stk[p] << endl;
            p += 1;
        }
    }
}
int Stack_B::get_size()
{
    return size;
}
int* Stack_B::get_stack(){
    return stk;
}
// int main()
// {
//     Stack_B st;
//     st.push(98);
//     // cout<<st.get_element_from_bottom(0)<<endl;
//     st.push(52);
//     st.push(-4);
//     st.push(584);
//     st.push(522);
//     st.push(5);
//     cout<<st.subtract()<<endl;
//     cout<<st.divide()<<endl;
//     // cout<<st.divide()<<endl;
//     // cout<<st.divide()<<endl;

//     cout<<st.add()<<endl;
//     // cout<<st.add();
//     cout<<st.pop()<<endl;
//     // cout<<st.pop()<<endl;
//     // cout<<st.pop()<<endl;
//     st.print_stack(0);
//     // cout<<st.get_element_from_bottom(586)<<endl;
//     // cout<<st.get_element_from_top(0)<<endl;
//     // cout<<st.pop()<<endl;
//     // st.push(324);
//     // st.pop();
//     // cout<<st.get_size()<<endl;
// }