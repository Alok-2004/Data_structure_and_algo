#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
int main()
{
	int m; 
    cout<<"Enter the number of rows: ";
    cin>>m;

    int n; 
    cout<<"Enter the number of columns: ";
    cin>>n;

    int arr[m][n];

    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    int sum = 0;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            sum = sum + arr[i][j];
        }
        cout<<endl;
    }
    cout<<"Sum of elements: "<<sum;
    return 0;
}