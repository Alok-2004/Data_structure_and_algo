#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
int main()
{   
    int m = 2;
    int n = 3;
    int a[m][n] = {1,2,3,4,5,6};

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
// Just start printing from coloumn instead of row
    int transpose[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            transpose[i][j] = a[j][i];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}