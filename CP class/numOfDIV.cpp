#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int num;
    cin >> num;

    vector<int> div;

    for (int i = 1; (i*i)<=num; i++)
    {
        if(num%i==0){
            div.push_back(i);
            if(i*i==num)
                continue;
            div.push_back(i);
        }
    }

    cout << "Num of divisors are: " << div.size() << endl;

    return 0;
}