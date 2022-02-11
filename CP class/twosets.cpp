#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int arr1[(n / 2) + 1];
    arr1[0] = 1;
    arr1[1] = 2;

    long long int arr2[(n / 2)];
    arr2[0] = 3;

    if (n == 3)
    {
        cout << "YES" << '\n';
        cout << "2" << '\n'
             << "1 2" << '\n';
        cout << "1" << '\n'
             << "3" << '\n';
    }
    else if(n==4){
        cout << "YES" << '\n';
        cout << "2" << '\n'
             << "1 4" << '\n';
        cout << "2" << '\n'
             << "2 3" << '\n';
    }
    else if(n%3 == 1){

    }

    return 0;
}