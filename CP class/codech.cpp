#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int N;
    cin >> N;
    int s[N], t[N];
    for (int i = 0; i < N; i++)
    {
        cin >> s[i] >> t[i];
        if (i >= 1)
        {
            s[i] += s[i - 1];
            t[i] += t[i - 1];
        }
    }
    int max = -1;
    int index = -1;

    for (int i = 0; i < N; i++)
    {
        cout << s[i] << " " << t[i] << endl;
    }

    for (int i = 0; i < N; i++)
    {
        if (s[i] > t[i])
        {
            t[i] = s[i] - t[i];
            s[i] = 1;
            //cout << t[i] << endl;
        }
        else
        {
            t[i] = t[i] - s[i];
            s[i] = 2;
            //cout << t[i] << endl;
        }
        if (t[i] > max)
        {
            max = t[i];
            index = s[i];
        }

    }
    cout << index << " " << max << endl;
    return 0;
}
