#include<iostream>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n,a=0,b=0;
    std::cin >> n;

    for (long long int i = n; i >=2;i--){

        n = i;
        while (n % 2 == 0 || n % 5 == 0)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                a++;
            }
            else if (n % 5 == 0)
            {
                n = n / 5;
                b++;
            }
        }
    }

    if(a>b)
        std::cout << b;
    else
        std::cout << a;

    return 0;
}