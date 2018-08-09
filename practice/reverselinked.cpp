//
//  main.cpp
//  reverselist
//
//  Created by Katelyn Suhr on 7/27/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};

class linked_list
{
private:
    node *head, *tail;
    
public:
    //constructor
    linked_list(){
        head = NULL;
        tail = NULL;
        
    }
    
    void add_node (int n)
    {
        node *curr = new node;
        curr->data = n;
        curr->link = NULL;
        
        if(head == NULL)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            tail->link = curr;
            tail = tail->link;
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
            display(head->link);
            
        }
        
    }
    
    void reverse()
    {
        node *curr, *prev, *next;
        
        prev = NULL;
        curr = head;
      
        while(curr != NULL)
        {
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.reverse();
    a.display(a.gethead());
    
    
    
    return 0;
}
