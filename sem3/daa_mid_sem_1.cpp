// CS20B1107< CHEERLA SRIRAM REDDY

// Binary multiplication

// The logic is, first finding the binary of two integers
// then creating a 2D array, and storing the multiplied
// digits in each of the row, of 1st digit
// After that, adding each coloumn elements then we get the final answer
// in binary

#include <iostream>
using namespace std;

class binaryMul
{
public:
    void bin_mul(int m, int n)
    {
        // Converting m and n to binary

        int *arrm = new int(1);
        int *arrn = new int(1);

        int i = 0, j = 0;

        if (m == 0)
            *(arrm + 0) = 0;
        if (n == 0)
            *(arrn + 0) = 0;

        while (m != 0)
        {
            *(arrm + i) = m % 2;
            m = m / 2;
            i++;

            // Reallocating the memory for the array
            // Since we don't know how many bin digits for the integer
            int *arrm = new int(1);
        }
        while (n != 0)
        {
            *(arrn + j) = n % 2;
            n = n / 2;
            j++;

            // Reallocating the memory for the array
            // Since we don't know how many bin digits for the integer
            int *arrn = new int(1);
        }

        int m_bit = i;
        int n_bit = j;

        // Displaying elements
        cout << "m in binary : ";
        for (int s = i - 1; s >= 0; s--)
            cout << " " << *(arrm + s);

        cout << endl;

        cout << "n in binary: ";
        for (int s = j - 1; s >= 0; s--)
            cout << " " << *(arrn + s);
        cout << endl;

        // 
        // 
        //

        // Creating a 2D array for storintg the multiplication elements
        int arr2D[n_bit][m_bit + (n_bit - 1)];

        for (int i = 0; i < n_bit; i++)
        {
            for (int j = 0; j < (m_bit + (n_bit - 1)); j++)
            {
                // Storing all the elements as zero in 2d matrix
                arr2D[i][j] = 0;
            }
        }

        int p = 0;
        int q = 0;
        int z = (m_bit + (n_bit - 1)) - 1;


        for (int i = 0; i < n_bit; i++)
        {
            for (int x = z - i; p < m_bit && x >= 0; x--)
            {
                if (*(arrm + p) == 0 && *(arrn + q) == 0)
                    arr2D[i][x] = 0;
                else if (*(arrm + p) == 0 && *(arrn + q) == 1)
                    arr2D[i][x] = 0;
                else if (*(arrm + p) == 1 && *(arrn + q) == 0)
                    arr2D[i][x] = 0;
                else if (*(arrm + p) == 1 && *(arrn + q) == 1)
                    arr2D[i][x] = 1;
                
                p = p + 1;
                cout << "p and q: " << p << " " << q << endl;
            }
            p = 0;
            q++;
            cout << endl;
        }

        cout << endl
             << "2D array printing: " << endl;
        for (int i = 0; i < n_bit; i++)
        {
            for (int j = 0; j < (m_bit + (n_bit - 1)); j++)
            {
                // Storing all the elements as zero in 2d matrix
                cout << " " << arr2D[i][j];
            }
            cout << endl;
        }

         


    }
};

int main()
{
    int m, n;

    cout << "Enter the integers m and n: " << endl;
    cin >> m >> n;

    binaryMul b1;
    b1.bin_mul(m, n);

    return 0;
}