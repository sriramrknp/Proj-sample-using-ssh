#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string figure;
    double side, radius, length, breadth;

    cout << "Enter figure name: " << endl;
    cin >> figure;

    if (figure == "circle")
    {
        cout << "radius: " << endl;
        cin >> radius;

        cout << "circle area is: " << 3.1472 * radius << setprecision(4) << endl;
    }
    else if (figure == "square")
    {
        cout << "Side of square: " << endl;
        cin >> side;
        cout << "square area is: " << side * side << setprecision(4) << endl;
    }
    else if (figure == "rectangle")
    {
        cout << "length and breadth: " << endl;
        cin >> length >> breadth;

        cout << "rectangle area is: " << length * breadth << setprecision(4) << endl;
    }
    else
        cout << "wrong choice" << endl;

    return 0;
}