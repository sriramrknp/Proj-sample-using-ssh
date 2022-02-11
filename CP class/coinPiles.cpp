#include <iostream>
#include <math.h>
#define llt long long int

void hey(llt a, llt b)
{
    llt base = a + b;

    if (a == 0 && b == 0)
    {
        std::cout << "YES" << '\n';
    
    }

    else if (base % 3 == 0 && base / 3 <= std::min(a, b))
        std::cout << "YES" << '\n';
    else
        std::cout << "NO" << '\n';
}

int main()
{
    llt n;
    std::cin >> n;

    while (n--)
    {
        llt a, b;
        std::cin >> a >> b;
        hey(a, b);
    }
    return 0;
}