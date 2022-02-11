// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// finding number of negative numbers using 2-way
// Lab 3, 2nd problem - 2 way approach

#include <iostream>
using namespace std;

class findmax
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
        void display_2way(int *arr, int arrSize)
        {
            int count = 0;
            for (int i = 0; i < arrSize; i++)
            {
                if(arr[i] < 0)
                {
                    count++;
                } 
            }
            cout << "The number of negative numbers in the array are: " << count << endl;
            cout << endl;
        }

        // Merging the elements by comparing, after dividing
        void merge_2way(int *arr, int lb, int mid, int ub)
        {
            int i, j, k, nl, nr;
            //size of left and right sub-arrays
            nl = mid - lb + 1;
            nr = ub - mid;
            int larr[nl], rarr[nr];

            //fill left and right sub-arrays
            for (i = 0; i < nl; i++)
                larr[i] = arr[lb + i];
            for (j = 0; j < nr; j++)
                rarr[j] = arr[mid + 1 + j];
            i = 0;
            j = 0;
            k = lb;

            //merge temp arrays to real array
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
            { //extra element in left array
                arr[k] = larr[i];
                i++;
                k++;
            }
            while (j < nr)
            { //extra element in right array
                arr[k] = rarr[j];
                j++;
                k++;
            }
        }

        // Dividing the arrays into two, further two etc
        void process_2way(int *arr, int begin, int end)
        {
            //int middle;
            if (begin < end)
            {
                int middle = begin + (end - begin) / 2;

                process_2way(arr, begin, middle);
                process_2way(arr, middle + 1, end);
                merge_2way(arr, begin, middle, end);
            }
        }
};

// Main program
int main()
{
    int arrsize;
    cout << "Enter the array size: ";
    cin >> arrsize;

    int arr[arrsize]; //create an array with given number of elements
    cout << "Enter elements:" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        cin >> arr[i];
    }

    findmax m1;
    m1.process_2way(arr, 0, arrsize - 1); //(n-1) for last index
    m1.display_2way(arr, arrsize);
    return 0;
}