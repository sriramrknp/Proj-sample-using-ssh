#include<iostream>
#include<math.h>
#define llt long long int 

llt hey(llt base, llt expo)
{
    llt result=1;
    while (expo > 0)
    {
        result = (result%1000000007) * base;
        expo--;
    }
    return result % 1000000007;
}

int main()
{
    llt n;
    std::cin >> n;

    llt ans = (llt)hey(2, n);
    std::cout << ans;
    return 0;
}