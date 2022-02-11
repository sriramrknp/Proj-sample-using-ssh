// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Insertion sort

#include <iostream>
using namespace std;

class selection_sort
{
public:
    int mid;

public:
    void finding(int *arr, int array_size)
    {
        int size = array_size;

        int temp, theEle, index;
        int i, j;

        // cout << "j = ";
        for (i = 1; i < array_size; i++)
        {
            theEle = arr[i];
            j = i - 1;

            index = binary_search(arr, 0, i - 1, arr[i]);
            //cout << j << " ";
            while (j >= index)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = theEle;
        }
    }

    int binary_search(int *arr, int low, int high, int key)
    {
        while (high >= low)
        {
            mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            //if searching element is greater than middle element

            else if (key > arr[mid])
            {
                //if(key < arr[mid + 1] && mid != 0)
                // return mid;
                //else
                return binary_search(arr, mid + 1, high, key);
            }
            //searchindgelement is smallwer than middle element
            else
            {
                //if(key > arr[mid - 1] && mid != 0)
                //  return mid;
                //else
                return binary_search(arr, low, mid - 1, key);
            }
        }
        //if search elment is not present
        return low;
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
    selection_sort s1;
    s1.finding(arr, arraySize);
    cout << endl;

    // Displaying the final matrix
    cout << "The sorted final array is: " << endl;
    for (int k = 0; k < arraySize; k++)
    {
        cout << " " << arr[k];
    }

    return 0;
}
