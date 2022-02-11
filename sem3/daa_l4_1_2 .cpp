// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Selection sort

#include <iostream>
using namespace std;

class selection_sort
{
    public:
    
    void finding(int *arr, int array_size)
    {
        int size = array_size;
        int MAX;
        
        // Asssigining arr[0] to MAX
        MAX = arr[0];
        int temp;
        int k;
        
        for(int j=0; j<array_size; j++)
        {
            // At each ith itration finding max in first n-i elements and 
            // Swaping elements at max index and n-i
            for(int i=0; i < size; i++)
            {
                if(arr[i] >= MAX)
                {
                   //Ubdating max
                   MAX = arr[i];
                   // Noting the index of MAX
                   k = i;
                }
            }
            // Interchanging elements
            temp = arr[array_size - (j+1)];
            arr[array_size - (j+1)] = MAX;
            arr[k] = temp;
            
            // Reducing the size at each itration of
            // 2nd loop
            size = size - 1;
            MAX = arr[0];
        }
        
        // Displaying the final matrix
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