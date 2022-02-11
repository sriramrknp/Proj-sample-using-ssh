#include <iostream>
#include <string>
#include <vector>
#define llt long long int

int main()
{
    std::string n;
    std::cin >> n;

    std::vector<int> a(27, 0);
    for (int i = 0; i < n.size(); i++)
    {
        a[n[i] - '@']++;
    }

    int count = 0, index = -1;
    for (int i = 1; i < n.size(); i++)
    {
        if (a[i] % 2 != 0 && a[i] != 0)
        {
            count++;
            index = i;
        }
    }

    std::string k = "";
    if (count > 1)
        std::cout << "NO SOLUTION" << '\n';
    else
    {
        for (int i = 1; i <= 27; i++)
        {
            if (a[i] != 0)
            {
                char s = (char)('@' + i);
                k = k + std::string((a[i] / 2), s);
            }
        }
        if (count > 0)
            k = k + (char)('@' + index);
        for (int i = (n.size() / 2); i >= 0; i--)
        {
            if (count == 0)
                k = k + k[i - 1];
            else
                k = k + k[i - 1];
        }
    }
    std::cout << k << '\n';

    return 0;
}