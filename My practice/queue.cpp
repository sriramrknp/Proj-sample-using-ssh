// 19/01/2022

#include<iostream>
using namespace std;

class node_data
{
public:
    int data;
    node_data *next;
}; 

// Read end
node_data *rear = NULL;
node_data *node = NULL;

// Enqueue
node_data* Enqueue(node_data* p)
{
    if(p==NULL)
    {
        node_data *temp = new node_data();
        cout << "Enqueue data: " << '\n';
        cin >> temp->data;
        temp->next = NULL;
        p = temp;
        node = temp;
        rear = node;
    }
    else{
        node_data *temp = new node_data();
        cout << "Enqueue data: " << '\n';
        cin >> temp->data;
        temp->next = NULL;
        node->next = temp;
        rear = node;
        node = temp;
    }
    return p;
}

// Dequeue
node_data* Dequeue(node_data* p)
{
    if(p!=NULL)
    {
        //node_data *temp = p;
        p = p->next;
        return p;
        //delete temp;
    }
    return p;
}

//  Top
void top(node_data *p)
{
    if (p == NULL)
        cout << "Queue is empty" << '\n';
    else
        cout << "The front element is: " << p->data << '\n';
}

//  Empty
void empty(node_data* p)
{
    if(p==NULL)
        cout << "Queue is empty" << '\n';
    else
        cout << "Queue is not empty" << '\n';
}

// Display
void display(node_data* p)
{
    if(p!=NULL)
    {
        node_data *temp = p;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
}

// Size
void size(node_data *p)
{
    if (p != NULL)
    {
        node_data *temp = p;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout <<"Size of the queue is: "<<count<<'\n';
    }
    else
        cout << "Queue is empty" << '\n';
}

int main()
{
    node_data *head = NULL;

    int choice;
    while (1)
    {
        cout << "Choose the option:" << '\n';
        cout << "  1. Enqueue" << '\n';
        cout << "  2. Dequeue" << '\n';
        cout << "  3. Top" << '\n';
        cout << "  4. Empty" << '\n';
        cout << "  5. Size" << '\n';
        cout << "  6. Display" << '\n';
        cout << "  7. Exit" << '\n';
        cin >> choice;

        switch (choice)
        {
        case 1:
            head = Enqueue(head);
            break;
        case 2:
            head = Dequeue(head);
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