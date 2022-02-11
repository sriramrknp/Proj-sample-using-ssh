// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding max in array using linear approach approach
// Lab 3, 1st problem - 1 way

#include <iostream>
using namespace std;

//Class definition
class arraymax
{
public: //public, access specifier, can be accessed directly from main
    //Function definition
    void toFindMaxMinsecMaxsecMin(int usize)
    {
        int arr[usize];
        int i;
        int MAX;

        //boundary conditions
        if (usize < 0)
        {
            cout << "\nEntered size is not appropriate, Please try again \n";
            exit(0);
        }
        else
        {
            cout << "Ënter " << usize << " integers" << endl;
            for (i = 0; i < usize; i++)
            {
                //inputting elements into the array
                cin >> arr[i];
            }
        }

        MAX = arr[0];

        for (i = 0; i < usize; i++)
        {
            if (arr[i] > MAX)
            {
                //Ubdating max
                MAX = arr[i];
            }
        }

        //Printing the final elements of min, max, secmin, secmax
        cout << "\nThe MAX of the array is " << MAX << endl;
    }
};

//Main program
int main()
{
    int i;

    //Creating the object to the class named array
    arraymax arr1;

    int MAX;
    int ussize;

    cout << "\nEnter the size of the array:" << endl;
    cin >> ussize;

    //Sending the size to the array through calling the function in class
    arr1.toFindMaxMinsecMaxsecMin(ussize);

    return 0;
}