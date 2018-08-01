//
//  main.cpp
//  2.61
//
//  Created by Katelyn Suhr on 7/31/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//
//implement a function to chek if a linked list is a palindrome
//singly linked list
#include <iostream>
#include <stdbool.h>

using namespace std;
template<typename T> struct Node
{
    Node(const T &v): data(v), next(nullptr){}
    T data; //object information
    Node *next; //pointer to next node element
};

template <typename T> class linked_list
{
private:
    Node<T> *head, *tail;
    int count;
    
public:
    
    //constructor
    linked_list()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    
    linked_list(const linked_list& list); //copy constructor
    
    //deconstructor
    ~linked_list(){}

    
    //method adds info to end of list
    void add_node(T info)
    {
        if(head == NULL)
        {
            head = new Node<T>(info);
            tail = head;
        }
        else
        {
            Node<T>* temp = new Node<T>(info);
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }
        count++;
        
    }
    
    Node<T> *gethead()
    {
        return head;
    }
    
    int size()
    {
        return count;
    }
    
    void display(Node<T> *head)
    {
        if(head == NULL)
        {
            cout << "NULL"<< endl;
        }
        else
        {
            cout << head->data << " ";
            display(head->next);
        }
        
    }
    
    void reverse()
    {
        Node<T> *curr = head;
        Node<T> *prev = NULL;
        Node<T> *n;
    
        while(curr != NULL)
        {
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        //update the head
        head = prev;
    }
    
    
    //if i have the size of linked list
    bool isPalidrome(Node<T> *original, Node<T> *reverse, int size)
    {
        int count = 0;
        bool pal = false;
        Node<T> *head1 = original;
        Node<T> *head2 = reverse;
        
        while(count < size/2 && head1 != NULL && head2 != NULL)
        {
            if(head1->data == head2->data)
            {
                count++;
                pal = true;
            }
            else
            {
                pal = false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        if(pal)
        {
            cout << "This string is a palindrome"<< endl;
        }
        else
        {
            cout << "This string is not a palindrome"<< endl;
        }
        return pal;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list<int> a;
    a.add_node(0);
    a.add_node(1);
    a.add_node(2);
    a.add_node(1);
    a.add_node(0);
   
    a.display(a.gethead());
    
    linked_list<int> c;
    c = a;
    c.reverse();
    c.display(c.gethead());
    
    a.isPalidrome(a.gethead(),c.gethead(), a.size());
    
    
    return 0;
}
