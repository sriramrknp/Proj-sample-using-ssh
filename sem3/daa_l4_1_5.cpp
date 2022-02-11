// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Insertion sort

#include <iostream>
using namespace std;

class heap_sort
{
public:
    void heapify(int arr[], int n, int i)
    {
        int lst = i;
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 

        // checking left child is larger than root
        if (l < n && arr[l] > arr[lst])
            lst = l;

        // checking right child is larger than largest so far
        if (r < n && arr[r] > arr[lst])
            lst = r;

        // Root is not largest
        if (lst != i)
        {
            swap(arr[i], arr[lst]);

            // certain non leaf elements or any sub tree is 
            // not a max heap, then again form that into max heap
            heapify(arr, n, lst);
        }
    }

    void heapsort(int *arr, int array_size)
    {
        // Building max heap
        for (int i = array_size / 2 - 1; i >= 0; i--)
            heapify(arr, array_size, i);

        for (int i = array_size - 1; i > 0; i--)
        {
            // Deleting max heap
            // after deletion again reforming the max heap 
            // for remaning elements
            swap(arr[0], arr[i]);

            heapify(arr, i, 0);
        }

        // Displaying the final matrix
        cout << "The sorted final array is: " << endl;
        for (int k = 0; k < array_size; k++)
        {
            cout << " " << arr[k];
        }
    }
};

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

    // Object creation
    heap_sort s1;
    s1.heapsort(arr, arraySize);

    return 0;
}
