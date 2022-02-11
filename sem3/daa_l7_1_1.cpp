// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Coin change problem using Dynamic programming
 
#include <iostream>
#include <algorithm>
using namespace std;
//#define SIZE _coin

class minCoins
{
private:
    int i, j, coin, NumOfDenom;

public:
    minCoins(int Coin, int Numofdenom)
    {
        i = 0;
        j = 0;
        coin = Coin;
        NumOfDenom = Numofdenom;
    }

    void findingMinCoins(int coin, int denomArray[], int numOfDenom)
    {
        int changeStrg[numOfDenom][coin + 1];
        for (int i = 0; i < numOfDenom; i++)
        {
            for (int j = 0; j < coin + 1; j++)
            {
                changeStrg[i][j] = 0;
            }
        }
        for (i = 0; i < numOfDenom; i++)
        {
            for (int j = i; j < numOfDenom; j++)
            {
                changeStrg[j][denomArray[i]] = 1;
            }
        }

        for (int i = 0; i < numOfDenom; i++)
        {
            for (int j = 1; j < coin + 1; j++)
            {
                if (j >= denomArray[i])
                {

                    if (denomArray[i] == 1)
                        changeStrg[i][j] = j / denomArray[i];
                    if ((j / denomArray[i]) >= 0 && denomArray[i] != 1 && denomArray[i] != 0)
                        changeStrg[i][j] = 1;

                    if ((j - denomArray[i]) != 0 && denomArray[i] != 1)
                    {
                        changeStrg[i][j] = changeStrg[i][j] + changeStrg[i][j - denomArray[i]];
                        if (changeStrg[i][j] > changeStrg[i - 1][j])
                            changeStrg[i][j] = changeStrg[i - 1][j];
                    }
                }
                else
                {
                    changeStrg[i][j] = changeStrg[i - 1][j];
                }
            }
        }

        cout << "\033[4;33mThe matrix where all the operations happened: ";
        cout << "\033[0m" << endl;
        for (int i = 0; i < numOfDenom; i++)
        {
            cout << "Denomination: " << denomArray[i] << " -- ";
            for (int j = 0; j < coin + 1; j++)
            {
                cout << " " << changeStrg[i][j];
            }
            cout << endl;
        }

        cout << "\033[4;33mThe minimum number of coins requred is: " << changeStrg[numOfDenom - 1][coin];
        cout << "\033[0m" << endl;
    }
};

int main()
{
    int _coin;

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
    minCoins mc1(_coin, _numOfDenom);

    int _denomArray[_numOfDenom];
    for (int j = 0; j < _numOfDenom; j++)
    {
        _denomArray[j] = *(_denominations + j);
    }
    sort(_denomArray, _denomArray + _numOfDenom);

    mc1.findingMinCoins(_coin, _denomArray, _numOfDenom);

    return 0;
}