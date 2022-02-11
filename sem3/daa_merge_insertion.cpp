// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Merge sort

#include <iostream>
#include <time.h>
using namespace std;

class mergeSort
{
private:
    int middle;

public:
    void display(int *arr, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void display_2way(int *arr, int size)
    {
        cout << "The sorted array is: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << " " << arr[i];
        }
        cout << endl;
    }

    // Merging the eleemnts by comparing
    void merge_2way(int *arr, int lb, int mid, int ub)
    {
        int i, j, k, nl, nr;

        nl = mid - lb + 1;
        nr = ub - mid;
        int larr[nl], rarr[nr];

        cout << "lower and upper: " << lb << " " << mid << " " << ub << " " << endl;
        for (i = 0; i < nl; i++)
            larr[i] = arr[lb + i];
        for (j = 0; j < nr; j++)
            rarr[j] = arr[mid + 1 + j];
        i = 0;
        j = 0;
        k = lb;

        while (i < nl && j < nr)
        {
            if (larr[i] <= rarr[j])
            {
                arr[k] = larr[i];
                i++;
            }
            else
            {
                arr[k] = rarr[j];
                j++;
            }
            k++;
        }
        while (i < nl)
        {
            arr[k] = larr[i];
            i++;
            k++;
        }
        while (j < nr)
        {
            arr[k] = rarr[j];
            j++;
            k++;
        }
    }

    void finding(int *arr, int start, int array_size)
    {
        cout << "finding entered: " << endl;
        int size = array_size;

        int temp;
        int i, j;

        for (i = start; i <= array_size; i++)
        {
            temp = arr[i];
            j = i - 1;

            // linear scan to Sorted part
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = temp;
        }
    }

    // Dividing the array into 2, further each into 2 etc
    void process_2way(int *arr, int begin, int end)
    {

        if (begin < end)
        {
            int middle = begin + (end - begin) / 2;

            if ((end - begin) <= 20)
            {
                finding(arr, begin, end);
            }
            else
            {
                cout << "Begin and middle: " << begin << " " << middle << endl;
                process_2way(arr, begin, middle);

                cout << "middle and end: " << middle + 1 << " " << end << endl;
                process_2way(arr, middle + 1, end);

                cout << "merge: " << endl;
                merge_2way(arr, begin, middle, end);
            }
        }
    }
};

// Main program
int main()
{
    srand(time(0));
    int arrsize;
    cout << "Enter the array size: ";
    cin >> arrsize;

    int arr[arrsize];

    //cout << "Enter elements:" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        arr[i] = rand() % 1000;
    }

    //arrsize = sizeof(arr)/sizeof(arr[0]);

    cout << "array size: " << arrsize << endl;

    mergeSort m1;
    m1.process_2way(arr, 0, arrsize - 1);
    m1.display_2way(arr, arrsize);
    return 0;
}