// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Matrix chain using dp
 
#include <iostream>
#include<limits.h>
using namespace std;

class matrixChainMul
{
private:
    int sum, N, i, j, k, q, l;

public:
    matrixChainMul()
    {
        sum = 0;
        i = 0;
        j = 0;
        k = 0;
    }
    void dpMatrixChain(int *arrRowClm, int size)
    {
        N = size;
        int M[size][size];

        for(i=1; i<N; i++)
            M[i][i] = 0;
        
        for(l = 2; l<N; l++)
        {
            for(i=1; i<N-l+1; i++)
            {
                j = i + l -1;
                M[i][j] = INT_MAX;
                for(k=i; k<= j - 1; k++)
                {
                    q = M[i][k] + M[k+1][j] 
                        + arrRowClm[i-1] * arrRowClm[k] * arrRowClm[j];
                    if(q < M[i][j])
                        M[i][j] = q;
                }
            }
        }

        cout << "\033[4;33mThe minimum cost is: " <<  M[1][N-1] ;
        cout << "\033[0m" << endl;
    }
};

int main()
{
    int _size;
    matrixChainMul m1;
    cout << "\033[1;31mEnter number of matrices: " << endl;
    cin >> _size;

    int _arrRowClm[_size];
    cout << "Enter the Matrix dimentions: " << endl;
    for (int i = 0; i <= _size; i++)
    {
        cin >> _arrRowClm[i];
    }
    cout << "\033[0m" << endl;

    m1.dpMatrixChain(_arrRowClm, _size+1);

    return 0;
}