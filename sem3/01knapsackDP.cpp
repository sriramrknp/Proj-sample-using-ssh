#include <iostream>
using namespace std;
class KnapSack
{
public:
    int Wt[25], W;
    int P[25], N;
 
public:
    int knapsack(int Wt[], int P[], int N, int W)
    {
        if (N == 0 || W == 0)
        {
            return 0;
        }
        else if (Wt[N - 1] > W)
        {
            return knapsack(Wt, P, N - 1, W);
        }
        else
        {
            return max(P[N - 1] + knapsack(Wt, P, N - 1, W - Wt[N - 1]), knapsack(Wt, P, N - 1, W));
        }
    }
};
int main()
{
    int N, W, Wt[25], P[25];
    cout << "Enter the NO of Objects:";
    cin >> N;
    cout << "Enter the weights of objects:";
    for (int i = 0; i < N; i++)
    {
        cin >> Wt[i];
    }
    cout << "Enter the Profits of objects:";
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    cout << "Enter the Capacity of bag:";
    cin >> W;
    KnapSack A;
    cout << A.knapsack(Wt, P, N, W);
    return 0;
}