// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding max in array using 2-way approach
// Lab 3, 1st problem - 2 way approach

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
        void display_2way(int *arr, int size)
        {
            cout << "The max element in tha array is: " << arr[size - 1] << endl;
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

        // Dividing the array into 2, further each into 2 etc
        void process_2way(int *arr, int begin, int end)
        {
            
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

    int arr[arrsize];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        cin >> arr[i];
    }

    findmax m1;
    m1.process_2way(arr, 0, arrsize - 1); 
    m1.display_2way(arr, arrsize);
    return 0;
}