//
//  stack.cpp
//
//  Created by Katelyn Suhr on 8/09/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved
//

#include <iostream>

using namespace std;

#define MAX 1000


class Stack
{
    int top;
public:
    int a[MAX]; //Maximum size of Stack

    //constructor
    Stack()
    {
        top = -1;    
    }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top >= (MAX-1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }

}

int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }

}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main(int argc, const char * argv[])
{
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " Popped from the stack \n";
    cout << s.pop() << " Popped from the stack \n";

    return 0;

}
































