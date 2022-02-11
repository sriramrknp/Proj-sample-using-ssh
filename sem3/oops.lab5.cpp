#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linkedList
{
private:
    Node *Head;
    bool isEmpty()
    {
        if (Head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    linkedList()
    {
        Head = NULL;
    }
    Node *Headpoint()
    {
        return Head;
    }
    void insert(int number)
    {
        Node *position = new Node();
        if (isEmpty())
        {
            position = NULL;
        }
        else
        {
            if (number < Head->data)
            {
                position = NULL;
            }
            else
            {
                Node *temp1 = Head;
                Node *temp2 = Head->next;
                while (temp2 != NULL)
                {
                    if (number < temp2->data)
                    {
                        position = temp1;
                        break;
                    }
                    temp1 = temp2;
                    temp2 = temp2->next;
                }
                position = temp1;
            }
        }
        Node *ptr = new Node();
        ptr->data = number;
        ptr->next = NULL;
        if (position == NULL)
        {
            ptr->next = Head;
            Head = ptr;
        }
        else if (position->next == NULL)
        {
            position->next = ptr;
        }
        else
        {
            ptr->next = position->next;
            position->next = ptr;
        }
    }
    void deletingData(int pos)
    {
        if (isEmpty())
        {
            cout << "The linkedList is Empty " << endl;
            return;
        }
        Node *position_prev = Head;
        Node *Position = Head->next;
        if (pos == 1)
        {
            Head = Head->next;
            delete position_prev;
        }
        else
        {
            for (int i = 2; Position != NULL; i++)
            {
                if (i == pos)
                {
                    position_prev->next = Position->next;
                    delete Position;
                    break;
                }
                else
                {
                    position_prev = position_prev->next;
                    Position = Position->next;
                }
            }
            if (Position == NULL)
            {
                cout << " !! No Data is present in the Positionation " << endl;
            }
        }
    }
    void display()
    {
        Node *ptr = Head;
        if (isEmpty())
        {
            cout << "Linked list is Empty" << endl;
            return;
        }
        cout << "Data in the list :" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    linkedList operator+(linkedList list)
    {
        linkedList L;
        Node *ptr = L.Headpoint();
        while (ptr != NULL)
        {
            L.insert(ptr->data);
            ptr = ptr->next;
        }
        ptr = list.Headpoint();
        while (ptr != NULL)
        {
            L.insert(ptr->data);
            ptr = ptr->next;
        }
        return L;
    }
};

int main()
{
    linkedList L1, L2, L3;
    int choice;
    while (1)
    {
        cout << "\nSelect your choice: " << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Display" << endl;
        cout << "4.Merge " << endl;
        cout << "5.Exit " << endl;
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int item, choice;
            cout << "Enter element to be inserted: ";
            cin >> item;
            cout << "Enter 1 to insert in list 1 and 2 to insert in list 2: ";
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << " !! INVALID CHOICE, Please try again !!" << endl;
                cout << "Enter 1 to insert in list 1 and 2 to insert in list 2: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                L1.insert(item);
            }
            else
            {
                L2.insert(item);
            }
            break;
        case 2:
            cout << "Enter 1 to delete in list 1 and 2 to delete in list 2: ";
            cin >> choice;
            cout << "Enter the position of the element: ";
            cin >> item;
            while (choice != 1 && choice != 2)
            {
                cout << " !! INVALID CHOICE, Please try again !!" << endl;
                cout << "Enter 1 to delete in list 1 and 2 to delete in list 2: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                L1.deletingData(item);
            }
            else if (choice == 2)
            {
                L2.deletingData(item);
            }
            break;
        case 3:
            cout << "Enter 1 to display list 1 and 2 to display: ";
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << "  INVALID CHOICE,  try again " << endl;
                cout << "Enter 1 to display list 1 and 2 to display L2: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                L1.display();
            }
            else if (choice == 2)
            {
                L2.display();
            }
            break;
        case 4:
            L3 = L1 + L2;
            cout << "Linked lists are merged " << endl;
            cout << " Merged list : " << endl;
            L3.display();
            break;
        default:
            cout << " !! INVALID CHOICE, Please try again !!" << endl;
        }
    }
}