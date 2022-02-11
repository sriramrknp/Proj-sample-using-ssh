
#include <iostream>
using namespace std;

class selection_sort
{
    public:
    
    void finding(int *arr, int array_size)
    {
        int size = array_size;
        int MAX;
        MAX = arr[0];
        int temp;
        int k;
        
        for(int j=0; j<array_size; j++)
        {
            for(int i=0; i < size; i++)
            {
                if(arr[i] >= MAX)
                {
                   //Ubdating max
                   MAX = arr[i];
                   k = i;
                }
            }
            temp = arr[array_size - (j+1)];
            arr[array_size - (j+1)] = MAX;
            arr[k] = temp;
            size = size - 1;
            MAX = arr[0];
        }
        
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
    
    selection_sort s1;
    s1.finding(arr, arraySize);
    
    return 0;
}