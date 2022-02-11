#include<iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    while(N != 1)
    {
        if(N%2 == 0 && N != 1)
        {
            cout << N << " ";
            N = N / 2;
        }
        else {
            cout << N << " ";
            N = 3 * N + 1;
        }
    }
    cout << "1";
    return 0;
}