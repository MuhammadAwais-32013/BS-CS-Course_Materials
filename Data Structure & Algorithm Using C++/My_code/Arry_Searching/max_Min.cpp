#include<iostream>
#include<climits>
using namespace std;
int main()
{   int size=0;
    cout<<"Declare the size of Arry "<<endl;
    cin>>size;
    int arry[size];

    int maxNo=INT_MIN;
    int minNo=INT_MAX;

    for (int i = 0; i < size; i++)
    {
        cin>>arry[i];
    }

    for (int i = 0; i < size; i++)
    {   
        maxNo= max(maxNo, arry[i]);
        minNo= min(minNo, arry[i]);
        
    }
       cout<<"Max is "<<maxNo<<" "<<"Min is "<<minNo<<endl;
    
    
    return 0;
}