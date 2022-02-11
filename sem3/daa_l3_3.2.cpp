// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// recursive way of doing the, binary and ternary search
// Lab-3, 3rd problem, recurssion

#include <iostream>

using namespace std;
class T_search
{
public:
    int arr[25], n;

public:
    //ittrative method
    int ternaraysearch(int arr[], int low, int high, int key)
    {

        while (high >= low)
        {
            int mid1 = low + (high - low) / 3;
            int mid2 = low + 2 * (high - low) / 3;

            if (key < arr[mid1]) //searching element is less than 1st middle element
            {
                high = mid1 - 1;
            }
            else if (key > arr[mid2]) //searching element is greater than 2nd middle element
            {
                low = mid2 + 1;
            }
            else if (key > arr[mid1] && key < arr[mid2]) //seraching element is between 1st middle element and 2nd middle element
            {
                low = mid1 + 1;
                high = mid2 - 1;
            }
            if (key == arr[mid1]) //Searching element is equal to 1st middle element then return mid1
            {
                return mid1;
            }

            else if (key == arr[mid2]) //Searching element is equal to 2nd middle element then return mid1
            {
                return mid2;
            }
        }
        //if search elment is not present
        return -1;
    }
    //recursive method
    int ternaray_search1(int *arr, int low, int high, int key)
    {

        while (high >= low)
        {
            int mid1 = low + (high - low) / 3;
            int mid2 = low + 2 * (high - low) / 3;
            if (arr[mid1] == key) //Searching element is equal to 1st middle element then return mid1
            {
                return mid1;
            }
            else if (key == arr[mid2]) //Searching element is equal to 2nd middle element then return mid1
            {
                return mid2;
            }
            else if (key < arr[mid1]) //searching element is less than 1st middle element
            {
                return ternaray_search1(arr, low, mid1 - 1, key);
            }
            else if (key > arr[mid2]) //searching element is greater than 2nd middle element
            {
                return ternaray_search1(arr, mid2 + 1, high, key);
            }
            else if (key > arr[mid1] && key < arr[mid2]) //seraching element is between 1st middle element and 2nd middle element
            {
                return ternaray_search1(arr, mid1 + 1, mid2 - 1, key);
            }
        } //while loop ends
        //if search elment is not present
        return -1;
    }
};
int main()
{
    int arr[25];
    int n, i, key;
    cout << "Enter number to elements in the array: " << endl;
    cin >> n;
    cout << "Enter array elements: " << endl;
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
    cout << "The sorted array is:" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Enter the element to be searched: \n";
    cin >> key;
    T_search b1;
    int index1 = b1.ternaraysearch(arr, 1, n, key);
    if (index1 == -1)
    {
        cout << "Element is not found" << endl;
    }
    else
    {
        cout << "Element fount at index: " << index1 << endl;
    }
    int index = b1.ternaray_search1(arr, 1, n, key);
    if (index == -1)
    {
        cout << "Element is not found " << endl;
    }
    else
    {
        cout << "Element fount at index: " << index << endl;
    }
    return 0;
}
