// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Finding max, secmax, min, secmin in array using linear approach approach
// Lab 1, 1st problem

/*To find the max, min, secmax and secmin in the array implimented using class*/

#include<iostream>
using namespace std;

//Class definition 
class array
{
   public: //public, access specifier, can be accessed directly from main

    //Function definition
    void toFindMaxMinsecMaxsecMin( int usize){
      int arr[usize]; 
      int i;
      int MAX,MIN,secMAX,secMIN;
      
      //boundary conditions
      if(usize < 4){
        cout << "\nEntered size is not appropriate, size should be >=4\n";
        exit(0);
      }
      else{
        cout << "Ënter " << usize << " integers" <<endl;
        for( i=0; i < usize ; i++){
         //inputting elements into the array   
         cin >> arr[i];
        }
      }
      
      //printing the elements in the array
      for(i=0; i < usize ; i++){
        cout << arr[i] << endl;
      }
      
      //checking wether arr[0] or arr[1] is greater
      //and assining to MAX and secMAX 
      if(arr[0] > arr[1]){
          MAX = arr[0];
          secMAX = arr[1];
      }
      else{
          MAX = arr[1];
          secMAX = arr[0];
      }

      //Now comparing the MAX and secMAX with the other elements
      //From arr[2]
      for(i=2; i < usize;i++){
        if(arr[i] > MAX){
            //Ubdating max
            secMAX = MAX;
            MAX = arr[i];
        }
        else if(arr[i] > secMAX & MAX != arr[i]){
            secMAX = arr[i];
        }
      }
       
       //checking wether arr[0] or arr[1] is less
      //and assining to MIN and secMIN 
       if(arr[0] < arr[1]){
          MIN = arr[0];
          secMIN = arr[1];
       }
      else{
          MIN = arr[1];
          secMIN = arr[0];
      }
      
      //Now comparing the MIN and secMIN with the other elements
      //From arr[2]
      for(i=2 ; i < usize;i++){
       
        if( arr[i] < MIN ){
            secMIN = MIN;
            MIN = arr[i]; 
        }
        else if( arr[i] < secMIN & MIN != arr[i]){
             //Ubdating secmin
              secMIN = arr[i];
        }
      }

      //Printing the final elements of min, max, secmin, secmax
      cout << "\nThe MAX of the array is " << MAX << endl;
      cout << "The MIN of the array is " << MIN << endl;
      cout << "The second MAX of the array is " << secMAX << endl;
      cout << "The second MIN of the array is " << secMIN << endl;
    }
};

//Main program
int main()
{
    int i;

    //Creating the object to the class named array
    array arr1;

    int MAX,MIN,secMAX,secMIN;
    int ussize;

    cout << "\nEnter the size of the array:"<< endl;
    cin >> ussize;
     
    //Sending the size to the array through calling the function in class
    arr1.toFindMaxMinsecMaxsecMin(ussize);

    return 0;
}