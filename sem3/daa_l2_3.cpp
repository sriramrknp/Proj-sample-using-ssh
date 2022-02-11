// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding triplets problem
// Lab 2, 3rd problem
/* Program to find the triplest in the array, whoose sum is equal to an integer */

#include <iostream>
#include <climits>
using namespace std;

//class
class tripletSum
{
private: // Access specifiers, private
  int X, sum;

public: // Access specifiers, public
  // Default constructor
  tripletSum()
  {
    X = 0;
    sum = 0;
  }

  /* Function declaration to find triplets */
  void findingTriplets(int size)
  {
    int arr[size];
    int i, j, k, count = 0;

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

    /* Takes the two elements set from the subsets of the set whose elements are
             the elements of the array, now finds the sum for each of the set with every other
             element in the array */
    for (i = 0; i < size; i++)
    {
      for (j = i + 1; j < size; j++)
      {
        sum = sum + arr[i] + arr[j];
        for (k = 0; k < size; k++)
        {
          if (k != i && k != j && (sum + arr[k]) == X)
          {
            cout << "The triplets are: " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            count++;
          }
        }
        sum = 0;
      }
      sum = 0;
    }

    if (count == 0)
    {
      cout << "There is no triplets in the array, which sum is equal to " << X << endl;
    }
  }
};

// Mmain program
int main()
{
  cout << endl;
  int size;
  tripletSum arr1; // Creating a object

  cout << "Enter the array size: " << endl;
  cin >> size;
  if (size < 0 || size > INT_MAX)
  {
    cout << "Sorry!, The entered size is invalid please try again" << endl;
    exit(0);
  }

  arr1.findingTriplets(size);

  cout << endl;
  return 0;
}
