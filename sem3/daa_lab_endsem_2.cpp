// CS20B1107, CHEERLA SRIRAM REDDY

// Greedy algorithm of 0-1 knapsack, if all profits are same

// The logic is:
//   Since all profits are same, we go for only object's weight
//   if 1st obj weight is less than knapsack weight(after sorting
//   then we inlude weight  and simultaneously check added object's
//   weight is less than the knapsack weight, we go this way
//   when the subset weight is more than the knapsack weight we exit

// Time complexity analysis -
//  best case- big O of(n)
//  worst case is little o(n^2).

#include <iostream>
using namespace std;

class optimum
{
private:
    int i, j, k, temp;
    double finalProfit;

public:
    optimum()
    {
        i = 0;
        j = 0;
        finalProfit = 0.0;
    }
    void findOptSol(int N, double *arrP, double *arrW, double knapW)
    {
        k = 1;

        // Displays objects, before sorted
        cout << "\033[4;33mBefore sorting the weight:\033[0m" << endl;
        cout << "\033[;32m object:";
        for (i = 0; i < N; i++)
        {
            cout << " " << i + 1;
        }
        cout << "\033[0m" << endl;

        // Displays profit
        cout << "\033[;32m Profit:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrP[i];
        }
        cout << endl;

        // Displays weight
        cout << "\033[;32m Weight:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrW[i];
        }
        cout << endl;

        cout << "\033[0m" << endl;

        // Since all weights are same, we sort the profits
        // and include that object and check weight is less than knapsack weight
        for (i = N - 1; i >= 0; i--)
        {
            for (j = N - 1; j >= k; j--)
            {
                //comparing two consecutive elements if left element is
                // greater than right element then swap
                if (arrW[j] > arrW[j - 1])
                {
                    swap(arrW[j], arrW[j - 1]);
                }
            }
            k++;
        }

        int flag = N;

        cout << endl;
        // Displays objects, after sorted
        cout << "\033[4;33mAfter sorting the weight:\033[0m" << endl;
        cout << "\033[;32m object:";
        for (i = 0; i < N; i++)
        {
            cout << " " << i + 1;
        }
        cout << "\033[0m" << endl;

        // Displays profit, sorted one
        cout << "\033[;32m Profit:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrP[i];
        }
        cout << endl;

        // Displays weight, sorted one
        cout << "\033[;32m Weight:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrW[i];
        }
        cout << endl;

        cout << "\033[0m" << endl;

        // Subset array, one is dublicate
        double arrSubSetW[N];

        for (i = 0; i < N; i++)
        {
            arrSubSetW[i] = 0;
        }

        double flag3 = 0;
        int i = 0;

        // we check 1st objects weight if less than knapsack weight
        // we include that object, else we go to next and ckeck same
        // after including certain object, we add that weight
        // and ckeck for next and overvall weight is also less than the
        // knapsack weight

        for (int k = 0; k < N; k++)
        {
            if (arrW[k] < knapW && flag3 < knapW)
            {
                arrSubSetW[i] = k;
                i++;
                flag3 = flag3 + arrW[k];
                flag3 = flag3 + arrW[k + 1];
            }
        }

        // Displaying final objects present in subset
        cout << "\033[4;33mSubset contaning objects:\033[0m" << endl;
        cout << "\033[4;33m  1-0  profit  weight:\033[0m" << endl;

        i = 0;
        while (arrSubSetW[i] != 0 || i == 0)
        {
            k = arrSubSetW[i];
            finalProfit = finalProfit + arrP[k];
            cout << "    " << 1 << "    " << arrP[k] << "     " << arrW[k];
            cout << endl;
            i++;
        }
        cout << endl;

        cout << "\033[4;33mFinal profit is: \033[0m" << finalProfit << endl;
    }
};

int main()
{
    int n, profit;
    double _knapW;

    optimum op1;
    cout << endl;
    cout << "\033[1;31mEnter the number of objects: \033[0m" << endl;
    cin >> n;
    double _arrW[n];
    double _arrP[n];

    cout << "\033[1;31mEnter profit of objects:\033[0m" << endl;
    cin >> profit;
    for (int i = 0; i < n; i++)
    {
        _arrP[i] = profit;
    }
    cout << "\033[1;31mEnter weight of " << n << " objects:\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> _arrW[i];
    }
    cout << "\033[1;31mEnter the weight of Knapsack:\033[0m" << endl;
    cin >> _knapW;

    op1.findOptSol(n, _arrP, _arrW, _knapW);

    return 0;
}