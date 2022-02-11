// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// finding sub arrays
// Lab 2, 4th problem

#include <iostream>
#include <climits>
using namespace std;

class subArraysSum
{
private:
  int sum;

public:
  subArraysSum()
  {
    sum = 0;
  }

  void arraysSum(int size)
  {
    int arr[size];
    int i, j, k;

    cout << "Enter the " << size << " integers: " << endl;
    for (i = 0; i < size; i++)
    {
      cin >> arr[i];
    }

    // Logic is here, to find the sum of the sub arrays
    cout << "The sub-arrays sum is: " << endl;

    for (i = 0; i < size; i++)
    {
      for (j = i; j < size; j++)
      {
        cout << "sub-array: [";

        for (k = i; k <= j; k++)
        {
          cout << arr[k];
          if (k != j)
          {
            cout << ",";
          }
        }

        cout << "]" << endl;
        sum = sum + arr[j];
        cout << "  Sum: " << sum << " ";
        cout << endl;
      }
      cout << endl;
      sum = 0;
    }

    cout << endl;
  }
};

int main()
{
  cout << endl;
  int size;

  subArraysSum arr1;

  cout << "Enter the array size: " << endl;
  cin >> size;
  if (size < 0 || size > INT_MAX)
  {
    cout << "Sorry!, The entered size is invalid please try again" << endl;
    exit(0);
  }

  arr1.arraysSum(size);
  return 0;
}