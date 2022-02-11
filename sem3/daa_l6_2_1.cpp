// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Matrix chain multiplication
 
#include <iostream>
using namespace std;

class matrixChainMul
{
private:
    int sum;

public:
    matrixChainMul()
    {
        sum = 0;
    }
    void greedyMatrixChain(int size, int *arrRowClm)
    {
        int k = 0;
        for (int j = 1; j < size-1; j++)
        {
            sum = sum + arrRowClm[k] * arrRowClm[j] * arrRowClm[j+1];
            cout << "i: " << arrRowClm[k] << " " << arrRowClm[j] << " " << arrRowClm[j+1] << endl;
        }
        cout << "The number of multiplications are: " << sum << endl;
    }
};

int main()
{
    int _size;
    matrixChainMul m1;
    cout << "Enter Matrix chain order: " << endl;
    cin >> _size;

    int _arrRowClm[_size];
    cout << "Enter the Matrix dimentions: " << endl;
    for (int i = 0; i < _size; i++)
    {
        cin >> _arrRowClm[i];
    }

    m1.greedyMatrixChain(_size, _arrRowClm);

    return 0;
}

//  a b c 