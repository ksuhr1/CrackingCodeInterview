//
//  main.cpp
//  linkedlistc
//
//  Created by Katelyn Suhr on 7/16/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>

int empty(struct node *head);
void print_list(struct node *head);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

struct node
{
    int data;
    struct node *link; //pointer too next node in linked list
};

//This function returns a value of 1 if linked list is empty
int empty(struct node *head)
{
    //Declare variables
    int k = 0;
    
    //Determine if the list is empy
    if(head == NULL)
    {
        k = 1;
    }
    return k;
}

//this function prints a linked list
void print_list(struct node *head)
{
    //Declare variables
    struct node *next;
    
    //print linked list
    if(empty(head))
        printf("Empty list \n");
    else
    {
        printf("List Values: \n");
        next = head;
        while(next->link != NULL)
        {
            printf("%d \n", next->data);
            next = next->link;
        }
        printf("%d \n", next->data);
    }
    //void return
    return;
    
}

