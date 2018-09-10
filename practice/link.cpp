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

        }

        void display_list(node *head)
        {
            if(head == NULL)
            {   
                cout << "NULL" << endl;
            }
            else
            {
                cout << head->data << " ";
                display_list(head->next);
            }
        }

};



int main(int argc, const char * argv[])
{
    cout << "Hello World" << endl;
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);

    a.display_list(a.gethead());
    

    return 0;
}
