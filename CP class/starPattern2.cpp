#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count=1;

    for (int i = N-1; i >=0 ; i--)
    {
        for (int j = i-1; j >= 0 ; j--)
        {
            cout << " ";
        }
        for (int k = 1;k<=count ;k++)
        {
            cout << "*";
        }
        count++;
        cout << endl;
    }
    return 0;
}