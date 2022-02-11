// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Optimum binary search tree using DP

#include <iostream>
#include <climits>

using namespace std;

int sum(int freq[], int i, int j);

int optCostFinding(int *freq, int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return freq[i];

    int fsum = sum(freq, i, j);

    // Initialize minimum value
    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int cost = optCostFinding(freq, i, r - 1) +
                   optCostFinding(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + fsum;
}

int optimalSearchTree(int *keys, int *freq, int n)
{
    return optCostFinding(freq, 0, n - 1);
}

int sum(int *freq, int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s = s + freq[k];
    return s;
}

// Driver Code
int main()
{
    int size;
    cout << "The key array size: " << endl;
    cin >> size;

    int keysOpt[size];
    for (int i = 0; i < size;i++)
    {
        cout << "Enter the key: " << endl;
        cin >> keysOpt[i];
    }
    int freqOpt[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the frequencies: " << endl;
        cin >> freqOpt[i];
    }

    cout << "Cost of Optimal BST is "
         << optimalSearchTree(keysOpt, freqOpt, size);
    cout << endl;
    return 0;
}
