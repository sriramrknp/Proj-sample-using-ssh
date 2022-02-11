// Date: 03/01/2022

#include <iostream>
using namespace std;

class node_data
{
public:
    int data;
    node_data *left;
    node_data *right;
};

// Normal insertion
node_data *insertionListAtEnding(node_data *head, node_data *node, int numNodes)
{
    while (numNodes--)
    {
        if (head == NULL)
        {
            cout << "Node data: " << '\n';
            cin >> node->data;
            node->left = NULL;
            head = node;
        }
        else
        {
            node_data *temp = new node_data;
            node->right = temp;
            temp->left = node;
            cout << "Node data: " << '\n';
            cin >> temp->data;
            temp->right = NULL;
            node = temp;
        }
    }
    return head;
}

// Display of DLL from head to tail
void display(node_data *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << '\n';
}

// Display from tail to start
void displayEnd(node_data *head)
{
    if (head == NULL)
        return;
    node_data *temp = head;
    while (head->right != NULL)
    {
        head = head->right;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->left;
    }

    cout << '\n';
}

// Deletion at given position in DLL
node_data *deletion(node_data *head, int pos)
{
    // Deletion of head node
    if (pos == 1)
    {
        head = head->right;
        head->left = NULL;
        return head;
    }

    node_data *temp = head;
    node_data *temp1 = head;
    while ((pos - 2) > 0)
    {
        temp = temp->right;
        temp1 = temp1->right;
        pos--;
    }

    temp1 = temp1->right;

    if (temp1->right != NULL)
    {
        // Other than head and tail

        temp->right = temp1->right;
        temp1->right->left = temp;
        delete temp1;
    }
    else
    {
        // Deletion at last

        temp->right = NULL;
        temp1->left = NULL;
        delete temp1;
    }
    return head;
}

// Insertion at given position in DLL
node_data *insertion(node_data *head, int pos)
{
    // Insertion at head
    if (pos == 1)
    {
        node_data *temp1 = new node_data;

        cout << "Enter the node to be inserted: " << '\n';
        cin >> temp1->data;

        head->left = temp1;
        temp1->left = NULL;
        temp1->right = head;
        head = temp1;
        return head;
    }
    node_data *temp = head;
    node_data *temp2 = head;
    node_data *temp1 = new node_data;

    cout << "Enter the node to be inserted: " << '\n';
    cin >> temp1->data;

    while ((pos - 2) > 0)
    {
        temp = temp->right;
        temp2 = temp2->right;
        pos--;
    }
    temp2 = temp2->right;

    // Insertion at other than head and tail
    if (temp->right != NULL)
    {
        temp1->right = temp2;
        temp2->left = temp1;
        temp->right = temp1;
        temp1->left = temp;
    }
    // Insertion at tail
    else
    {
        temp->right = temp1;
        temp1->left = temp;
        temp1->right = NULL;
    }
    return head;
}

int main()
{
    int numNodes, position, posiI;
    node_data *head = NULL;
    node_data *node = new node_data;

    cout << "Num of nodes: " << endl;
    cin >> numNodes;

    head = insertionListAtEnding(head, node, numNodes);
    display(head);

    cout << "Node position be deleted: " << endl;
    cin >> position;

    head = deletion(head, position);
    display(head);

    cout << "Node position be inserted: " << endl;
    cin >> posiI;

    head = insertion(head, posiI);
    display(head);
    displayEnd(head);

    return 0;
}