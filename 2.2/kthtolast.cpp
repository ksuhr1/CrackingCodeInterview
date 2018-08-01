//
//  main.cpp
//  2.2
//
//  Created by Katelyn Suhr on 7/24/18.
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
    
    node *findhead()
    {
        return head;
    }
    
    void add_node(int n)
    {
        node *curr = new node;
        curr->data = n;
        curr->next = NULL;
        
        if(head == NULL)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            tail->next = curr;
            tail = tail->next;
        }
    }
    
    void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << head->data << " ";
            display(head->next);
        }
    }
    
    node *kthToLast(node *head, int k)
    {
        node *p1 = head;
        node *p2 = head;
        
        for(int i = 0; i < k; i++)
        {
            p1 = p1->next;
        }
        
        while(p1 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        cout << "node wanted: " << p2->data;
        return p2;
        
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list a;
    a.add_node(3);
    a.add_node(4);
    a.add_node(3);
    a.add_node(5);
    a.display(a.findhead());
    cout << "\n";
    a.kthToLast(a.findhead(), 2);
    cout << "\n";
    return 0;
}
