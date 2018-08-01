//
//  main.cpp
//  KthElement
//  Created by Katelyn Suhr on 7/31/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//
//implement a function to chek if a linked list is a palindrome
//singly linked list
#include <iostream>

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
    
public:
    
    //constructor
    linked_list()
    {
        head = NULL;
        tail = NULL;
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
        
    }
    
    Node<T> *gethead()
    {
        return head;
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
};



Node<int> *removeKFromList(Node<int> *head, int k)
{
    Node<int> *curr = head;
    Node<int> *prev = nullptr;
    
    while(curr != NULL)
    {
        if(curr->data == k)
        {
            if(prev!= NULL)
            {
                prev->next = curr->next;
                // free(curr);
            }
            else // at head of the list
            {
                Node<int> *temp = head;
                head = head->next;
                free(temp); //frees pointer head from the memory
            }
            
            
        }
        prev = curr; //update pointer - should this be updated no matter what?
        curr = curr->next; //update current no matter what
        
    }
    return curr;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list<int> a;
    a.add_node(3);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(3);
    cout << "Before removing Kth element"<< endl;
    a.display(a.gethead());
    removeKFromList(a.gethead(),3);
    cout << "After removing Kth element"<< endl;
    a.display(a.gethead());
    
    return 0;
}
