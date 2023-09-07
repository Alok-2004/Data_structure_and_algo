#include<iostream>
//#include<algorithm>
//#include<climits>

using namespace std;

void swapelement(int arr[3][3],int i,int j)
{
    int temp = arr[i][j];
    arr[i][j] = arr[j][i];
    arr[j][i] = temp;
    return; 
}

int main()
{   
    int m = 3;
    int n = 3;
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };


    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
// Just start printing from coloumn instead of row

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            if( j == i) continue;
            else
            {
                swapelement(a, i, j);
            }
        }
        cout<<endl;
    }

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}