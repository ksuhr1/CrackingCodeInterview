//
//  main.cpp
//  2.5
//
//  Created by Katelyn Suhr on 7/27/18.
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
        node * curr = new node;
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
    
//    int remainder(node *head1, node *head2)
//    {
//        node *a = head1;
//        node *b = head2;
//        int righthand = 0;
//        int lefthand = 1;
//
//        int sum = a->data + b->data;
//
//        if(sum > 10)
//        {
//            righthand = sum % 10;
//        }
//
//        cout << "Righthand: "<< righthand << endl;
//        cout << "Sum: " << sum << endl;
//
//        return sum;
//    }
    
    //add contents of two linked lists and return the head node of resultant list
    node *addLists(node *first, node *second)
    {
        node *result = NULL;
        node *temp = NULL;
        node *prev = NULL;
        int carry = 0, sum;
        
        while(first != NULL || second != NULL)
        {
            sum = carry + (first? first->data: 0) + (second? second->data : 0);
            
            //update carry for next calculation
            carry = (sum>=10)? 1: 0;
            
            //update sum if it is greater than 10
            sum = sum % 10;
            
            //create a new node with sum as data
            node *temp = new node;
            temp->data = sum;
            
            //if this is the first node, then set it as head of the resultant list
            if(result == NULL)
            {
                result = temp;
            }
            else //if this is not the first node, then connect it to the rest
            {
                prev->next = temp;
            }
            
            //set prev for next insertion
            prev = temp;
            
            //move first and second pointers to next nodes
            if(first) first = first->next;
            if(second) second = second->next;
        }
        if(carry > 0)
        {
            temp->next = add_node(carry);
        }
        cout << "Result: "<< result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    linked_list a;
    linked_list b;isPalindrome(const std::string& word)
    a.add_node(7);
    a.add_node(2);
    a.add_node(3);
    
    b.add_node(5);
    b.add_node(7);
    b.add_node(8);
   
    linked_list c;
    
    c.addLists(a.gethead(), b.gethead());
    
    c.display(c.gethead());
    return 0;
}
