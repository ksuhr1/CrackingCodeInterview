#include <cstdlib>
#include <iostream>

using namespace std;


struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*head;

class doubly_linkedlist
{

public:
    
    void create_list(int value);


    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void search_element(int value);
    void display_dlist();
    void count();
    void reverse();
    void insert_end(int value);

    doubly_linkedlist()
    {
        head = NULL;
    }
};

void doubly_linkedlist::create_list(int value)
{
    struct node *start, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;

    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        start = head;
        while(start->next != NULL)
        {
            start = start->next;
        }
        start->next = temp;
        temp->prev = start;
    }
}

void doubly_linkedlist::insert_end(int value)
{

    if(head == NULL)
    {
        cout << "First create the list" << endl;
    }
    else
    {
        
        node *start = head;
        while(start->next != NULL)
        {
            start = start->next;
        
        }

        node *temp = new (struct node);
        temp->info = value;
        start->next = temp;
        temp->next = NULL;
        temp->prev = start;
        

    }
}

void doubly_linkedlist::display_dlist()
{
    struct node *curr;
    if(head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    curr = head;
    cout << "The doubly linked list is : " << endl;

    while(curr != NULL)
    {
        cout << curr->info << "<->";
        curr = curr->next;
    }
    cout << "NULL" << endl;

}

void doubly_linkedlist::add_begin(int value)
{
    if(head == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = head;
    head->prev = temp;
    head = temp;
    cout << "Element Inserted" << endl;
}

void doubly_linkedlist::add_after(int value, int pos)
{
    if(head == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }

    struct node *temp, *q;
    
    q = head;
    int i;
    for(i = 0; i < pos-1; i ++)
    {
        q = q->next;
        if(q == NULL)
        {
            cout << "There are less than ";
            cout << pos<< " elements." << endl;
            return;
        }
    }
    temp = new(struct node);
    temp->info = value;
    //inserting at the end of the list
    if(q->next == NULL)
    {
        q->next = temp;
        temp->next = NULL;
        temp->prev = q;
    }
    else
    {
        temp->next = q->next;
        q->next->prev = temp;
        q->next = temp;
        temp->prev = q;
    }
    cout << "Element Insterted" << endl;

}

void doubly_linkedlist:: delete_element(int value)
{

    //first element deleted
    struct node *temp, *q;
    if(head->info== value)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        cout << "Element Deleted" << endl;
        free(temp);
        return;
    }

    q = head;

    //must be at least 3 elements
    while(q->next->next != NULL)
    {
        if(q->next->info == value)
        {
            temp = q->next;
            q->next = temp->next;
            temp->prev = q;
            cout << "Element Deleted " << endl;
            free(temp);
            return;
        }
        q = q->next;

    }
    //last element deleted

    if(q->next->info == value)
    {
        temp =q->next;
        free(temp);
        q->next = NULL;
        cout << "Element Deleted" << endl;
        return;
    }
    cout << "Element" << value<< "not found "<< endl;

}

void doubly_linkedlist::count()
{
    struct node *q = head;
    int count = 0;
    while(q!=NULL)
    {
        q = q->next;
        count++;
    }
    cout << "Number of elements are: " << count << endl;

}

void doubly_linkedlist::reverse()
{
    struct node *p1, *p2;
    p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    cout << "List Reversed" << endl;



}


int main(int argc, char **argv)
{

    int choice;
    int element;
    int position;
    doubly_linkedlist dl;

    while(1)
    {
        cout << endl << "------------------------" << endl;
        cout << endl << "Operations on Doubly Linked List" << endl;
        cout << endl << "------------------------" << endl;
        cout << "1. Create Node" << endl;
        cout << "2. Add at beginning " << endl;
        cout << "3. Add after position " << endl;
        cout << "4. Insert at the end" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Display" << endl;
        cout << "7. Count" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the element: ";
                cin >> element;
                dl.create_list(element);
                cout << endl;
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> element;
                dl.add_begin(element);
                cout << endl;
                break;

            case 3:
                cout << "Enter the element: ";
                cin >> element;
                cout<< "Insert Element after position: ";
                cin >> position;
                dl.add_after(element, position);
                cout << endl;
                break;

            case 4:
                cout << "Enter the element: ";
                cin >> element;
                dl.insert_end(element);
                cout << endl;
                break;

            case 5:
                if(head == NULL)
                {

                    cout << "List empty, nothing to delete" << endl;
                    break;
                }
                cout << "Enter the element for deletion: ";
                cin >> element;
                dl.delete_element(element);
                cout << endl;
                break;
            case 6:
                dl.display_dlist();
                cout << endl;
                break;
            case 7:
                dl.count();
                break;

            case 8:
                dl.reverse();
                cout << endl;
                break;
            case 9:
                exit(1);
            default:
                cout << "Wrong choice: " << endl;
        }
    }
    return 0;
}
