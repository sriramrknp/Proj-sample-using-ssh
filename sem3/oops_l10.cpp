// CS20B1107, CHEERLA SRIRAM REDDY
 
// Selection sort, using a templates
  
#include <iostream>
using namespace std;
#define SIZE 7

template <typename T>
void sort(T *arr, int arraySize)
{
    int size = arraySize;
    T MAX;

    // Asssigining arr[0] to MAX
    MAX = arr[0];
    T temp;
    int k;
    int i = 0, j = 0;

    for (j = 0; j < arraySize; j++)
    {
        // At each ith itration finding max in first n-i elements and
        // Swaping elements at max index and n-i
        for (i = 0; i < size; i++)
        {
            if (arr[i] >= MAX)
            {
                //Ubdating max
                MAX = arr[i];
                // Noting the index of MAX
                k = i;
            }
        }
        // Interchanging elements
        temp = arr[arraySize - (j + 1)];
        arr[arraySize - (j + 1)] = MAX;
        arr[k] = temp;

        // Reducing the size at each itration of
        // 2nd loop
        size = size - 1;
        MAX = arr[0];
    }

    cout << "******The array is sorted******" << endl;
}

// Main program
int main()
{
    int choice=0, choice1=0;
    int arrSize = SIZE;

    try
    {
        if (arrSize < 0)
            throw "Error";
    }
    catch (string err)
    {
        cout << "Exception handled: '" << err << "' " << endl;
    }

    int arrI[SIZE];
    float arrF[SIZE];
    char arrC[SIZE];

    cout << "*****************************************************" << endl;
    cout << "\033[1;31mThe array size is defined in program itself '#define'\033[0m\n";
    cout << "*****************************************************" << endl;

    while (1)
    {
        cout << endl;
        cout << "Choose 1. to Give Values " << endl;
        cout << "Choose 2. to Sort" << endl;
        cout << "Choose 3. to Display" << endl;
        cout << "Choose 4. to Exit" << endl;
        cout << "********Enter the choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter 1. to Give values of integers: " << endl;
            cout << "      2. to Give values of floating point numbers: " << endl;
            cout << "      3. to Give values of characters: " << endl;
            cin >> choice1;
            if (choice1 == 1)
            {
                cout << "Enter " << arrSize << " corresponding elements: " << endl;
                for (int i = 0; i < arrSize; i++)
                {
                    cin >> arrI[i];
                }
            }

            else if (choice1 == 2)
            {
                cout << "Enter " << arrSize << " corresponding elements: " << endl;
                for (int i = 0; i < arrSize; i++)
                {
                    cin >> arrF[i];
                }
            }

            else if (choice1 == 3)
            {
                cout << "Enter " << arrSize << " corresponding elements: " << endl;
                for (int i = 0; i < arrSize; i++)
                {
                    cin >> arrC[i];
                }
            }

            break;
        }
        case 2:
            if(choice1 == 0)
                cout << "The array is empty, Try selecting option 1" << endl;
            else if (choice1 == 1)
                // Calling sort func, of data types int
                sort<int>(arrI, arrSize);
            else if (choice1 == 2)
                // Calling sort func, of data types float
                sort<float>(arrF, arrSize);
            else if (choice1 == 3)
                // Calling sort func, of data types char
                sort<char>(arrC, arrSize);
            break;

        case 3:
            if(choice1 == 0)
                cout << "The array is empty, Try selecting option 1" << endl;
            else if (choice1 == 1)
            {
                cout << "The sorted array of integers is: " << endl;
                // Displaying the final array of int
                for (int k = 0; k < arrSize; k++)
                {
                    cout << " " << arrI[k];
                }
                cout << endl;
            }

            else if (choice1 == 2)
            {
                cout << "The sorted array of floating point numbers is: " << endl;
                // Displaying the final array of float
                for (int k = 0; k < arrSize; k++)
                {
                    cout << " " << arrF[k];
                }
                cout << endl;
            }

            else if (choice1 == 3)
            {
                cout << "The sorted array of characters is: " << endl;
                // Displaying the final array of char
                for (int k = 0; k < arrSize; k++)
                {
                    cout << " " << arrC[k];
                }
                cout << endl;
            }
            break;
        case 4:
            exit(0);
            break;
        }
    }

    return 0;
}