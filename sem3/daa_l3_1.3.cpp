// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding max in array using 3-way approach
// Lab 3, 1st problem - 3 way approach

#include <iostream>
using namespace std;

class findmax
{
public:
    void display(int *arr, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void display_3way(int *arr, int size)
    {
        cout << "The max element in tha array is: " << arr[size - 1] << endl;
        cout << endl;
    }

    // merging the elements, by comparing
    void merge_3way(int *arr, int lb, int mid, int mid2, int ub, int *arr1)
    {
        int i, j, k, p;
        i = lb;
        j = mid;
        k = mid2;
        p = lb;
        //marge temp arrays to real array

        while (i < mid && j < mid2 && k < ub)
        {
            if (arr[i] < arr[j])
            {
                if (arr[i] < arr[k])
                {
                    arr1[p] = arr[i];
                    i++;
                    p++;
                }
                else
                {
                    arr1[p] = arr[k];
                    k++;
                    p++;
                }
            }
            else
            {
                if (arr[j] < arr[k])
                {
                    arr1[p] = arr[j];
                    j++;
                    p++;
                }
                else
                {
                    arr1[p] = arr[k];
                    k++;
                    p++;
                }
            }
        }

        while (i < mid && j < mid2)
        {
            if (arr[i] < arr[j])
            {
                arr1[p] = arr[i];
                i++;
            }
            else
            {
                arr1[p] = arr[j];
                j++;
            }
            p++;
        }
        while (i < mid && k < ub)
        {
            if (arr[i] < arr[k])
            {
                arr1[p] = arr[i];
                i++;
            }
            else
            {
                arr1[p] = arr[k];
                j++;
            }
            p++;
        }
        while (k < ub && j < mid2)
        {
            if (arr[j] < arr[k])
            {
                arr1[p] = arr[j];
                j++;
            }
            else
            {
                arr1[p] = arr[k];
                k++;
            }
            p++;
        }

        while (i < mid)
        { //extra element in left array
            arr1[p] = arr[i];
            i++;
            p++;
        }
        while (j < mid2)
        { //extra element in right array
            arr1[p] = arr[j];
            j++;
            p++;
        }
        while (k < ub)
        { //extra element in right array
            arr1[p] = arr[k];
            k++;
            p++;
        }
    }

    // Dividing the array into 3 parts, further each into 3 parts etc
    void process_3way(int *arr, int begin, int end, int *arr1)
    {
        if ((end - begin) < 2)
            return;

        int middle1 = begin + ((end - begin) / 3);
        int middle2 = begin + 2 * ((end - begin) / 3) + 1;

        process_3way(arr1, begin, middle1, arr);
        process_3way(arr1, middle1, middle2, arr);
        process_3way(arr1, middle2, end, arr);

        merge_3way(arr1, begin, middle1, middle2, end, arr);
        
    }

    // Copying the elements into the new array
    void ms3way(int *arr, int arrSize)
    {
        if (arrSize == 0)
            return;

        int arr1[arrSize];

        for (int i = 0; i < arrSize; i++)
        {
            arr1[i] = arr[i];
        }

        process_3way(arr1, 0, arrSize, arr);

        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = arr1[i];
        }
        cout << endl;
    }
};

// Main program
int main()
{
    int arrsize;
    cout << endl;
    cout << "Enter the array size: ";
    cin >> arrsize;

    int arr[arrsize]; //create an array with given number of elements
    cout << "Enter elements:" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        cin >> arr[i];
    }

    findmax m1;
    m1.ms3way(arr, arrsize);
    m1.display_3way(arr, arrsize);

    return 0;
}