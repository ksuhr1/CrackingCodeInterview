#include <iostream>

using namespace std;

#define MAX 1000

class Stack
{
    private:
        int top;
    public:
        //initialize an array
        int a[MAX];

        //constructor
        Stack()
        {
            top = -1;
        }

        //define methods
        int peek();
        bool push(int x);
        int pop();
        bool isEmpty();
        void showstack(Stack s);
};

int Stack::peek()
{
    //top is -1 if it is Empty
    if(isEmpty())
    {
        cout << "Nothing to peek" << endl;
        return 0;
    }
    else
    {

        int x = a[top];
        return x;
    }
}

int Stack::pop()
{
    //if the stack is empty
    if(top < 0)
    {
        cout << "Stack underflow" ;
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }

}

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

bool Stack::isEmpty()
{
    //stack is empty if top = -1
    //if stack is empty return true
    return (top < 0);
}

void Stack::showstack(Stack s)
{
    while(!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << "\n";

}

int main(int argc, const char * argv[])
{
    struct Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.showstack(s);
    

    return 0;

}


















