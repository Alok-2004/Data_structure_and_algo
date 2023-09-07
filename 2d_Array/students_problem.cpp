#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int m; 
    cout<<"Enter the number of students: ";
    cin>>m;

    int n; 
    cout<<"Enter the number of marks: ";
    cin>>n;

    int arr[m][n];

    cout<<"Enter the data: "<<endl;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i<m; i++) // for rows
    {
        for(int j = 0; j<n; j++)// for columns
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

