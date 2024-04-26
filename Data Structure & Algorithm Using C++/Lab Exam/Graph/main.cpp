#include <iostream>
using namespace std;
int main()
{

    int row;
    int colum;
    cout << "Enter no of rows \n";
    cin >> row;
    cout << "Enter no of colum \n";
    cin >> colum;

    int Graph[row][colum];
for (int i = 0; i < row; i++)
{    
    for (int j = 0; j < colum; j++)
    { 
    cin>>Graph[i][j];
    
    }
    
}

for (int i = 0; i < row; i++)
{
    

    for (size_t j = 0; j < colum; j++)
    {  
        if(Graph[i][j]==1)
        {
            cout<<j<<" is Adjecent of "<< i<< i+1<<endl;
        }
    }
    
}



    return 0;
}