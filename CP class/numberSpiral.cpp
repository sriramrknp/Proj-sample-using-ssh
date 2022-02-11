#include <iostream>
using namespace std;

int main()
{
    long int t;
    cin >> t;
    long int arr[t];
    long long int i = 0;

    while(t>0)
    {
        long long int x, y;
        cin >> x >> y;

        if(x>y)
        {
            i = 1 + (x - 1) * (x - 1) + (x - 1);
        }
        else{
            i = 1 + (y - 1) * (y - 1) + (y - 1);
        }

        if(x<y && y%2==0)
            cout << i - (y - x) << "\n";
        else if(x>y && x%2==0)
            cout << i + (x - y) << "\n";

        if (x > y && x % 2 != 0)
            cout << i - (x - y) << "\n";
        else if (x<y && y % 2 != 0)
            cout << i + (y - x) << "\n";

        if(x==y)
            cout << i << '\n';
        t--;
    }

    return 0;
}