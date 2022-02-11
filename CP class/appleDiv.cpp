#include<iostream>

int main()
{
    int n;
    std::cin >> n;

    long int arr[n];
    for (int i = 0; i < n;i++)
        std::cin >> arr[i];

    std::sort(arr, arr + n);

    long int a = 0, b = 0;

    a = arr[n - 1];
    

    return 0;
}