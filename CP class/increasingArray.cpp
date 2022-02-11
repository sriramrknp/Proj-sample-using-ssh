#include <iostream>

#define li long int

int main()
{
    li n;
    std::cin >> n;

    li arr[n];
    long long int count = 0;
    for (li i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        if(i!=0)
        {
            if(arr[i]< arr[i-1])
            {
                count += arr[i-1] - arr[i];
                arr[i] = arr[i - 1];
            }
        }
    }
    std::cout << count;

    return 0;
}