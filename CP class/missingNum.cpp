#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int N;
    cin >> N;
    long long int arr[N - 1];

    for (int i = 0; i < N - 1; i++)
        cin >> arr[i];

    sort(arr, arr + (N - 1));

    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        if ((i + 1) != arr[i])
        {
            cout << i + 1;
            count++;
            break;
        }
    }

    if (count == 0)
    {
        cout << N;
    }
    return 0;
}