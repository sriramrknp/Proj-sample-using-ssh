#include<iostream>
#include <vector>
#include <string>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int diff = 0;
    int temp = 0;
    int n = prices.size();

    if (n >= 2)
    {
        temp = prices[n - 1] - prices[n - 2];
        for (int i = n - 1; i >= 0; i--)
        {
            if ((prices[i] > prices[i - 1]) && i >= 1)
            {
                for (int j = i - 1; j >= 0; j--)
                {

                    diff = prices[i] - prices[j];
                    if (diff > temp)
                    {
                        temp = diff;
                    }
                }
            }
            //}
        }
    }
    else
    {
        if (n == 1)
            return 0;
    }
    if (temp < 0)
        return 0;
    return temp;
}

int main()
{
    vector<int> a = {1, 2, 3, 0, 0, 0};
    int b=maxProfit(a);

        cout << b<< " ";
}