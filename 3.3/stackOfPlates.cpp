#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <assert.h>
//size_t is unsigned data type of at least 16 bits
//use this when values can't be negative

using namespace std;

#define SIZE 4

class Stack
{
    private:
        int top;
        int capacity;
        int *arr;
        int index;
    public:
        
        //constructor
        Stack(int size = SIZE);

        bool push(int x);
        int size();
        int pop();
        int peek();
        void display(Stack s);
        bool isEmpty();
        bool isFull();
};

class SetOfStacks:public Stack
{
    public:
        int max_size;
    //create vector of stacks
    private:
        vector<Stack> stack_of_plates;
 //       int index2;
    public:
        SetOfStacks(int x);
        void push(int x);
        void pop();
        void popAt(int index);
};

SetOfStacks::SetOfStacks(int x)
{
    max_size = x;
 //   index2 = 0;
}


void SetOfStacks::push(int x)
{
    if(stack_of_plates.empty())
    {
       Stack first;
       first.push(x);
       //push first stack into stack of plates
       stack_of_plates.push_back(first);
    }
    else
    {
        //get last stack size in stack of plates
        //if there is more room in stack, push the element
        int plate_size = stack_of_plates.back().size();
      
        if(plate_size < SIZE )
        {
            stack_of_plates.back().push(x);
        }
        else
        {
            //stack is full so create a new one
            Stack next;
            next.push(x);
            stack_of_plates.push_back(next);
           // index2++;
           // cout << "index: " << index2<< endl;
       }
         for(int i = 0; i < stack_of_plates.size(); i++)
         {
               stack_of_plates[i].display(stack_of_plates[i]); 
         }
    }

}

void SetOfStacks::pop()
{
    if(stack_of_plates.empty())
    {
        cout << "No elements to pop"<<endl;
        assert(0);
    }
    else
    {
        cout << "Popping: " << stack_of_plates.back().peek() << " from the last stack" << endl;
        stack_of_plates.back().pop();
        cout << "-----------------------Start of pop()---------------------"<<endl;
        for(int i = 0; i < stack_of_plates.size(); i++)
        {
               stack_of_plates[i].display(stack_of_plates[i]); 
        }
        if(stack_of_plates.back().isEmpty())
        {
            stack_of_plates.pop_back();   
        }
    }
}

void SetOfStacks::popAt(int index)
{
    if(!(index < stack_of_plates.size()))
    {
        cout << "No elements to pop at index: " << index << endl;
        assert(0);
    }
    else
    {
        cout << "Popping: " << stack_of_plates[index].peek() << " at index: " << index << endl;
        stack_of_plates[index].pop();
        for(int i = 0; i < stack_of_plates.size(); i++)
        {
            stack_of_plates[i].display(stack_of_plates[i]); 
        }
        if(stack_of_plates[index].isEmpty())
        {
            cout << "erasing" << endl;
            stack_of_plates.erase(stack_of_plates.begin()+index);
        }
    }

}

Stack::Stack(int size)
{
    top = -1;
    arr = new int[size];
    capacity = size;
    index = 0;
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top >= (SIZE-1));
}

int Stack::size()
{
    return index;
}
bool Stack::push(int x)
{
    if(isFull())
    { 
        cout << "Stack Overflow"<< endl;
        return false;
    }
    else
    {
        arr[++top] = x;
        index++;
        return true;
    }
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow"<< endl;
        return 0;
    }
    else
    {
        int x = arr[top--];
        index--;
        return x;
    }
}

int Stack::peek()
{
    if(!isEmpty())
    {
        return arr[top];
    }
    else
    {
        cout << "Stack is empty"<< endl;
        return 0;
    }
}

void Stack::display(Stack s)
{
    if(s.size() == 0 )
    {
       cout << "The Stack is empty" << endl;
    }   
    for(int i = top; i >= 0; i--)
    {
        cout <<"|" <<arr[i]<<"|"<< endl;
    //    cout << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    SetOfStacks s(2);
    s.push(100);
    s.push(101);
    s.push(103);
    s.push(104);

//    s.pop();
//    s.pop();
//    s.pop();
//    s.pop();

    s.push(105); //stack 0
    s.push(106);
    s.popAt(0);
    s.push(107); //onto stack 0
    s.push(108); //onto stack 1
    s.popAt(1);
    s.popAt(1);

    
    return 0;
}
