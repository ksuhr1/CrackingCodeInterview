//
//  main.cpp
//  2.3
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
    
    void deleteNode(node *n)
    {
        if(n == NULL || n->next == NULL){
            cout << "Not possible" << endl;
        }
        node *p = n->next;
        n->data = p->data;
        n->next = p->next; //deletes next node - don't understand this part
    }
    
//    node *deleteMiddle(node *head, int k)
//    {
//        node *curr = head;
//        node *prev = NULL;
//
//        while(curr->next != NULL)
//        {
//            if(curr->data == k && prev!=NULL)
//            {
//                prev->next = curr->next;
//                free(curr);
//                //cout<< "found the value: "<<curr->data<< endl;
//            }
//            else{
//                prev = curr;
//            }
//            curr = curr->next;
//
//        }
//        return curr;
//    }
    
    
    node *findNode(node *head, int n)
    {
        node *curr = head;
        while(curr!=NULL)
        {
            if(curr->data == n)
            {
                return curr;
            }
            curr = curr->next;
        }
        return curr;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list a;
    a.add_node(1);
    a.add_node(5);
    a.add_node(9);
    a.add_node(12);
    node *n = a.findNode(a.findhead(),9);
    a.deleteNode(n);
    a.display(a.findhead());
    cout << "\n";
    
    cout << "\n";
    return 0;
}
