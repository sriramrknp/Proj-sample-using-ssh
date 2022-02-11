// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Bubble sort 

#include <iostream>
using namespace std;
class A
{
    int arr[25];
    int n, i, j;

public:
    //bubblesort
    void BubbleSort(int arr[], int n)
    {
        int temp;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                //comparing two consecutive elements if left element is greater than right element then swap
                if (arr[j] > arr[j + 1]) 
                {

                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    //Displaying sorted list
    void display(int arr[], int n)
    {
        cout << endl << "the sorted array is: " << endl;
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    int arr[25];
    int n, i;
    cout << "Enter the no of array elements u want: " << endl;
    cin >> n;
    cout << "Enter the array elements" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    A obj;                  //creation of object
    obj.BubbleSort(arr, n); //calling bubblesort
    obj.display(arr, n);
    
    return 0;
}