#include <iostream>
#include <vector>
using namespace std;

int identifyPrime(int num)
{
    vector<int> div;
    int i;
    for (i = 1; (i * i) <= num; i++)
    {
        if (num % i == 0)
        {
            div.push_back(i);
            if (i * i == num)
                continue;
            div.push_back(i);
        }
    }

    if(div.size()==2){
        return 1;
    }
    return 0;
}

int main()
{
    int num;
    cin >> num;

    int arr[num];

    for (int i = 1; i <= num;i++)
    {
        arr[i] = identifyPrime(i);
        if(arr[i]==1)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}