// CS20B1107, CHEERLA SRIRAM REDDY

// Bubble sort, Using templates

#include <iostream>
using namespace std;
 
// Creating template,
// Which sorts, based on the array type
template <typename T>
void BubbleSort()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    // Array based on user type
    T arr[n];

    cout << "Enter the array elements of the choosen type: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Since, temp is storing array element,
    // so it is also the same type of array
    T temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            //comparing two consecutive elements
            // if left element is greater than right element then swap
            if (arr[j] > arr[j + 1])
            {
                // Swapping
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Printing the final sorted array
    cout << endl
         << "The sorted array is: " << endl;
    cout << "    ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main program
int main()
{
    int choice;
    while (1)
    {
        // Menu
        cout << endl;
        cout << "Choose 1. to 'The type of array elements are integers:' " << endl;
        cout << "Choose 2. to 'The tyep of array elements are float:' " << endl;
        cout << "Choose 3. to 'The type of array elements are characters:' " << endl;
        cout << "Choose 4. to 'The type of array elements are double: '" << endl;
        cout << "Choose 5. to 'Exit' " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Array type is int
            BubbleSort<int>();
            break;
        case 2:
            // Array type is float
            BubbleSort<float>();
            break;
        case 3:
            // Array type if char
            BubbleSort<char>();
            break;
        case 4:
            // Array type is double
            BubbleSort<double>();
            break;
        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}