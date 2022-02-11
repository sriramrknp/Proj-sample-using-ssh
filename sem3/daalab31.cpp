// Problem 1

#include <iostream>
using namespace std;

class findmax
{
private:
    //int mid, arrsize;

public:
    int mid, arrsize;
    findmax(int arrSize)
    {
        arrsize = arrSize;
    }

    void merge2Way(int arr[], int lb, int mid, int ub)
    {
        int i;
        int j;
        int k;
        int nl = mid - lb + 1;
        int nr = ub - mid;
        int larr[nl], rarr[nr];
        cout << "lower and upper: " << lb << " " << ub << " " << mid << " " << endl;

        for (int k = 0; k < nl; k++)
            larr[k] = arr[lb + k];
        for (int s = 0; s < nr; s++)
            rarr[s] = arr[mid + 1 + s];
        i = 0;
        j = 0;
        k = lb;

        while (i < nl && j < nr)
        {
            if (larr[i] <= rarr[j])
            {
                arr[k] = larr[i];
                //cout << "left: " <<arr[k] << " " <<endl;
                i++;
            }
            else
            {
                arr[k] = rarr[j];
                // cout << "right: " <<arr[k] << " " <<endl;
                j++;
            }
            k++;
        }

        while (i < nl)
        {
            arr[k] = larr[i];
            //cout << "while 1: " <<arr[k] << " " <<endl;
            i++;
            k++;
        }
        while (j < nr)
        {
            arr[k] = rarr[j];
            //cout << "while 2: " <<arr[k] << " " <<endl;
            j++;
            k++;
        }
    }

    void findMax_2Way(int arr[], int be, int en)
    {
        //cout << "lower and upper: " << lb << " " << ub << endl;

        if (be < en)
        { //return;

            mid = be + (en - be) / 2;
            cout << "1 ";
            findMax_2Way(arr, be, mid);
            cout << "2 ";
            findMax_2Way(arr, mid + 1, en);
            cout << "3 ";
            merge2Way(arr, be, mid, en);
            cout << "4 " << endl;
        }
    }
    void display(int arr[], int arrSize)
    {
        for (int i = 0; i < arrsize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arrSize;

    cout << "Enter the array size: " << endl;
    cin >> arrSize;

    int arr[arrSize];

    cout << "Enter the " << arrSize << " integers: " << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    int Lb = 0, Ub = arrSize - 1;
    //int arrSize = arrsize;
    findmax m1(arrSize);

    m1.display(arr, arrSize);
    m1.findMax_2Way(arr, 0, arrSize - 1);

    cout << "Final array: " << endl;
    m1.display(arr, arrSize);

    return 0;
}