//
//  main.cpp
//  linkedlist
//
//  Created by Katelyn Suhr on 7/16/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>
#include <map>
#include<unordered_set>

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
    int length;
    
public:
    
    //constructor
    linked_list()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    node *gethead()
    {
        return head;
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
        length++;
        cout << "length: " << length << endl;
    }
    
    static void print_list(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL"<< endl;
        }
        else
        {
            cout << head->data << endl;
            print_list(head->next);
        }
    }
    
    void deleteDup(node *start)
    {
        node *curr = start;
        node *prev = NULL;
        unordered_set<int> map;
        
        while(curr != NULL)
        {
            //if the value is found in the list
            if(map.find(curr->data) != map.end())
            {
                prev->next = curr->next;
            }
            //add node to hashtable
            else
            {
                map.insert(curr->data);
                prev = curr;
            }
            curr = curr->next;
        }
        
    }
    
    int findLength(node *start)
    {
        node *curr = start;
        int count = 0;
        
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        //cout << "count:" << count << endl;
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //object of linked_list
    linked_list a;
    a.add_node(10);
    a.add_node(11);
    a.add_node(11);
    a.add_node(12);
    a.add_node(13);
    a.add_node(12);
    
   // a.findLength(a.gethead());
    a.deleteDup(a.gethead());
    a.print_list(a.gethead());
   


    
    return 0;
}
