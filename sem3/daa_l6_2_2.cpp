// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Greedy strategy for Optimum binary search tree

#include <iostream>
#include <math.h>
using namespace std;

class greedyBST
{
private:
    int i, j, k, temp, p, q, s;

public:
    greedyBST()
    {
        i = 0;
        j = 0;
        k = 1;
        temp = 0;
        p = 0;
        q = 0;
        s = 0;
    }

    void greedyOneStrategy(int *arrT, int *arrF, int arrSize, int frequency)
    {
        // Sorting the frequencies, corresponding keys also sorted
        // while frequencies being sorted
        for (i = arrSize - 1; i >= 0; i--)
        {
            for (j = arrSize - 1; j >= k; j--)
            {
                //comparing two consecutive elements
                // if left element is greater than right element then swap
                if (arrF[j] > arrF[j - 1])
                {
                    swap(arrF[j], arrF[j - 1]);
                    swap(arrT[j], arrT[j - 1]);
                }
            }
            k++;
        }

        // Displaying after frequencies sorted
        cout << "\033[4;33mFrequencies after sorted and corresponding keys too:\033[0m" << endl;
        cout << "\033[4;33mKeys\033[0m  \033[4;33mFrequencies:\033[0m" << endl;
        for (int i = 0; i < arrSize; i++)
        {
            cout << " " << arrT[i] << "     " << arrF[i] << endl;
        }

        int sizeTree = pow(2, arrSize);
        int dubTree[sizeTree];
        int dubFtree[sizeTree];

        for (i = 0; i < sizeTree; i++)
        {
            dubTree[i] = -1;
            dubFtree[i] = -1;
        }

        // Arrays of tree and frequency,
        // of max possible height based on the input of actual array
        dubTree[q] = arrT[s];
        dubFtree[q] = arrF[s];
        s++;

        int count = 0, count1 = 0;

        while (s < arrSize)
        {
            if (arrT[s] < dubTree[0])
            {
                if (count != 0)
                {
                    if (arrT[s] < dubTree[q])
                        q = 2 * q + 1;
                    if (arrT[s] > dubTree[q])
                        q = 2 * q + 2;
                }
                if (arrT[s] < dubTree[q])
                {
                    dubTree[2 * q + 1] = arrT[s];
                    dubFtree[2 * q + 1] = arrF[s];
                }
                else if (arrT[s] > dubTree[q])
                {
                    dubTree[2 * q + 2] = arrT[s];
                    dubFtree[2 * q + 2] = arrF[s];
                }
                count++;
            }
            else if (arrT[s] > dubTree[0])
            {
                if (count1 != 0)
                {
                    if (arrT[s] < dubTree[p])
                        p = 2 * p + 1;
                    if (arrT[s] > dubTree[p])
                        p = 2 * p + 2;
                }
                if (arrT[s] > dubTree[p])
                {
                    dubTree[2 * p + 2] = arrT[s];
                    dubFtree[2 * p + 2] = arrF[s];
                }
                else if (arrT[s] < dubTree[p])
                {
                    dubTree[2 * p + 1] = arrT[s];
                    dubFtree[2 * p + 1] = arrF[s];
                }
                count1++;
            }
            s++;
        }

        cout << "Displaying final: " << endl;
        for (int i = 0; i < sizeTree; i++)
        {
            cout << " " << dubTree[i] << "     " << dubFtree[i] << endl;
        }
    }
};

int main()
{
    int _arrSize, _frequency;

    greedyBST g1;

    cout << "\033[1;31m\nEnter the size of the array (which is same as the freq array size): " << endl;
    cin >> _arrSize;

    _frequency = _arrSize;
    int _arrT[_arrSize], _arrF[_frequency];

    cout << "Enter the " << _arrSize << " integers and corresponding frequency: \033[0m" << endl;
    for (int i = 0; i < _arrSize; i++)
    {
        cin >> _arrT[i] >> _arrF[i];
    }

    g1.greedyOneStrategy(_arrT, _arrF, _arrSize, _frequency);

    return 0;
}