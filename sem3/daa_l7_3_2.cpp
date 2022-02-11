// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// max and min with min number of compariions

#include<iostream>
#include<climits>
using namespace std;

void finding(int arr[], int n)
{
    int min = 0, max = 0;
    /*If there is only one element then return it as min and max both*/
    if (n == 1)
    {
        min = max = arr[0];
    }
    /* If there are more than one elements, then initialize min and max*/
    if (arr[0] > arr[1])
    {
        max = arr[0];
        min = arr[1];
    }
    else
    {
        max = arr[1];
        min = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;
}
// Driver program to test above function 
int main()
{
    int size;
    cout << "Enter the array size: " << endl;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size;i++)
    {
        cout << "Enter the element: " << endl;
        cin >> arr[i];
    }
        finding(arr, size);
}