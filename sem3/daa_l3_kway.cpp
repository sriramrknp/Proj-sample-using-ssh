// Group 13

// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding maximum using k-way
// Lab-3, 1st problem, using k way

#include <iostream>
using namespace std;

class kWay
{
public:
    void findMax_Kway(int *arr, int arrSize, int k)
    {
        int MAX;

        // If array size is equal to k then we do comparisions by linearly
        if (k == arrSize)
        {
            MAX = arr[0];
            for (int i = 0; i < arrSize; i++)
            {
                if (arr[i] > MAX)
                {
                    MAX = arr[i];
                }
            }
            cout << "The MAX is: " << MAX << endl;
        }

        // if array size is multiple of K, then divided arrays size are equal
        else if ((arrSize % k) == 0)   
        {
            int div = arrSize / k;
            int arrK[k];
            int count = 0;

            for (int j = 0; j < arrSize; j = j + div)
            {
                arrK[count] = arr[j];
                for (int i = j; i < (j + (div)); i++)
                {
                    if (arr[i] > arrK[count])
                    {
                        arrK[count] = arr[i];
                    }

                }
                count++;
            }

            MAX = arrK[0];

            for (int i = 0; i < k; i++)
            {
                if (arrK[i] > MAX)
                {
                    MAX = arrK[i];
                }
            }

            cout << "The MAX is: " << MAX << endl;
        }

        // If array size is not a multiple of K, then last divided array size is different 
        else if((arrSize % k) != 0)   
        {
            int div1 = arrSize / k;
            int arrK1[k];
            int count1 = 0;

            for (int j = 0; j < arrSize; j = j + div1)
            {
                arrK1[count1] = arr[j];
                if (j == (div1*(k-1)))
                {
                    for (int i = j; i < arrSize; i++)
                    {
                        if (arr[i] > arrK1[count1])
                        {
                            arrK1[count1] = arr[i];
                        }
                    }
                }
                else
                {
                    for (int i = j; i < (j + (div1)); i++)
                    {
                        if (arr[i] > arrK1[count1])
                        {
                            arrK1[count1] = arr[i];
                        }
                    }
                }
                count1++;
            }

            MAX = arrK1[0];

            cout << endl;

            for (int i = 0; i < k; i++)
            {
                if (arrK1[i] > MAX)
                {
                    MAX = arrK1[i];
                }
            }

            cout << "The MAX is: " << MAX << endl;
        }
    }
};

// Main program
int main()
{
    int arrsize, k;
    cout << "Enter the value of k:" << endl;
    cin >> k;

    if(k < 0)
    {
        cout << "Sorry!, invalid k is selected please try again: " << endl;
        cin >> k;
    }
    cout << "Enter the array size: ";
    cin >> arrsize;

    if(arrsize < 0 || arrsize < k)
    {
        cout << "Sorry!, invalid array size is selected please try again: " << endl;
        cin >> arrsize;
    }

    int arr[arrsize];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        cin >> arr[i];
    }

    kWay k1;
    k1.findMax_Kway(arr, arrsize, k);

    return 0;
}