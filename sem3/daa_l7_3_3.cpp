// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Coin change problem

#include <iostream>
using namespace std;

void knapsackInt(int, int *, int *, int);
void knapsackDouble(double, double *, double *, int);
void knapsackOnlyweight(int, int *, int);
void knapsackFractional(int, int *, int *, bool, int);

int main()
{
    int n;
    cout << "Number of objects: " << endl;
    cin >> n;

    int choice;
    int weightI[n], wI, profitI[n];
    int nI = n;
    double weightD[n], wD, profitD[n];
    int nD = n;
    int weightOI[n], wOI;
    int nOI = n;
    int weightFI[n], wFI, profitFI[n];
    int nFI = n;

    while (1)
    {
        cout << endl;
        cout << "Choose 1. to knapsack of int" << endl;
        cout << "Choose 2. to knapsack of double" << endl;
        cout << "Choose 3. to knapsack with weight" << endl;
        cout << "Choose 4. to fractional knapsack" << endl;
        cout << "Choose 5. to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the weights: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> weightI[i];
            }
            cout << "Enter the profits: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> profitI[i];
            }
            cout << "Max weight of knapsack: " << endl;
            cin >> wI;

            knapsackInt(wI, weightI, profitI, nI);
            break;


        case 2:
            cout << "Enter the weights: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> weightD[i];
            }
            cout << "Enter the profits: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> profitD[i];
            }
            cout << "Max weight of knapsack: " << endl;
            cin >> wD;

            knapsackDouble(wD, weightD, profitD, nD);
            break;


        case 3:
            cout << "Enter the weights: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> weightOI[i];
            }
            cout << "Max weight of knapsack: " << endl;
            cin >> wOI;

            knapsackOnlyweight(wOI, weightOI, nOI);
            break;


        case 4:
            cout << "Enter the weights: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> weightFI[i];
            }
            cout << "Enter the profits: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> profitFI[i];
            }
            cout << "Max weight of knapsack: " << endl;
            cin >> wD;

            knapsackFractional(wFI, weightFI, profitFI, true, nFI);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}



int knapsackINT(int wI, int *weightI, int *profitI, int nI)
{
    if (nI == 0 || wI == 0)
    {
        return 0;
    }
    else if (weightI[nI - 1] > wI)
    {
        return knapsackINT(wI, weightI, profitI, nI - 1);
    }
    else
    {
        return max(profitI[nI - 1] + knapsackINT(wI - weightI[nI - 1], weightI, profitI, nI - 1), knapsackINT(wI, weightI, profitI, nI - 1));
    }
}

void knapsackInt(int wI, int *weightI, int *profitI, int nI)
{
    cout << "The final w: " << knapsackINT(wI, weightI, profitI, nI) << endl;
}

double knapsackDOUBLE(double wD, double *weightD, double *profitD, int nD)
{
    if (nD == 0 || wD == 0.0)
    {
        return 0;
    }
    else if (weightD[nD - 1] > wD)
    {
        return knapsackDOUBLE(wD, weightD, profitD, nD - 1);
    }
    else
    {
        return max(profitD[nD - 1] + knapsackDOUBLE(wD - weightD[nD - 1], weightD, profitD, nD - 1), knapsackDOUBLE(wD, weightD, profitD, nD - 1));
    }
}

void knapsackDouble(double wD, double *weightD, double *profitD, int nD)
{
    cout << "The final w: " << knapsackDOUBLE(wD, weightD, profitD, nD) << endl;
}

void knapsackOnlyweight(int wOI, int *weightOI, int nOI)
{
    int knapsackW = 0;
    sort(weightOI, weightOI + nOI);

    while(knapsackW <= wOI)
    {
        knapsackW = knapsackW + weightOI[nOI-1];

        if (knapsackW > wOI)
        {
            knapsackW = knapsackW - weightOI[nOI-1];
            cout << "The weight is: " << knapsackW << endl;
            break;
        }
        else if (knapsackW == wOI)
        {
            cout << "The weight is: " << knapsackW << endl;
            break;
        }
        nOI--;
    }
}

void knapsackFractional(int knapW, int *arrW, int *arrP, bool, int N)
{
    int i = 0, j=0;
    double finalProfit;

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
    int k = 1;

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