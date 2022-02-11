// 04/01/2002, edited 11/01/22.

// stack program, Last In First Out,
//   insertion or deletion only from top.
//   Eg: shuttle kok box.
// Operations: Push, pop, Top, IsEmpty.

// Remember the edge cases always, popping the
//  last element, displaying the stack if its empty.

#include <iostream>
using namespace std;

class node_data
{
public:
    int data;
    node_data *next;
};

//node_data *head = NULL;
node_data *node = NULL;

void empty(node_data *head)
{
    if(head==NULL)
        cout << "Stack is empty" << '\n';
    else
        cout << "Stack is not empty" << '\n';
}

void top(node_data *head)
{
    if(head==NULL)
        cout << "Stack is empty" << '\n';
    else
        cout << "Top data " <<head->data<<'\n';
}

void size(node_data *head)
{
    if (head == NULL)
        cout << "Stack is empty" << '\n';
    else
    {
        node_data *temp = head;
        int count = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            count++;
        }
        cout << "The size of the stack is: " << count << '\n';
    }
}

// Push.
node_data *push(node_data *p)
{
    // If head == NULL, then push into stack at first.
    if (p == NULL)
    {
        node_data *temp = new node_data;
        cout << "Push Data: " << '\n';
        cin >> temp->data;
        temp->next = NULL;
        p = temp;
        node = temp;
    }
    else
    {
        node_data *temp = new node_data;
        cout << "Push Data: " << '\n';
        cin >> temp->data;
        temp->next = p;
        p = temp;
    }
    return p;
}

// Pop.
node_data *pop(node_data *p)
{
    // Deleting the head node, after popping all
    //  and remaning only head node.
    if(p==NULL)
    {
        cout << "Stack is empty" << '\n';
        return NULL;
    }
    if (p->next == NULL)
    {
        p = NULL;
        return p;
    }
    node_data *temp = p;

    p = p->next;
    delete temp;

    return p;
}

void display(node_data *p)
{
    // The stack is empty
    if (p == NULL)
        cout << "Empty STACK" << '\n';

    node_data *temp = p;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << '\n';
}

int main()
{
    node_data *head = NULL;

    int choice;
    while (1)
    {
        cout << "Choose the option:" << '\n';
        cout << "  1. Push" << '\n';
        cout << "  2. Pop" << '\n';
        cout << "  3. Top" << '\n';
        cout << "  4. Empty" << '\n';
        cout << "  5. Size" << '\n';
        cout << "  6. Display" << '\n';
        cout << "  7. Exit" << '\n';
        cin >> choice;

        switch(choice)
        {
            case 1:
                head = push(head);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                top(head);
                break;
            case 4:
                empty(head);
                break;
            case 5:
                size(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                exit(0);
            }
    }

    return 0;
}