// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Iterative way of doing the, binary and ternary search
// Lab3, 3rd problem, Iterative

#include <iostream>
using namespace std;

class bi_search
{
public:
    int arr[25], n;

public:
    //ittrative method
    int binarysearch(int arr[], int low, int high, int key)
    {

        while (high >= low)
        {
            int mid = (low + high) / 2;

            //if searching element is greater than middle element

            if (key > arr[mid])
            {
                low = mid + 1;
            }
            //searchindgelement is smallwer than middle element
            else if (key < arr[mid])
            {
                high = mid - 1;
            }
            //searching element is equql  to middle element
            else
            {
                return mid;
            }
        }
        //if search elment is not present
        return -1;
    }
    //recursive method
    int binary_search(int *arr, int low, int high, int key)
    {

        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            //if searching element is greater than middle element

            else if (key > arr[mid])
            {
                return binary_search(arr, mid + 1, high, key);
            }
            //searchindgelement is smallwer than middle element
            else
            {
                return binary_search(arr, low, mid - 1, key);
            }
        }
        //if search elment is not present
        return -1;
    }
};
int main()
{
    int arr[25];
    int n, i, key;
    cout << "Enter number to elements in the array: ";
    cin >> n;
    cout << "Enter array elements:";
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    //array should be shorted
    //bubble sort
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "the sorted array is:";
    for (i = 1; i <= n; i++)
    {
        cout << " " << arr[i];
    }
    

    cout << endl;

    cout << "Enter the element to be searched: \n";
    cin >> key;
    bi_search b1;
    int index1 = b1.binarysearch(arr, 1, n, key);
    if (index1 == -1)
    {
        cout << "Element is not found" << endl;
    }
    else
    {
        cout << "Element fount at : " << index1 << " " << endl;
    }
    int index = b1.binary_search(arr, 1, n, key);
    if (index == -1)
    {
        cout << "Element is not found" << endl;
    }
    else
    {
        cout << "Element fount at : " << index << " " << endl;
    }
    return 0;
}
