/*
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    long int N;
    cin >> N;

    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    map<int, int> a;

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int freq = 0,count=1;

    cout << "Integer factorisation: " << endl;
    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            while (N % i == 0)
            {
                //cout << i << " ";
                freq++;
                N = N / i;
            }
            a[i] = freq;
            cout << i << "-" << a[i] << endl;
            count *= a[i]+1;
            freq = 0;
        }
    }
    cout << "Num of div: " <<count<< endl;

    
    for(auto c: a){
        cout  << " " << a[c] << endl;
    }

    for (auto i : a)
        cout << a.first << "   " << a.second
             << endl;

    return 0;
}

*/
/*

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    long long int T;
    cin >> T;
    long long int sum = 0;
    while (T > 0)
    {
        long long int N;
        cin >> N;
        for (long int i = 1; (i * i) <= N; i++)
        {
            if(N % i == 0)
            {
                sum += i;
                if (i * i == N)
                    continue;
                sum += N / i;
            }
        }
        cout << sum-N << endl;
        sum = 0;
        T--;
    }
    return 0;
}
*/
#include <iostream>
#include<ctime>

int main()
{
    clock_t start, end;
    start = clock();

    // your code goes here
    long long int T;
    std::cin >> T;
    long long int sum = 0;
    while (T > 0)
    {
        long long int N1, N2, N;
        std::cin >> N1 >> N2;
        if (N1 > N2)
            N = N2;
        else
            N = N1;
        for (long int i = 1; (i * i) <= N; i++)
        {
            if (N1 % i == 0 && N2 % i == 0)
            {
                sum++;
            }
            if (i * i == N1 || i * i == N2)
               continue;
            if (N1 % (N / i) == 0 && N2 % (N / i) == 0)
                sum++;
        }

        std::cout << sum << '\n';
        sum = 0;
        T--;
    }

    end = clock();

    //Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << time_taken << '\n';
    return 0;
}