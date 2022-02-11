// CS20B1107, CHEERLA SRIRAM REDDY

// Greedy algorithm of 0-1 knapsack, if all weights are same


#include <iostream>
using namespace std;
class KnapSack
{
public:
    int arrW[1000], knapW;
    int arrP[1000], N;

public:
    double findOptSol(double *arrP, double *arrW, int N, double knapW)
    {
        if (N == 0 || knapW == 0)
        {
            return 0;
        }
        else if (arrW[N - 1] > knapW)
        {
            return findOptSol(arrW, arrP, N - 1, knapW);
        }
        else
        {
            return max(arrP[N - 1] + findOptSol(arrW, arrP, N - 1, knapW - arrW[N - 1]), findOptSol(arrW, arrP, N - 1, knapW));
        }
    }
};

int main()
{
    int n;
    double _knapW;

    KnapSack op1;
    cout << endl;
    cout << "\033[1;31mEnter the number of objects: \033[0m" << endl;
    cin >> n;
    double _arrW[n];
    double _arrP[n];

    cout << "\033[1;31mEnter profit of objects:\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> _arrP[i];
    }
    cout << "\033[1;31mEnter weight of " << n << " objects:\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> _arrW[i];
    }
    cout << "\033[1;31mEnter the weight of Knapsack:\033[0m" << endl;
    cin >> _knapW;

    op1.findOptSol(_arrP, _arrW, n, _knapW);

    return 0;
}