//
//  main.cpp
//  2.4
//
//  Created by Katelyn Suhr on 7/26/18.
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
    
    void add_node(int n)
    {
        
        node *p = new node;
        p->data = n;
        p->next = NULL;
        
        if(head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        
    }
    
    node *gethead()
    {
        return head;
    }
    
    void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << " ";
            display(head->next);
        }
        
    }
    void deleteFirst()
    {
        if(head == NULL){
            cout << "List is empty" << endl;
        }
        else
        {
            node *ptr = head;
            head = head->next;
            free(ptr);
        }
       // display(head);
    }
    
    linked_list partition(int val, node *head)
    {
        linked_list b;
        node *curr = head;
        node *prev = NULL;
        
        if(head == NULL)
        {
            cout << "Can't partition"<< endl;
        }
        while(curr != NULL)
        {
            if(curr->data < val)
            {
                //add node to linked list b
                b.add_node(curr->data);
                if(prev != NULL)
                {
                    // delete node
                    prev->next = curr->next;
                }
                else
                {
                    this->deleteFirst();
                }
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
        return b;
    }
    
    
    linked_list add_lists(linked_list b, linked_list a)
    {
        node *a_head = a.gethead();
        node *b_head = b.gethead();
        linked_list c;
        
        while(a_head != NULL){
            c.add_node(a_head->data);
            a_head = a_head->next;
            
        }
        
        while(b_head != NULL){
            c.add_node(b_head->data);
            b_head = b_head->next;
        }
        return c;
        
    }
    
    
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list a;
    linked_list b;
    linked_list c;
    a.add_node(3);
    a.add_node(5);
    a.add_node(8);
    a.add_node(5);
    a.add_node(10);
    a.add_node(2);
    a.add_node(1);
    
    a.display(a.gethead());
    b = a.partition(5, a.gethead());
    c = c.add_lists(a,b);
    c.display(c.gethead());
    return 0;
}
