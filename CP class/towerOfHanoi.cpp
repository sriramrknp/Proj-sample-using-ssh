#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    signed int n;
    cin >> n;

    signed int res = (signed int)pow(2, n) - 1;
    cout << res;
    return 0;
}