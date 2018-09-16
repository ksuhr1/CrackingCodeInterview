#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    private:
        Node *head, *tail;
    public:
        //constructor
        Queue()
        {
            head = NULL;
            tail = NULL;
        }

        void enqueue(int n);
        void dequeue();
        void display();
        int peek();
        ~Queue();
};

//add to the tail
void Queue::enqueue(int n)
{
    Node *temp = new Node;
    //confused by this function check?
    if(temp == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }

    temp->data = n;
    temp->next = NULL;
    
    //if first one
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail-> next = temp;
        tail = temp;
    }
}

//remove from the head
void Queue::dequeue()
{
    if(head == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
        }
    }

}

int Queue::peek()
{
    if(head == NULL)
    {
        cout << "Nothing to peek" << endl;
        return 0;
    }
    else
    {
        int x = head->data;
        return x;
    }
}

void Queue::display()
{
    if(head == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }

    Node *temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}


 int main(int argc, const char * argv[])
{
    Queue q;
    q.display();

    q.enqueue(10);
    q.enqueue(24);
    q.enqueue(28);
    q.enqueue(32);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
