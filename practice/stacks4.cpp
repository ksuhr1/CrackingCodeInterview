#include <iostream>

using namespace std;

#define MAX 1000

class Stack
{
    private:
        int top;
    public:
        //initalize an array
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

bool Stack::isEmpty()
{
    return (top < 0);
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout << "Nothing to peek"<< endl;
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
    if(isEmpty())
    {
        cout << "Stack underflow" << endl;
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
        cout << "Stack Overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }

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

int main(int arc, const char * argv[])
{
    struct Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.showstack(s);
}
