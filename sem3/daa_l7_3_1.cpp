// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI
 
// second largest element with n+logn-2 comparisions

#include <iostream>
#include<vector>
#include "function-template"
using namespace std;

int main()
{
    int n, choice;
    int cI;
    double cD;
    char cC;

    vector<int> arrI;
    vector<double> arrD;
    vector<char> arrC;

    cout << "Enter the array size" << endl;
    cin >> n;

    while(1)
    {
        cout << endl;
        cout << "Choose 1. to enter integers" << endl;
        cout << "Choose 2. to enter double" << endl;
        cout << "Choose 3. to enter characters" << endl;
        cout << "Choose 4. to exit " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter " << n << " integers: " << endl;
            for (int i = 0; i < n;i++)
            {
                cin >> cI;
                arrI.push_back(cI);
            }
            findSecondLargest<int>(n, arrI);
            break;
        case 2:
            cout << "Enter " << n << " double num: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> cD;
                arrD.push_back(cD);
            }
            findSecondLargest<double>(n, arrD);
            break;
        case 3:
            cout << "Enter " << n << " characters: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> cC;
                arrC.push_back(cC);
            }
            findSecondLargest<char>(n, arrC);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}