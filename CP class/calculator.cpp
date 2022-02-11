#include <iostream>
using namespace std;

int main()
{
    int a, b;
    string ope;

    cout << "Enter two numbers a and b: " << endl;
    cin >> a >> b;

    cout << "Enter the operation: " << endl;
    cin >> ope;

    if(ope == "add")
    {
        cout << "add is: " << a + b << endl;
    }
    else if(ope == "sub")
    {
        cout << "sub is: " << a - b << endl;
    }
    else if(ope == "div")
    {
        cout << "div is " << a / b << endl;
    }
    else if(ope == "mul")
    {
        cout << "mul is " << a * b << endl;
    }

    return 0;
}