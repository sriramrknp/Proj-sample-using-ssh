#include<iostream>
using namespace std;

int main()
{
    int n,i=0;
    cin >> n;

    if(n==1)
    cout << 1 << " ";
    else if (n == 2)
        cout << 1 << " "<<1<<" ";

    while(n && n>2)
    {
            cout << i << " ";
            i = i - 1 + i - 2;
    }
    return 0;
}