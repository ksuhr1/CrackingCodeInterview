//
//  main.cpp
//  codewhoop
//
//  Created by Katelyn Suhr on 7/23/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};

//global head pointer
Node *head = NULL;

//insert node at beginning
void insertBeg(int d)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->link = head;
    head = ptr;
}

//insert node at end
void insertEnd(int d)
{
    Node *ptr = new Node();
    ptr->data = d;
    ptr->link = NULL;
    
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        Node *temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
    
}

void displayList()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << "\n";
}

void deleteBeg()
{
    //if linked list is empty
    if(head== NULL)
    {
        cout << "List Empty";
    }
    else
    {
        Node *ptr = head;
        head = head->link;
        free(ptr); //frees pointer head from the memory
    }
    
}

void deleteEnd()
{
    //traverse to last node
    //make link of second to last not next node null
    
    Node *ptr, *prev;
    if(head == NULL)
    {
        cout << "List Empty";
    }
    if(head->link == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        Node *prev;
        ptr = head;
        
        //traverse till reach last node
        while(ptr->link != NULL){
            //keep track of previous node
            prev = ptr;
            ptr = ptr->link;
        }
        //when we reach last node
        prev->link = NULL;
        //delete last node
        free(ptr);
    }
    ptr = head;
    prev = ptr;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    insertBeg(2);
    insertBeg(1);
    insertEnd(3);
    displayList();
    
    deleteBeg();
    displayList();
    deleteEnd();
    displayList();
    return 0;
}
