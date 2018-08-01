//
//  main.cpp
//  remove Kth element
//
//  Created by Katelyn Suhr on 7/23/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>


using namespace std;

struct node
{
    int data;
    struct node *next;
};

class linked_list
{
private:
    node *head, *tail;
    
public:
    
    //constructor
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    
    node *findhead(){
        return head;
    }
    
    void add_node(int n)
    {
        node *curr = new node;
        curr->data = n;
        curr->next = NULL;
        
        if(head == NULL){
            head = curr;
            tail = curr;
        }
        else{
            tail->next = curr;
            tail = tail->next;
            
        }
        
    }
    
    void displayList()
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    
    void deleteBeg()
    {
        
        if(head == NULL)
        {
            cout << "List is empty";
        }
        else
        {
            node *ptr = head;
            head = head->next;
            free(ptr);
        }
        
    }
    
    
    void removeKthElement(node *head, int k)
    {
        node *curr = head;
        node *prev = nullptr;

        while(curr != NULL){
            if(curr->data == k){
                if(prev != NULL)
                {
                    prev->next = curr->next;
                }
                //if k is at the head of the list and you want to delete it
                else{
                    this->deleteBeg();
                }
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    linked_list a;
  //  a.add_node(3);
    a.add_node(3);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
    a.removeKthElement(a.findhead(), 3);
    a.displayList();
    
    
    return 0;
}


