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
    
    void finding(int *arr, int array_size)
    {
        int size = array_size;

        int temp;
        int i,j;
        
        for(i=1; i<array_size; i++)
        {
            temp = arr[i];
            j = i-1;
            
            // linear scan to Sorted part 
            while(j >= 0 && arr[j]>temp)
            {
                arr[j+1] = arr[j];
                j--;
            }
            
            arr[j+1] = temp;
        }
        
        // Displaying the final matrix
        cout << "The sorted final array is: " << endl;
        for(int k=0; k < array_size; k++)
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
    for(int i=0; i<arraySize; i++)
    {
        cin >> arr[i];
    }
    
    // Object creation
    selection_sort s1;
    s1.finding(arr, arraySize);
    
    return 0;
}
