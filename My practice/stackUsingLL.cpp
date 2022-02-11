// 04/01/2002

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

node_data *node = NULL;

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
        temp->next = NULL;
        node->next = temp;
        node = temp;
    }
    return p;
}

// Pop.
node_data *pop(node_data *p)
{
    // Deleting the head node, after popping all
    //  and remaning only head node.
    if (p->next == NULL)
    {
        p = NULL;
        return p;
    }
    node_data *temp = p;
    node_data *temp1;

    // Deleting all the nodes else the head node.
    while (temp->next->next != NULL)
        temp = temp->next;

    temp1 = temp->next;
    temp->next = NULL;
    delete temp1;

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
    // node_data *node = NULL;

    head = push(head);
    head = push(head);
    head = push(head);
    head = push(head);
    head = push(head);
    head = push(head);

    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    //head = pop(head);
    display(head);

    return 0;
}