#include <iostream>

using namespace std;
#define MAX 1000

class Stack
{
    private:
        int top;
    public:
        int a[MAX];

        //constructor
        Stack()
        {
            top = -1;
        }
        int peek();
        bool push(int x);
        int pop();
        bool isEmpty();
        void showstack(Stack s);
};

int Stack::peek()
{
    if(isEmpty()){
        cout << "Nothing to peek"<< endl;
        return 0;
    }
    else{
        int x = a[top];
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

int Stack::pop()
{
    if(top < 0)
    {
        cout <<"Stack Underflow";
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
    //if stack is empty return true
    return (top < 0);
}

void Stack::showstack(Stack s)
{
    while(!s.isEmpty())
    {
        cout << s.peek() << " " ;
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
    cout << "Peek: " << s.peek()<< endl;
    cout << s.pop() << " is popped from the stack \n";
    cout << s.pop() << " is popped from the stack \n";
    cout << "Peek: " << s.peek()<<endl;
    cout << s.pop() << " is popped from the stack \n";
    cout << "Peek: " << s.peek() << endl;
    return 0;
}
