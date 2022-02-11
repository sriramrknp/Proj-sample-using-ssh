

// Program to implement dual pivot QuickSort

#include <iostream>
using namespace std;

class dualpivot_QuickSort
{
    private:
        int arraySize;
public:
    dualpivot_QuickSort(int arrsize)
    {
        arraySize = arrsize;
    }
    void display(int *arr)
    {
        cout << "MIDDLE: " ;
        for (int i = 0; i < arraySize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int dividing(int *arr, int low, int high, int *lp)
    {
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);
        
        cout << "dividing ";
        display(arr);
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
            cout << "dividing ";
            display(arr);
            k++;
        }
        j--;
        g++;

        cout << "dividing ";
        display(arr);

        // Sets at appropriate position
        swap(arr[low], arr[j]);
        swap(arr[high], arr[g]);

        *lp = j;

        cout << "dividing ";
        display(arr);

        return g;
    }

    void dualPivotQuickSort_Recc(int *arr, int low, int high)
    {
        if (low < high)
        {
            int leftp, rightp;
            rightp = dividing(arr, low, high, &leftp);
            // One from low to leftp - 1
            cout << "left and right: " << arr[leftp] << " " << arr[rightp] << endl;
            dualPivotQuickSort_Recc(arr, low, leftp - 1);
            // One from leftp +1 to rightp - 1
            display(arr);
            dualPivotQuickSort_Recc(arr, leftp + 1, rightp - 1);
            // Last is rightp + 1 to end
            display(arr);
            dualPivotQuickSort_Recc(arr, rightp + 1, high);
            // Everytime it repeats
            display(arr);
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
    dualpivot_QuickSort qs1(arraySize);

    qs1.dualPivotQuickSort_Recc(arr, 0, arraySize - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
