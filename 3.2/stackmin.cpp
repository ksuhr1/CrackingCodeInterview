#include <iostream>

using namespace std;

#define SIZE 10

class Stack{

    private:
        int top;
        int *arr;
        int capacity;
        int min;
    public:
        //constructor 
        Stack(int size = SIZE);

        bool push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
        int findMin();
        void display(Stack s);
};

Stack::Stack(int size)
{
    capacity = size;
    top = -1;
    arr = new int[size];
    min = 0;
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
        if(min == 0)
        {
            min = x;
        }
        if (x < min)
        {
            min = x;
        }
        cout << "current min: " << min << endl;
        return true;
    }
}

int Stack::findMin()
{
    cout << "min: " << min << endl;
    return min;

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

    Stack s(5);

    s.push(5);
    s.push(6);
    s.push(3);
    s.push(7);
    s.pop();
   // s.pop();

    s.display(s);
    s.findMin();
    s.pop();
    s.findMin();
    return 0;
}
