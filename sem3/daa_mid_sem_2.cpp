// CS20B1107, CHEERLA SRIRAM REDDY

// Program to implement dual pivot QuickSort

// Logic is to taking index 1 as 1st pivot
// next arraysize - 2 as secong pivot
// and proceding according to the quicksort
// instead of taking one we take two
// Similarly the array left is less than 1st pivot
// middle > than 1st and less than 2nd
// right > than second pivot

// This is the logic, proceeding with recurssion


#include <iostream>
using namespace std;

class dualpivot_QuickSort
{
    public:

    int dividing(int *arr, int low, int high, int *lp)
    {
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);

        int j = low + 1;
        int g = high - 1, k = low + 1;
        int leftp = arr[low], rightp = arr[high];

        while (k <= g)
        {
            // Checking Less than left pivot
            if (arr[k] < leftp)
            {
                swap(arr[k], arr[j]);
                j++;
            }

            // Checking Greater than or equal
            // to the right pivot
            else if (arr[k] >= rightp)
            {
                while (arr[g] > rightp && k < g)
                    g--;
                swap(arr[k], arr[g]);
                g--;
                if (arr[k] < rightp)
                {
                    swap(arr[k], arr[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;

        // Sets at appropriate position
        swap(arr[low], arr[j]);
        swap(arr[high], arr[g]);

        *lp = j; 

        return g;
    }

    void dualPivotQuickSort_Recc(int *arr, int low, int high)
    {
        if (low < high)
        {
            int leftp, rightp;
            rightp = dividing(arr, low, high, &leftp);
            // One from low to leftp - 1
            dualPivotQuickSort_Recc(arr, low, leftp - 1);
            // One from leftp +1 to rightp - 1
            dualPivotQuickSort_Recc(arr, leftp + 1, rightp - 1);
            // Last is rightp + 1 to end
            dualPivotQuickSort_Recc(arr, rightp + 1, high);
            // Everytime it repeats
        }
    }
};

// Main program
int main()
{
    int arraySize;
    cout << "Enter the arry size: " << endl;
    cin >> arraySize;

    int arr[arraySize];
    cout << "Enter " << arraySize << " integers: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }

    // Creating the object
    dualpivot_QuickSort qs1;

    qs1.dualPivotQuickSort_Recc(arr, 0, arraySize - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

