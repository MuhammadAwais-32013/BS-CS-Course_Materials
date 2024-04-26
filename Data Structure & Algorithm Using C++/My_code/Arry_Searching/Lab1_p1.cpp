 #include<iostream>
using namespace std;

//*************************Fuctions Declarations**************************

/*write a Function name intilizer  that will an arry,
its size  as parametrs, this function should initilize the declaraed arry*/
void intilizer(int arr[], int size);// Arry intilizer 

/*write a Function name Display  that will an arry,
its size  as parametrs, this function should display initilized  values of arry*/
void Display(int arr[], int size);// Arry Display

/*write a Function name evenNo  that will an arry,
its size  as parametrs, this function should find Even number in the Arry*/
void evenNo(int arr[], int size);// Even Finder 

/*write a Function name LargestLoc  that will an arry,
its size  as parametrs, this function should display the Index of largest in the Arry*/
int largestLoc(int arr[], int size);// Largest loction Finder 

/*write a Function name Swap  that will an arry,
and two indices   as parametrs, this function swap the indices of Arry*/
void Swap(int arr[], int indexA,int indexB);// Swap indices 

/*write a Function name linear search  that will an arry,
size of arry and key to find  as parametrs, this function search a entered key in the Arry 
and return index if found else return -1*/
int linearSearch(int arr[], int size,int key);// linear Search

/*write a Function name Binary search  that will an arry,
size of arry and key to find  as parametrs, this function search a entered key in the Arry*/
void LinearSearch(int arr[], int size,int key);// linear Search

/*write a Function name Binary search  that will an arry,
size of arry and key to find  as parametrs, this function search a entered key in the Arry */
int binarySearch(int arr[], int size,int key);// Binary Search

/*write a Function name binary search  that will an arry,
size of arry and key to find  as parametrs, this function search a entered key in the Arry*/
void binarysearch(int arr[], int size, int key);// binary search

/*write a Function name selection sort  that will an arry,
size of arry  as parametrs, this function sort the arry in Acending order*/
void selectionSort(int arr[], int size);// Section sort

/*write a Function name bubble sort  that will an arry,
size of arry  as parametrs, this function sort the arry in Acending order*/
void bubbleSort(int arr[], int size);// bubble sort

/*write a Function name bubble sort  that will an arry,
size of arry  as parametrs, this function sort the arry in Acending order*/
void insertionSort(int arr[], int size);// insertion sort
int main()
{    
    int size=0;
    cout<<"Declare the size of Arry "<<endl;
    cin>>size;
    int arry[size];
    int choice=0;
    int A=0;
    int B=0;
    int key=0;
do
{

    cout<<"Press 1 to initialize array \n";
	 //cout<<"Press 2 to Display array \n";
    //cout<<"Press 3 to display even numbers of array \n";
     //cout<<"Press 4 to swapping indices \n";
	//cout<<"Press 5 to Find the index with largest value \n";
	//cout<<"Press 6 to search array through LinearSearch \n";
	 //cout<<"Press 7 to search array through BinarySearch \n";
	//cout<<"Press 8 to sort an array using slectiom sort \n";
	 //cout<<"Press 9 to sort an array using Bubble sort \n";
    cout<<"Press 10 to sort an array using insertion sort \n";
	cout<<"Press 0 to exit from code\n";	
	
	cin>>choice;

    switch(choice)
{
		case 1:
			cout<<"----------Initializing array------------"<<endl;
            intilizer(arry,size);
            break;

		case 2:
			cout<<"----------Displaying array------------"<<endl;	
	        Display(arry,size);
	        break;

		case 3:
           cout<<"**************Finding***********"<<endl;
           evenNo(arry,size);
           break;

        case 4:
              cout<<"Enter the indices which are want to swap"<<endl;
              cin>>A>>B;
              cout<<"...........Swapping........."<<endl;
              Swap(arry,A,B);
              cout<<"**************Swaped*************"<<endl;
              Display(arry,size);
              break;

        case 5:
             cout<<".........Finding Largest value  Location......"<<endl;
             cout<<largestLoc(arry,size)<<endl;
             break;
            
        case 6:
             /// Complexity of linear search is O(n)
              cout<<"...........Linear Searching.........."<<endl;
              cout<<"Enter key/element "<<endl;
              cin>>key;
               LinearSearch(arry,  size, key);
            //cout<<"Entered key is on index "<<linearSearch(arry, size,key)<<endl;
              break;

        case 7:
              cout<<"...........Binary Searching.........."<<endl;
              cout<<"Enter key/element "<<endl;
              cin>>key;
              binarysearch(arry,  size,  key);
              //cout<<"Entered key is on index "<<binarySearch(arry, size,key)<<endl;
              break;

         case 8:
              cout<<"...........Selection Sort.........."<<endl;
              selectionSort(arry,size);
              cout<<"------Sorted by selection Sort----"<<endl;
              Display(arry,size);
              break;
            
         case 9:
              cout<<"...........Bubble Sort.........."<<endl;
              bubbleSort(arry,size);
              cout<<"------Sorted by Bubble Sort----"<<endl;
              Display(arry,size);
              break;

        case 10:
              cout<<"...........insertion Sort.........."<<endl;
              insertionSort(arry,size);
              cout<<"------Sorted by insertion Sort----"<<endl;
              Display(arry,size);
              break;

		case 0:
			
			exit(-1);
        
        
}// End of switch

}while (true);// End of While 
   
    return 0;
}// End of Main
  
//***********************************-->Functions Definitions--****************************************

void intilizer(int arr[], int size)
{
     
     for (int i = 1; i < size; i++)
     {
        cin>>arr[i]; 
     }
     
}// End of Initilizer 


void Display(int arr[], int size)
{
    cout<<"***********Values of  Arry********"<<endl;

     for (int i = 0; i < size; i++)
     {
        cout<<arr[i]<<endl;
     }
}// End of Display


void evenNo(int arr[], int size)
{
     cout<<"*************Even Numbers in arry***********"<<endl;

     for (int i = 0; i < size; i++)
     {
        if(arr[i]%2==0)
        {
            cout<<arr[i]<<endl;
        }
     }
}// End of evenNo

void Swap(int arr[], int indexA, int indexB)
{
    int temp; // empty
    temp=arr[indexA];
    arr[indexA]=arr[indexB];
    arr[indexB]=temp;

}// End of Swap

int largestLoc(int arr[], int size)
{
    int largest = arr[0];  
    int largestloc=0;   
    for (int i = 1; i < size; i++)
    {
        if(arr[i]>largest)  // 2 4 7 6
        {
            largest=arr[i];
            largestloc=i;
        }
    }
      return largestloc;

}// End of largestLoc 

int linearSearch(int arr[], int size,int key)
{      
    for(int i=0; i<size;i++)
    {
    if(arr[i]==key)
    {   
        return i;
    } 
    }
      return -1;

}// End of linear Search

void LinearSearch(int arr[], int size,int key)
{    
    bool check =false;
    int index=0;
  
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==key)
        {
            index=i;
            check=true;
        }

    }
      if(check==true)
      {
        cout<<"Key is found on index "<<index<<endl;
      }

      else{
        cout<<"Not Found"<<endl;
      }
}// End of Void linear search


int binarySearch(int arr[], int size,int key)
{   
    int end=size-1;
    int start=0;
 

    while(start<=end)
    {   
        int mid=(start+end)/2;

        if(arr[mid]==key)
        {
            return mid;
        }

        else if(key<arr[mid])
        {
            end=mid-1;
        }

        else
        {   
              start=mid+1;
        }
    }
    
    return -1;
}// End of Binary Search

void binarysearch(int arr[], int size, int key)
{
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;

    while (s<=e && key!=arr[mid])
    {
        if(key>arr[mid])
        {
            s=mid+1;
        }
        else if(key<arr[mid])
        {
           e=mid-1;
        }

        mid=(s+e)/2;
    }

    if(s>e)
    {
       cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }
    
}// End of Void binary Search

void selectionSort(int arr[], int size)
{  
///// 3 4 5 67 8 6 7 
    int marker=size-1;

    while (marker>0)
    {
        int largNo=largestLoc(arr,marker+1);
        Swap(arr,largNo,marker);
        marker--;
    }
    
}// End of selection Sort
  
void bubbleSort(int arr[], int size)
{
    int marker=size-1;

    while (marker>0)
    {
          for (int i = 0; i < marker; i++)
          {
            if(arr[i]>arr[i+1])
            {
                Swap(arr,i,i+1);
            }
          }
         marker--; 
    }
    
}// End of Bubble sort

void insertionSort(int arr[], int size)
{    
    /// Outer loop 
    for (int i = 1; i < size; i++)
    {
         int current=arr[i];
         int j=i-1;
         
         // Innner loop set sort element on correct position
         while (arr[j]>current && j>=0)
         {  
            Swap(arr,j,j+1);
           // arr[j+1]=arr[j];
         j--;
         }
        
         arr[j+1]=current;
    }
    

}// End of insertion sort
