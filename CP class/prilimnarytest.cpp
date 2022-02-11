#include <iostream>
#include <ctime>

using namespace std;

int primeTest(long long int _num)
{
    for (long long int i = 2; (i * i) <= _num; i++)
    {
        if (_num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t start, end;
    start = clock();

    long long int t;
    cin >> t;
    long long int size[t];
    long long int i = 0;
    long long int j = t;

    //for (int i = 0; i < t;i++)
    //  size[i] = 0;

    while (t > 0)
    {
        long long int num;
        cin >> num;

        size[i] = primeTest(num);
        i++;
        t--;
    }

    for (int i = 0; i < j; i++)
    {
        if (size[i] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    // Recording the end clock tick.
    end = clock();

    //Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << time_taken << endl;
    return 0;
}
