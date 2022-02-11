// Date: 03/01/2022

// Reversing of a LL

#include <iostream>
using namespace std;

class node_data
{
public:
    int data;
    node_data *next;
};

// Normal insertion
node_data* insertionListAtEnding(node_data *head, node_data *node, int NumNodes)
{
    while (NumNodes--)
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
    }
    return head;
}


void insertionAtPosition(node_data *head, int n)
{
    node_data *temp = head;
    node_data *ptr = new node_data;

    while (n - 2 > 0)
    {
        temp = temp->next;
        n--;
    }
    cout << "Node to be inserted: " << '\n';
    cin >> ptr->data;
    ptr->next = temp->next;
    temp->next = ptr;
}

void display(node_data *head)
{
    node_data *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display reverse list using recursion
void displayReverseList(node_data *p)
{
    if (p == NULL)
        return;

    displayReverseList(p->next);
    cout << p->data << '\n';
    cout << "end" << '\n';
}

node_data *q = NULL;
node_data *s = NULL;

// Reverse linked list using recursion
node_data* ReverseList(node_data *p)
{
    if (p->next == NULL)
    {
        s = p;
        return 0;
    }
    ReverseList(p->next);
    q = p->next;
    q->next = p;

    // Instead of both above two lines we can wite
    // p->next->next = p;
    p->next = NULL;

    return s;
}

int main()
{
    int n, numNodes;
    node_data *head = NULL;
    node_data *node = new node_data;

    cout << "Num of nodes: " << endl;
    cin >> numNodes;

    head = insertionListAtEnding(head, node, numNodes);
    display(head);

    cout << "The position: " << endl;
    cin >> n;
    insertionAtPosition(head, n);
    display(head);

    displayReverseList(head);
    cout << '\n';
    
    head = ReverseList(head);
    display(head);
    
    cout << '\n';

    return 0;
}