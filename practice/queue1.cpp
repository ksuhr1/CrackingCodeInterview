#include <iostream>

#define MAX 5

using namespace std;
class Queue{
    private:
        int head;
        int tail;
    public:
        int a[MAX];

    //constructor
    Queue()
    {
        head = -1;
        tail = -1;
    }

    //define functions
    bool isEmpty();
    int peek();
    void enqueue(int data);
    void dequeue();
    void displayQueue();
};

bool Queue::isEmpty()
{
   if(head == -1 && tail == -1)
   {    
        return true;
   }
   else
   {
        return false;
   }
}

int Queue::peek()
{
    if(isEmpty())
    {
        cout << "The queue is empty" << endl;
        return 0;
    }
    else
    {
        int x = a[head];
        return x;
    }
}

//can only insert at the rear
void Queue::enqueue(int data)
{
    if(tail == MAX-1)
    {
        cout << "Queue is full \n"<< endl;
    }
    else
    {
        if(head == -1)
        {
            head = 0;
        }
        tail++;
        a[tail] = data;
    }
    
}

//remove from the beginnning aka head
void Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        //check if there is only 1 element in the queue
        if(head == tail)
        {
            head = -1;
            tail = -1;
        }
        else
        {
            head++;
        }
    }
}

void Queue::displayQueue()
{
    if(isEmpty())
    {
        cout << "Queue is empty \n";
    }
    else
    {
        for(int i = head; i <= tail; i++)
        {
            cout << a[i] << " ";
        }
    }

}

int main(int argc, const char * argv[])
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << "Front of queue: ";
    q.peek();
    cout << endl;
    q.displayQueue();

    return 0;
}
