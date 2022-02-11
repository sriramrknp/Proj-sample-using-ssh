// Date: 03/01/2022

// Linked list, insertion and deletion
#include <iostream>
using namespace std;

class node_data
{
public:
    int data;
    node_data *next;
};

// Normal insertion
node_data *insertionListAtEnding(node_data *head, node_data *node)
{
    char c = 's';
    while (c != 'q')
    {
        if (head == NULL)
        {
            cout << "Node data: " << endl;
            cin >> node->data;
            node->next = NULL;
            head = node;
        }
        else
        {
            node_data *ptr = new node_data;
            cout << "Node data: " << endl;
            cin >> ptr->data;
            ptr->next = NULL;
            node->next = ptr;
            node = ptr;
        }
        cout << "'q' to quit" << endl;
        cin >> c;
    }
    return head;
}

// Insertion in LL at given position
void insertionAtPosition(node_data *head, int n)
{
    node_data *temp = head;
    node_data *ptr = new node_data;

    while(n-2>0)
    {
        temp = temp->next;
        n--;
    }
    cin >> ptr->data;
    ptr->next = temp->next;
    temp->next = ptr;
}

// Display of LL
void display(node_data *head)
{
    node_data *temp = NULL;
    temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
    
}

int main()
{
    int n;
    node_data *head = NULL;
    node_data *node = new node_data;

    head = insertionListAtEnding(head, node);
    display(head);

    cout << "The position: " << endl;
    cin >> n;
    insertionAtPosition(head, n);
    //deletioList(head, node);
    display(head);

    return 0;
}