#include <bits/stdc++.h>
#include<iostream>
#include <ctime>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int nof(int n)
{
    int nof = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                nof++;
            else
                nof += 2;
        }
    }
    return nof;
}

int main()
{
    clock_t start, end;
    start = clock();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << nof(gcd(a, b)) << "\n";
    }
    end = clock();

    //Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << time_taken << '\n';
    return 0;
}