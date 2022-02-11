/* CS20B1107, CHEERLA SRIRAM REDDY */
/* Program to sort two merged linked lists into single list(sorted) */

#include <iostream>
#include <climits>
using namespace std;

// class

class node
{
public:
    int data;
    node *next;
};

class linkedlist
{
private:
    node *head1;
    node *head2;
    node *head;

public:
    //insert function declaration, inserts into linkedlist
    void insert(int num)
    {
        node *head1 = new node;
        node *head2 = new node;
        node *node1 = head1;
        node *node2 = head2;
        int i = 1;

        while (num == 1)
        {
            //if(i == 1)
             //node *head1 = new node;

            if (num == 1)
            {
                if (head1 == NULL)
                {
                    cout << "Enter elements in sorted order in list 1:" << endl;
                    cin >> node1->data;
                    node1->next = NULL;
                }
                else
                {
                    node *ptr1 = new node;
                    cout << "Enter elements in sorted order in list 1:" << endl;
                    cin >> ptr1->data;
                    ptr1->next = NULL;
                    node1->next = ptr1;
                    node1 = ptr1;
                }
            }
            cout << "Enter 1 to continue anyother to quit: " << endl;
            cin >> num;
        }

        while (num == 2)
        {
            if (num == 2)
            {
                if (head2 == NULL)
                {
                    cout << "Enter elements in sorted order in list 2:" << endl;
                    cin >> node2->data;
                    node2->next = NULL;
                }
                else
                {
                    node *ptr2 = new node;
                    cout << "Enter elements in sorted order in list 2:" << endl;
                    cin >> ptr2->data;
                    ptr2->next = NULL;
                    node2->next = ptr2;
                    node2 = ptr2;
                }
            }
            cout << "Enter 2 to continue anyother to quit: " << endl;
            cin >> num;
        }
    }


    void display(int num)
    {
        cout << endl;
        
        if (num == 1)
        {
            node *node1 = head1;
            node *temp1 = node1;
            cout << "************List-1***********: " << endl;
            while (node1 != NULL)
            {
                cout << " hey   " << node1->data;
                node1 = node1->next;
            }
            node1 = temp1;
            cout << endl;
            cout << endl;
        }
        if (num == 2)
        {
            node *node2 = head2;
             node *temp2 = node2;
            cout << "************List-2***********: " << endl;
            while (node2 != NULL)
            {
                cout << "    " << node2->data;
                node2 = node2->next;
            }
            node2 = temp2;
            cout << endl;
            cout << endl;
        }
        if (num == 3)
        {
             node *node3 = head;
             node *temp = node3;
            cout << "************Merged List***********: " << endl;
            while (node3 != NULL)
            {
                cout << "    " << node3->data;
                node3 = node3->next;
            }
            node3 = temp;
            cout << endl;
            cout << endl;
        }
    }

    //merge function declaration, which merges two entered linkedlists
    void merge(node *node1, node *node2, node *node3)
    {
        int countm1 = 1;
        //linkedlist *node1 = head1;
        //linkedlist *node2 = head2;
        //linkedlist *node = head;

        while (node1 != NULL || node2 != NULL)
        {
            if (node1 != NULL && node2 != NULL)
            {
                if (node1->data < node2->data)
                {
                    if (countm1 == 1)
                    {
                        node3->data = node1->data;
                        node3->next = NULL;
                        countm1++;
                        node1 = node1->next;
                        cout << "node data 1 " << node3->data << endl;
                    }
                    else
                    {
                        node *ptr1 = new node;
                        ptr1->data = node1->data;
                        ptr1->next = NULL;
                        node3->next = ptr1;
                        node3 = ptr1;
                        node1 = node1->next;
                        cout << "node data 1 " << node3->data << endl;
                    }
                }
            }
            else if (node2 != NULL)
            {
                if (countm1 == 1)
                {
                    node3->data = node2->data;
                    node3->next = NULL;
                    countm1++;
                    node2 = node2->next;
                    cout << "node data" << node3->data << endl;
                }
                else
                {
                    node *ptr3 = new node;
                    ptr3->data = node2->data;
                    ptr3->next = NULL;
                    node3->next = ptr3;
                    node3 = ptr3;
                    node2 = node2->next;
                    cout << "node data" << node3->data << endl;
                }
            }

            if (node1 != NULL && node2 != NULL)
            {
                if (node1->data > node2->data)
                {
                    if (countm1 == 1)
                    {
                        node3->data = node2->data;
                        node3->next = NULL;
                        node2 = node2->next;
                        countm1++;
                        cout << "node data 2 " << node3->data << endl;
                    }
                    else
                    {
                        node *ptr2 = new node;
                        ptr2->data = node2->data;
                        ptr2->next = NULL;
                        node3->next = ptr2;
                        node3 = ptr2;
                        node2 = node2->next;
                        cout << "node data 2 " << node3->data << endl;
                    }
                }
            }
            else if (node1 != NULL)
            {
                if (countm1 == 1)
                {
                    node3->data = node1->data;
                    node3->next = NULL;
                    countm1++;
                    node1 = node1->next;
                    cout << "node data" << node3->data << endl;
                }
                else
                {
                    node *ptr4 = new node;
                    ptr4->data = node1->data;
                    ptr4->next = NULL;
                    node3->next = ptr4;
                    node3 = ptr4;
                    node1 = node1->next;
                    cout << "node data" << node3->data << endl;
                }
            }
        }
    }
};

//Main program
int main()
{
    int choice = 1;
    int num1 = 1;
    int num = 1;
    linkedlist list1;
    linkedlist list2;
    linkedlist list3;

    while (choice > 0)
    {
        cout << "Enter the choice: " << endl;
        cout << "  1. Insert, 2. Display, 3. Merge, 4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            
            while (num == 1 || num == 2)
            {
                cout << "Enter 1 to insert in 1, 2 to insert in 2 or any other to quit: " << endl;
                cin >> num;
                if (num == 1)
                    list1.insert(num);
                if (num == 2)
                    list2.insert(num);
                if (num != 1 || num != 2)
                    break;
            }
            break;
        case 2:
            
            while (num1 == 1 || num1== 2)
            {
                cout << "Enter 1 to display in  list1, 2 to display in list2 or any other to quit: " << endl;
                cin >> num1;
                if (num1 == 1)
                    list1.display(num1);
                if (num1 == 2)
                    list2.display(num1);
                if (num1 != 1 || num1 != 2)
                    break;
            }
            break;
        case 3:
            cout << "  hello   " << endl;
            //l3.merge(head1, head2, head);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}