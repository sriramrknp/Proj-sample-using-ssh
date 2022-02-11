// CS20B1107, CHEERLA SRIRAM REDDY

// Greedy algorithm of 0-1 knapsack, if all weights are same

// The logic is:
//   Since all weights are same first we check the
//   first object's weight is less than the kanpsack weight
//   then we include the oject and add the profit of that object
//   to the subset next add next object weight and check if it is
//   less than the knapsack weight, if less we add that object
//   weight and add profit, once it becomes greater or = we come
//   out of loop.

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
        cout << "\033[4;33mBefore sorting the profit:\033[0m" << endl;
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
                if (arrP[j] > arrP[j - 1])
                {
                    swap(arrP[j], arrP[j - 1]);
                }
            }
            k++;
        }

        int flag = N;

        cout << endl;
        // Displays objects, after sorted
        cout << "\033[4;33mAfter sorting the profit:\033[0m" << endl;
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
        double arrSubSet[N];
        double darrSubSet[N];

        for (i = 0; i < N; i++)
        {
            darrSubSet[i] = 0;
            arrSubSet[i] = 0;
        }

        double flag3 = arrW[0];

        int flag2 = 0, temp = 0;
        int flag4 = 0;

        // If weight is less than kanpsack weight, we include that object
        // and add those profits simultaneously.
        while (flag3 <= knapW)
        {
            arrSubSet[flag2] = arrP[temp];
            darrSubSet[flag4] = flag2;
            flag3 = flag3 + arrW[0];
            if (flag3 <= knapW)
            {
                flag2++;
                flag4++;
                temp++;
            }
        }

        // Displaying final objects present in subset
        cout << "\033[4;33mSubset contaning objects:\033[0m" << endl;
        cout << "\033[4;33m                1-0  profit:\033[0m" << endl;

        i = 0;
        while (i < N && arrSubSet[i] != 0)
        {
            cout << "Object ---  " << i + 1;
            if (i == 0)
                cout << "   " << darrSubSet[i] + 1;
            if (i != 0)
                cout << "   " << darrSubSet[i];
            cout << "   " << arrSubSet[i];
            finalProfit = finalProfit + arrSubSet[i];
            i++;
            cout << endl;
        }

        cout << "\033[4;33mFinal profit is: \033[0m" << finalProfit << endl;
    }
};

int main()
{
    int n, weight;
    double _knapW;

    optimum op1;
    cout << endl;
    cout << "\033[1;31mEnter the number of objects: \033[0m" << endl;
    cin >> n;
    double _arrW[n];
    double _arrP[n];

    cout << "\033[1;31mEnter profits of " << n << " objects:\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> _arrP[i];
    }
    cout << "\033[1;31mEnter weight of objects:\033[0m" << endl;
    cin >> weight;
    for (int i = 0; i < n; i++)
    {
        _arrW[i] = weight;
    }
    cout << "\033[1;31mEnter the weight of Knapsack:\033[0m" << endl;
    cin >> _knapW;

    op1.findOptSol(n, _arrP, _arrW, _knapW);

    return 0;
}