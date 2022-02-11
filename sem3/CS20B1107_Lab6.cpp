/* CS20B1107, CHEERLA SRIRAM REDDY */
/* Program to sort two merged linked lists into single list(sorted) */


#include <iostream>
#include<climits>
using namespace std;

// class
class linkedlist
{
    private:
      //linked list data
      int data;
      
      //linked list pointer which points to node
      linkedlist *next;
       int num = 1, count1 =1, count2 =1;
        int countm1 = 1, countm2 = 1;
    public:
      linkedlist()
      {
        
      }
      
      //insert function declaration, inserts into linkedlist 
      void insert(linkedlist *node1, linkedlist *node2)
      {
          int num = 1, count1 =1, count2 =1;
          
          
          while(num == 1 || num == 2)
          {
             cout << "Enter 1 to insert in list 1, 2 to insert in 2 and any other to quit:" << endl;       
             cin >> num;
             if(num == 1)
             {
                if(count1 == 1)
                {
                   cout << "Enter elements in sorted order in list 1:" << endl;   
                   cin >> node1->data;
                   node1->next = NULL;
                   count1++;
                }
                else
                {
                   linkedlist *ptr1 = new linkedlist;
                   cout << "Enter elements in sorted order in list 1:" << endl;
                   cin >> ptr1->data;
                   ptr1->next = NULL;
                   node1->next = ptr1;
                   node1 = ptr1;
                }
             }
          
             if(num == 2)
             {
                if(count2 == 1)
                {
                   cout << "Enter elements in sorted order in list 2:" << endl;   
                   cin >> node2->data;
                   node2->next = NULL;
                   count2++;
                }
                else{
                   linkedlist *ptr2 = new linkedlist;
                   cout << "Enter elements in sorted order in list 2:" << endl;
                   cin >> ptr2->data;
                   ptr2->next = NULL;
                   node2->next = ptr2;
                   node2 = ptr2;
                }
              }
           }
      }
      
      void deleteElement(linkedlist *node1, linkedlist *node2)
      {
          //linkedlist *node1 = head1;
          //linkedlist *node2 = head2;
          
          linkedlist *slownode1 = node1;
          linkedlist *slownode2 = node2;
          
          int pos1, pos2, i = 0;
          cout << endl;
          
          while(num == 1 || num == 2)
          {
              cout << "Enter 1 to delete in list 1, 2 to delete in 2 and any other to exit: " << endl;
              cin >> num;
              
              if(num == 1)
              {
                  cout << "Enter at which position you want to delete: " << endl;
                  cin >> pos1;
                  
                  if(pos1 == 1)
                  {
                     node1 = node1->next;
                     delete slownode1;
                  }
                  for(i=0; i<(pos1-1); i++)
                  {
                      slownode1 = node1;
                      cout << "i= " << i <<endl;
                      node1 = node1->next;
                  }
                  if(pos1 != 1)
                  {
                  delete slownode1;
                  }
              }
              
              if(num == 2)
              {
                  cout << "Enter at which position you want to delete: " << endl;
                  cin >> pos2;
                  
                  if(pos2 == 1)
                  {
                     node2 = node2->next;
                     delete slownode1;
                  }
                  for(i=0; i<(pos2-1); i++)
                  {
                      slownode2 = slownode2->next;
                      node2 = node2->next;
                  }
                  
                  if(pos2 != 1)
                  {
                  delete slownode2;
                  }
                 
              }
          }
 
      }
      
      
      void display(linkedlist *node1, linkedlist *node2, linkedlist *node)
      {
          //int num = 1;
          cout << endl;
          linkedlist *temp1 = node1;
          linkedlist *temp2 = node1;
          linkedlist *temp = node;
          // linkedlist *node1 = head1;
           //linkedlist *node2 = head2;
           //linkedlist *node = head;
           
          while(num ==1 || num == 2 || num == 3)
          {
              cout << "Enter 1 to display list 1, 2 to display 2, 3 to merged and any other to quit:" << endl;       
              cin >> num;
              
              if(num == 1)
              {
                  cout << "************List-1***********: " << endl;
                  while(node1 != NULL)
                  {
                      cout << "    " << node1->data ;
                      node1 = node1->next;
                  }
                  node1 = temp1;
                  cout << endl;
                  cout << endl;
              }
              if(num == 2)
              {
                  cout << "************List-2***********: " << endl;
                  while(node2 != NULL)
                  {
                      cout << "    " << node2->data ;
                      node2 = node2->next;   
                  }
                  node2 = temp2;
                  cout << endl;
                  cout << endl;
              }
              if(num == 3)
              {
                  cout << "************Merged List***********: " << endl;
                  while(node != NULL)
                  {
                      cout << "    " << node->data ;
                      node = node->next;   
                  }
                  node = temp;
                  cout << endl;
                  cout << endl;
              }
          }
      }
      
      //merge function declaration, which merges two entered linkedlists
      void merge(linkedlist *node1, linkedlist *node2, linkedlist *node)
      {
          //linkedlist *node1 = head1;
          //linkedlist *node2 = head2;
          //linkedlist *node = head;
          
          
          while(node1 != NULL || node2 != NULL)
          {
          
            if(node1 != NULL && node2 != NULL)
            {
                if(node1->data < node2->data)
                {
                   if(countm1 == 1)
                   {
                       node->data = node1->data;
                       node->next = NULL;
                       countm1++;
                       node1 = node1->next;
                       cout << "node data 1 " << node->data << endl; 
                   }
                   else
                   {
                      linkedlist *ptr1 = new linkedlist;
                      ptr1->data = node1->data;
                      ptr1->next = NULL;
                      node->next = ptr1;
                      node = ptr1;
                      node1 = node1->next;
                      cout << "node data 1 " << node->data << endl;
                   }  
                }
            }
            else if(node2 != NULL)
            {
                 if(countm1 == 1)
                 {
                    node->data = node2->data;
                    node->next = NULL;
                    countm1++;
                    node2 = node2->next;
                    cout << "node data" << node->data << endl;
                 }
                 else
                 {
                    linkedlist *ptr3 = new linkedlist;
                    ptr3->data = node2->data;
                    ptr3->next = NULL;
                    node->next = ptr3;
                    node = ptr3;
                    node2 = node2->next;
                    cout << "node data" << node->data << endl;
                 }
            }
           
           
            if(node1 != NULL && node2 != NULL)
            {
                if(node1->data >  node2->data)
                { 
                   if(countm1 == 1)
                   {
                      node->data = node2->data;
                      node->next = NULL;
                      node2 = node2->next;
                      countm1++;
                      cout << "node data 2 " << node->data << endl;
                   }    
                   else
                   {
                       linkedlist *ptr2 = new linkedlist;
                       ptr2->data = node2->data;
                       ptr2->next = NULL;
                       node->next = ptr2;
                       node = ptr2;
                       node2 = node2->next;
                       cout << "node data 2 " << node->data << endl;
                    }
               }
            }
            else if(node1 != NULL)
            {
                if(countm1 == 1)
                {
                   node->data = node1->data;
                   node->next = NULL;
                   countm1++;
                   node1 = node1->next;
                   cout << "node data" << node->data << endl;
                }
                else
                {
                    linkedlist *ptr4 = new linkedlist;
                    ptr4->data = node1->data;
                    ptr4->next = NULL;
                    node->next = ptr4;
                    node = ptr4;
                    node1 = node1->next;
                    cout << "node data" << node->data << endl;
                }
             }
          }
      }
      
};


//Main program
int main()
{
     int choice = 1;
     linkedlist list1;
     
     linkedlist *head1 = new linkedlist;
     linkedlist *head2 = new linkedlist;
     linkedlist *head = new linkedlist;
     
     while(choice > 0)
     {
         cout << "Enter the choice: " << endl;
         cout << "  1. Insert, 2. Delete, 3. Display, 4. Merge, 5. Exit" << endl;
         cin >> choice;
         
         switch(choice)
         {
             case 1:
                 list1.insert(head1, head2);
                 break;
             case 2:
                 list1.deleteElement(head1, head2);
                 break;
             case 3:
                 list1.display(head1, head2, head);
                 break;
             case 4:
                  list1.merge(head1, head2, head);
                  break;
             case 5: 
                 exit(0);
         }
      } 
    return 0;
}    


