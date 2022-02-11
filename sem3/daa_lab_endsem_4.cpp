// CS20B1107, CHEERLA SRIRAM REDDY

// List of all feasible solutions, in 0-1 knapsack

// The logic is:
//   finding the sub arrays, which sum is less tha or equal to the
//   knapsack weight 

// Time complexity analysis is,
//     big O(n^3), since three for loops


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

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N - i - 1; j++)
            {
                //comparing two consecutive elements if left element is
                // greater than right element then swap
                if (arrW[j] > arrW[j + 1])
                {
                    swap(arrW[j], arrW[j + 1]);
                }
            }
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
        double arrW_less[N][N];
        double arrSubSetW[N];

        for (i = 0; i < N; i++)
        {
            arrSubSetW[i] = -1;
            for (int j = 0; j < N; j++)
                arrW_less[i][j] = -1;
        }

        int sum = 0, count = 0;

        cout << "The feasible solutions are: " << endl;
        for (i = 0; i < N; i++)
        {
            for (j = i; j < N; j++)
            {
                sum = sum + arrW[j];
                if (sum <= knapW)
                {
                    if (i != j)
                    {
                        cout << "weights: ";
                        for (k = i; k <= j; k++)
                        {
                            cout << arrW[k];
                            if (k != j)
                            {
                                cout << ",";
                            }
                        }
                        cout << "";
                        count++;
                        cout << endl;
                    }
                }
            }
            sum = 0;
        }

        cout << "\033[4;33mThe number of feasible solutions are: \033[0m" << count << endl;
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

    op1.findOptSol(n, _arrP, _arrW, _knapW);

    return 0;
}