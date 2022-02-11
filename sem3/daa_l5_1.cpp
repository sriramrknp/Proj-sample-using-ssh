// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Merge sort

#include <iostream>
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

        //cout << "lower and upper: " << lb << " " << mid << " " << ub << " " << endl;
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

    void finding(int *arr, int start, int array_size )
    {
        cout << "finding entered: " << endl;
        int size = array_size;

        int temp;
        int i, j;

        for (i = start; i < array_size; i++)
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

        // Displaying the final matrix
        //cout << "The sorted final array is: " << endl;
        //for (int k = 0; k < array_size; k++)
        //{
          //  cout << " " << arr[k];
        //}
    }

    // Dividing the array into 2, further each into 2 etc
    void process_2way(int *arr, int begin, int end)
    {

        if (begin < end)
        {
            int middle = begin + (end - begin) / 2;

            cout << "Begin and middle: " << begin << " " << middle << endl;
            
            //if (middle == 19)
            //{
              //  finding(arr, begin, middle);
              //  return;
            //}
            //else
                process_2way(arr, begin, middle);

            cout << "middle and end: " << middle + 1 << " " << end << endl;
            //if ((middle + 1) == 40)
            //{
              //  finding(arr, middle+1, end);
              //  return;
            //}
            //else
                process_2way(arr, middle + 1, end);

            cout << "merge: " << endl;
            merge_2way(arr, begin, middle, end);
        }
    }
};

// Main program
int main()
{
    int arrsize;
    //cout << "Enter the array size: ";
    //cin >> arrsize;

    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 16,7, 43, 423, 987, 3459, 75,4, 75, 13, 87, 97, 675, 643,  765, 18, 179, 87, 871, 8, 16,
     9237, 18,967, 98,167, 28,36, 87, 87, 81, 97, 87, 
     7, 6, 567, 87, 86, 134, 621, 67, 61, 6874, 1346, 76, 871, 710, 34, 819, 871, 98,64, 347, 76, 96, 91,78, 8774, 761, 76, 7, 54,
      2654, 76, 826,477, 72,65, 747, 45, 33, 48};
    
    //cout << "Enter elements:" << endl;
    //for (int i = 0; i < arrsize; i++)
    //{
      //  cin >> arr[i];
    //}

    arrsize = sizeof(arr)/sizeof(arr[0]);

    cout << "array size: " << arrsize << endl;

    mergeSort m1;
    m1.process_2way(arr, 0, arrsize - 1);
    m1.display_2way(arr, arrsize);
    return 0;
}