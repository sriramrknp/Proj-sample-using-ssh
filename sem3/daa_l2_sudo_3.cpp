// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding triplets problem
// Lab 2, 3rd problem

#include <iostream>
#include <climits>
using namespace std;

class tripletSum
{
private:
  int X, sum;

public:
  tripletSum()
  {
    X = 0;
    sum = 0;
  }
  void findingTriplets(int size)
  {
    int arr[size];
    int i, j, k;

    cout << "Enter the " << size << " integers: " << endl;
    for (i = 0; i < size; i++)
    {
      cin >> arr[i];
    }

    cout << "Enter the integer X: " << endl;
    cin >> X;
    if (X < 0 || X > INT_MAX)
    {
      cout << "Sorry!, The entered size is invalid please try again" << endl;
      exit(0);
    }

    for (i = 0; i < size; i++)
    {
      for (j = i + 1; j < size; j++)
      {
        sum = sum + arr[i] + arr[j];

        //cout << sum << " " << endl;
        for (k = 0; k < size; k++)
        {
          while (k != i && k != j && k < size)
          {
            //cout << "While " << endl;
            if (X == (sum + arr[k]))
            {
              cout << "The triplets are: " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
              //cout << k << endl;
              exit(0);
            }

            k++;
            cout << k << endl;
          }
        }
      }
      sum = 0;
    }
  }
};

int main()
{
  cout << endl;
  int size;
  tripletSum arr1;

  cout << "Enter the array size: " << endl;
  cin >> size;
  if (size < 0 || size > INT_MAX)
  {
    cout << "Sorry!, The entered size is invalid please try again" << endl;
    exit(0);
  }

  arr1.findingTriplets(size);

  return 0;
}
