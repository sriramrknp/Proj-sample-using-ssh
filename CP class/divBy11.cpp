#include<iostream>
using namespace std;

int main()
{
    string num;
    cin >> num;

    int evenSum = 0, oddSum = 0;

    for (long int i = 1; i < num.length();i=i+2){
        evenSum += num[i] - '0';
    }

    for (long int i = 0; i < num.length(); i = i + 2)
    {
        oddSum += num[i] - '0';
    }

    if (evenSum == oddSum)
    {
        /* code */
        cout << "yes";
    }
    else
        cout << "no";

        return 0;
}