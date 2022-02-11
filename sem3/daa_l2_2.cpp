// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Two stacks problem
// Lab 2, 2nd problem

#include <iostream>
using namespace std;

class twostacks
{
    //data members
    int size;
    int *arr;
    int top1, top2;

public:
    twostacks(int n) //constructor
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    //member function1
    void push1(int value)
    {                         //function to add elements to stack1
        if (top2 - top1 == 1) //condition to check stack is full
        {
            cout << "stack is overflow";
            exit(1);
        }
        else
        {
            top1 = top1 + 1;
            arr[top1] = value;
        }
    }
    //member function2
    int pop1()
    { //function to remove element from stack 1
        int value;
        if (top1 == -1)
        {
            cout << "stack is empty";
            exit(1);
        }
        else
        {
            value = arr[top1];
            top1 = top1 - 1;
            return value;
        }
    }
    void push2(int value)
    { //function to add elements to stack2
        if (top2 - top1 == 1)
        {
            cout << "stack is overflow";
            exit(1);
        }
        else
        {
            top2 = top2 + 1;
            arr[top2] = value;
        }
    }
    int pop2()
    { //function to remove element from stack2
        int value;
        if (top2 == size)
        {
            cout << "stack is empty";
            exit(1);
        }
        else
        {
            value = arr[top2];
            top2 = top2 - 1;
            return value;
        }
    }
    void printstack1()
    {
        int i;
        for (i = top1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    int value, choice, n;
    cout << "Enter the size of array :\n";
    cin >> n;
    twostacks T1(n);
    while (1)
    {
        /*cout << "1. Push an element in to first stack\n2. Push an element in to second stack\n3. pop an element from first stack and display it\n4. pop an element from second stack and display it\n5. Exit\n";
*/
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the value that to be pushed:" << endl;
            cin >> value;
            T1.push1(value);
            break;
        case 2:
            cout << "enter the value that to be pushed:" << endl;
            cin >> value;
            T1.push2(value);
            break;
        case 3:
            cout << "****popped Number in first stack is : \n"
                 << T1.pop1() << endl;
            break;
        case 4:
            cout << "****popped Number in second stack is : \n"
                 << T1.pop2() << endl;
            break;
        default:
            exit(1);
        }
    }
    return 0;
}
