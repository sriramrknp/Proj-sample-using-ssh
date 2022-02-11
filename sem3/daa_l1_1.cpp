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
class arraymax
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

      MAX = arr[0];
      MIN = arr[0];

      for(i=0; i < usize;i++){
        if(arr[i] > MAX){
            //Ubdating max
            MAX = arr[i];
        }
        
        if(arr[i] < MIN){
            //Ubdating min
            MIN = arr[i];
        }
      } 
    
      secMAX = MIN;
      secMIN = MAX;

      for(i=0; i < usize;i++){
       
        if( arr[i] < MAX & arr[i] > secMAX){
            //Ubdating secmax
            secMAX = arr[i];
          
        }
        if( arr[i] > MIN & arr[i] < secMIN){
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
    arraymax arr1;

    int MAX,MIN,secMAX,secMIN;
    int ussize;

    cout << "\nEnter the size of the array:"<< endl;
    cin >> ussize;
     
    //Sending the size to the array through calling the function in class
    arr1.toFindMaxMinsecMaxsecMin(ussize);

    return 0;
}