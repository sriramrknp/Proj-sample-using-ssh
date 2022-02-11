#include <iostream>
#include <vector>
#include<map>
using namespace std;

int main()
{
    long long int N,s=0,b=0;
    cin >> N;

    for (long long int i = N; i >= 2; i--)
    {
        N = i;
        vector<bool> prime(N + 1, true);
        prime[0] = prime[1] = false;
        map<int, int> a;

        for (long long int i = 2; i <= N; i++)
        {
            if (prime[i])
            {
                for (long long int j = i * i; j <= N; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        int freq = 0;
        for (long long int i = 2; i <= N; i=i+3)
        {
            if (prime[i])
            {
                while (N % i == 0)
                {
                    if(i==2)
                        s++;
                    else if(i==5)
                        b++;
                    N = N / i;
                }
            }
        }
    }

    if (s > b)
        std::cout << b;
    else
        std::cout << s;

    return 0;
    }