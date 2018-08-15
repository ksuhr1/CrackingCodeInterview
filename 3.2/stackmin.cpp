#include <iostream>

using namespace std;

#define SIZE 12

class Stack{

    private:
        int top;
        int *arr;
        int *arr2;
        int capacity;
    public:

        //constructor 
        Stack(int size = SIZE);
        bool push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
        void display(Stack s);
};

//this class supports all stack operations from Stack class
//used to store all the minimum elements
class Stack2: public Stack
{
    Stack min;

    public:
        void push(int x);
        int pop();
        int getMin();
};

void Stack2::push(int x)
{
    if(isEmpty())
    {
        Stack::push(x);
        min.push(x);
    }
    else
    {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if(x<=y)
            min.push(x);
    }
   
}

//remove top element from both stacks
int Stack2::pop()
{

    int x = Stack::pop();
    int y = min.pop();
    
    //push the popped element y back only if it is not equal to x
    //do this because if you had a bigger element in o.g list and you 
    //pop it off, you don't want to pop of smallest value in min list,
    //so you put it back
    if(x!=y)
        min.push(y);
    return x;
}

int Stack2::getMin()
{
    int x = min.pop();
    min.push(x);
    return x;


}


Stack::Stack(int size)
{
    capacity = size;
    top = -1;
    arr = new int[size];
}


bool Stack::push(int x)
{
    if(isFull())
    {
        cout<< "Overflow"<< endl;
        return false;
    }
    else
    {
        arr[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Underflow" << endl;
        return 0;
    }
    else
    {
        int x = arr[top--];
        return x;
    }   
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top > (SIZE-1));
}

int Stack::peek()
{
    if(!isEmpty())
    {
        return (arr[top]);
    }
    else
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
}

void Stack::display(Stack s)
{
     for(int i = 0; i <=top ; i++)
     {   
        cout << arr[i]<< " ";
     }   
     cout << endl;
}

int main(int argc, const char * argv[])
{

    Stack2 s;

    s.push(5);
    s.push(6);
    s.push(3);
    s.push(7);
    s.display(s);
    cout <<"Min: " << s.getMin() << endl;
    s.push(2);
    s.display(s);
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    s.display(s);
    cout << "Min after a pop: " << s.getMin() << endl;
    return 0;
}
