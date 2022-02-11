// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Greedy algorithm of Fractional knapsack
  
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
        // Dublicate arrays, to store the profit and weight
        double d_arrP[N];
        double d_arrW[N];
        for (i = 0; i < N; i++)
        {
            d_arrP[i] = arrP[i];
            d_arrW[i] = arrW[i];
        }

        // Array to store the profit / weight ratio
        double arrPW[N];
        k = 1;

        for (i = 0; i < N; i++)
        {
            arrPW[i] = arrP[i] / arrW[i];
        }

        // Displays objects, before sorted
        cout << "\033[4;33mBefore sorting the profit / weight:\033[0m" << endl;
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

        // Displays ratios
        cout << "\033[;32m Ratios:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrPW[i];
        }
        cout << "\033[0m" << endl;

        // Sorts the profit / weight ratio,
        // also the weight and profit arrays accordingly
        for (i = N - 1; i >= 0; i--)
        {
            for (j = N - 1; j >= k; j--)
            {
                //comparing two consecutive elements if left element is
                // greater than right element then swap
                if (arrPW[j] > arrPW[j - 1])
                {
                    swap(arrPW[j], arrPW[j - 1]);
                    swap(arrW[j], arrW[j - 1]);
                    swap(arrP[j], arrP[j - 1]);
                }
            }
            k++;
        }

        int flag = N;

        cout << endl;
        // Displays objects, after sorted
        cout << "\033[4;33mAfter sorting the profit / weight:\033[0m" << endl;
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

        // Displays ratios, sorted one
        cout << "\033[;32m Ratios:";
        for (i = 0; i < N; i++)
        {
            cout << " " << arrPW[i];
        }
        cout << "\033[0m" << endl;

        // Subset array, one is dublicate
        double arrSubSet[N];
        double darrSubSet[N];
        double flag3 = arrW[0];

        int flag2 = 0;

        // Checking weights is less than knapsack weight
        while (flag3 <= knapW)
        {
            flag2++;
            arrSubSet[flag2 - 1] = flag2;
            flag3 = flag3 + arrW[flag2];
        }

        // Subset setting remaning to zero
        for (i = flag2; i < N; i++)
        {
            arrSubSet[i] = 0;
        }
        double frac_x = 0.0;

        // Finding fraction of object
        frac_x = (knapW - (flag3 - arrW[flag2])) / arrW[flag2];

        arrSubSet[flag2] = frac_x;

        // Finding actual position of objects before sorted
        int temp2 = 0;
        int temp3 = 0, temp4 = 0;
        double indexarr[N];

        for (i = 0; i < N; i++)
        {
            indexarr[i] = 0;
        }

        while (arrSubSet[temp2] != 0.0)
        {
            temp4 = 0;
            while (arrW[temp3] != d_arrW[temp4])
            {
                temp4++;
            }
            temp3++;
            if (temp2 == flag2)
                indexarr[temp4] = frac_x;
            else
                indexarr[temp4] = 1;
            temp2++;
        }

        // Displaying final objects present in subset
        cout << "\033[4;33mSubset contaning objects:\033[0m" << endl;
        for (i = 0; i < N; i++)
        {
            cout << " " << indexarr[i];
        }
        cout << endl;

        int temp1 = 0;

        // Caluclating final profit of objects present in knapsack
        while (arrSubSet[temp1] != 0.0)
        {
            if (temp1 == flag2)
                finalProfit = finalProfit + arrP[temp1] * frac_x;
            else
                finalProfit = finalProfit + arrP[temp1];
            temp1++;
        }
        cout << "\033[4;33mFinal profit is: \033[0m" << finalProfit << endl;
    }
};

int main()
{
    int n;
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
    cout << "\033[1;31mEnter weights of " << n << " objects:\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> _arrW[i];
    }
    cout << "\033[1;31mEnter the weight of Knapsack:\033[0m" << endl;
    cin >> _knapW;

    op1.findOptSol(n, _arrP, _arrW, _knapW);

    return 0;
}