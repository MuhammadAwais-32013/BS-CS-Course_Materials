#include<iostream>
using namespace std;
int largestLoc(int arr[], int size);
void intilizer(int arr[], int size);
int main()
{  
     int size=0;
    cout<<"Declare the size of Arry "<<endl;
    cin>>size;
    int arry[size];
     intilizer( arry, size);

    cout<<"largest value on index "<<largestLoc(arry, size);
    return 0;
}

void intilizer(int arr[], int size)
{
    cout<<"***********Let initilize the Arry********"<<endl;
     
     for (int i = 0; i < size; i++)
     {
        cin>>arr[i];
     }
     
}// End of Initilizer 
int largestLoc(int arr[], int size)
{
    int largest = arr[0];
    int largestLoc=0;
    for (int i = 1; i < size; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
            largestLoc=i;
        }
    }
      return largestLoc;
      
}// End of largestLoc