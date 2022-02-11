// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// Rain water problem
// Lab 2, 1st problem

#include<iostream>
using namespace std;
class water
{
    //data members
   int arr[25],n;
   //member function
 public:
  int trapped_water(int arr[],int n){

      if(n<=2){
      return 0;
      }
      else{
        //declaration of left and right arrays for finding heights
            int Left[n],Right[n];  
           int totalwater=0;
          //assigning left first element to array first element
           Left[0]=arr[0]; 
           //filling left array
           for(int i=1;i<n;i++)
           
             Left[i]=max(Left[i-1],arr[i]);   
           
             Right[n-1]=arr[n-1];
      
             //filling right array
              for(int i=n-2;i>=0;i--)
              
                Right[i]=max(Right[i+1],arr[i]); 
              
            //calculating trapped water
            //amount of water on the ith term is equal to min(Left[i],Right[i])-arr[i]
            for(int i=0;i<n;i++)
            
            totalwater=totalwater+min(Left[i],Right[i])-arr[i];
        
        return (totalwater);
      }
  }

};

// Main program
int main()
{   int arr[25];
     int n;
     cout<<"enter the no of array elements:";
     cin>>n;
     cout<<"enter the heights of each blocks:";
     for(int i=0;i<n;i++)
     {
       cin>>arr[i];
     }
       water obj;
      
       cout<<"the total water is:"<< obj.trapped_water(arr,n)<<endl;
    return 0;
}
