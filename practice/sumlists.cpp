#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
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
        
        void add_node(int n)
        {

            ListNode *curr = new ListNode(0);
            curr->val = n;
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

        void display(ListNode *head)
        {
            if(head == NULL)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << head->val << "->";
                display(head->next);
            }
        }

        ListNode *gethead()
        {
            return head;
        }

        void addTwoNumbers(ListNode *l1, ListNode *l2)
        {   
            ListNode *p = l1;
            ListNode *q = l2; 
            int carry = 0;
           
            ListNode *curr  = new ListNode(0);
            this->head = curr;
            ListNode *prev = NULL;
            while(p!=NULL || q!=NULL)
            {
                int x = (p!=NULL) ? p->val : 0;
                int y = (q!=NULL) ? q->val : 0;
               
                int sum = x+y+carry;
              
                //update carry
                carry = sum/10;
                curr->next = new ListNode(sum % 10);
                if(prev == NULL)
                {
                    this->head = curr->next;
                }

                prev = curr;
                curr = curr->next;
                if(p!=NULL) p = p->next;
                if(q!=NULL) q = q->next;
                   
           }
            if(carry > 0)
            {
                curr->next = new ListNode(carry);
            }
        }
};

int main(int argc, const char *argv[])
{
    cout << "Return the sum of two linked lists"<< endl;
    Linked_List a;
    a.add_node(0);
    a.add_node(1);
   
    
    Linked_List b;
    b.add_node(0);
    b.add_node(1);
    b.add_node(2);
    
    a.display(a.gethead());
    b.display(b.gethead());
 
    Linked_List c;
    c.addTwoNumbers(a.gethead(),b.gethead());
 
    c.display(c.gethead());
    return 0;
}
