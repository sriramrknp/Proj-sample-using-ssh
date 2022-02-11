#include <iostream>

#define li long int

int main()
{
    li n;
    std::cin >> n;

    if (n >= 4 || n == 1)
    {
        for (li i = 2; i <= n; i += 2)
        {
            std::cout << i << " ";
        }
        for (li i = 1; i <= n; i+=2)
        {
            std::cout << i << " ";
        }
    }
    else
        std::cout << "NO SOLUTION";

    return 0;
}