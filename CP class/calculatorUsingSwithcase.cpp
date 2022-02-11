#include <iostream>
using namespace std;

int main()
{
    int a, b;
    string ope;

    cout << "Enter two numbers a and b: " << endl;
    cin >> a >> b;

    cout << "Enter the operation: " << endl;
    cout << "1. For Addition" << endl;
    cout << "2. For Substraction" << endl;
    cout << "3. For Multiplocation" << endl;
    cout << "4. For Division" << endl;
    cin >> ope;

    switch (ope)
    {
    case 1:
        /* code */
        cout << "Sum is: " << a + b << endl;
        break;
    case 2:
        cout << "Diff is: " << a - b << endl;
        break;

    case 3:
        cout << "Product is:" << a * b << endl;
        break;

    case 4:
        cout << "Division is " << a / b << endl;
        break;
    default:
        cout << "Wrong choice" << endl;
    }

    return 0;
}