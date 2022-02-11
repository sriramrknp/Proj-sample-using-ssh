// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI
 
// Coin change problem
 
#include <iostream>
using namespace std;

class minCoins
{
private:
    int i, j, k, temp1, temp2, count;

public:
    minCoins()
    {
        i = 0;
        j = 0;
        k = 1;
        temp1 = 0;
        temp2 = 0;
        count = 1; 
    }
    void findingMinCoins(int coin, int *denomArray, int numOfDenom)
    {
        // Sorting the denominations
        for (i = numOfDenom - 1; i >= 0; i--)
        {
            for (j = numOfDenom - 1; j >= k; j--)
            {
                //comparing two consecutive elements if left element is
                // greater than right element then swap
                if (denomArray[j] > denomArray[j - 1])
                {
                    swap(denomArray[j], denomArray[j - 1]);
                }
            }
            k++;
        }

        // Denominations after sorting
        cout << "\033[4;33mDenominations after sorting:" << endl;
        for (j = 0; j < numOfDenom; j++)
        {
            cout << " " << denomArray[j];
        }
        cout << "\033[0m" << endl;

        int changeCoins[numOfDenom];
        for (j = temp1; j < numOfDenom; j++)
        {
            changeCoins[j] = 0;
        }

        while (coin != 0 && temp2 <= numOfDenom-1)
        {
            changeCoins[temp2] = coin / denomArray[temp2];
            if ((coin - (denomArray[temp2] * changeCoins[temp2])) <= denomArray[temp2 + 1])
            {
                temp2++;
                count = 0;
            }
            else 
                count++;
            
            if(count == 0)
                coin = coin - (denomArray[temp2-1] * changeCoins[temp2-1]);
            else
                coin = coin - (denomArray[temp2] * changeCoins[temp2]);

            if (coin != 0)
            {
                temp1++;
                temp2++;
            }
        }

        cout << "\033[4;33mFinal change: ";
        for (j = 0; j < numOfDenom; j++)
        {
            cout << " " << changeCoins[j];
        }
        cout << "\033[0m" << endl;
    }
};

int main()
{
    int _coin;
    minCoins mc1;

    cout << "\033[1;31mEnter the coin to give change: \033[0m" << endl;
    cin >> _coin;

    int *_denominations = new int(1);
    char _temp = 'k';
    int i = 0;

    while (_temp != 'q')
    {
        cout << "\033[1;31mEnter the denominations: \033[0m" << endl;
        cin >> *(_denominations + i);

        cout << "\033[1;31mEnter 'q' to quit else any char to continue: \033[0m" << endl;
        cin >> _temp;
        if (_temp != 'q')
        {
            i++;
            int *_denominations = new int(1);
        }
    }
    int _numOfDenom = i + 1;
    int _denomArray[_numOfDenom];
    for (int j = 0; j < _numOfDenom; j++)
    {
        _denomArray[j] = *(_denominations + j);
    }

    mc1.findingMinCoins(_coin, _denomArray, _numOfDenom);

    return 0;
}