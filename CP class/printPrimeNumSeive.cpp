#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long int N;
    cin >> N;
    
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= N;i++)
    {
        if(prime[i])
        {
            for (int j = i * i; j <= N;j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }

        return 0;
}