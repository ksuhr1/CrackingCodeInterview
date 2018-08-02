//
//  intersection.cpp
//  2.6
//
//  Created by Katelyn Suhr on 7/30/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.

// Given two (singly) linked lists, determine if the lists intersect.
// Return the intersecting node

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <vector>
#include <unordered_map>
#include <stdbool.h>

using namespace std;

struct ListNode
{
   int data;
   ListNode *next;
   ListNode(int x) : data(x), next(NULL){}

};

class Linked_List
{
   private:
      ListNode *head, *tail;

   public:
      //constructor
      Linked_List()
      {
         head = NULL;
         tail = NULL;
      }
      ~Linked_List(){}


      void add_node(int n)
      {
         ListNode *temp = new ListNode(n);
         temp->next = NULL;

         if(head == NULL)
         {
            head = temp;
            tail = temp;
         }
         else
         {
            tail->next = temp;
            tail = tail->next;
         }
      }

      ListNode *gethead()
      {
         return head;
      }

      void display(ListNode *head)
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

      ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
      {
        //vector<int>freq;
        unordered_map<int, int> freq;
        int i = 0;

        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
    
        while(curr1 != NULL)
        {
           i = curr1->data;
           freq[i]++;
           curr1 = curr1->next;
        }
        int j = 0;
        bool found = false;
        while(curr2->next != NULL)
        {
            

           j = curr2->data;
           if(freq.find(j) != freq.end())
           {
             // found = true;
             // cout << "Intersecting Node: " << curr2->data;
              return curr2;
           }
           else
           {
                curr2 = curr2->next;
 //               cout << curr2->data << endl;
           }
        }
        

        cout << "Output of hashmap : \n";
        unordered_map<int, int>:: iterator p;
        for(p = freq.begin(); p != freq.end(); p++)
        {
           cout << "(" << p->first << ", " << p->second << ")\n";
        }
       
        return curr2;
      }
};

int main(int argc, const char * argv[])
{
   cout << "Permutation problem" << endl;

   Linked_List a;
   a.add_node(1);
   a.add_node(2);
   a.add_node(3);
   a.add_node(4);
   a.add_node(5);
   
   Linked_List b;
   b.add_node(6);
   b.add_node(7);
   b.add_node(8);
   b.add_node(3);
   b.add_node(4);
   b.add_node(5);

   a.display(a.gethead());
   b.display(b.gethead());
   ListNode *found;

   found =b.getIntersectionNode(a.gethead(), b.gethead());
   if(found->next != NULL){
       cout << "Intersection Node: " << found->data<<endl;
   }
   else
   {
        cout << "No intersection found " << endl;
   }
   return 0;
}




