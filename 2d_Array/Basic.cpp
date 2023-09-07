#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int arr[3][4] = { {1,2,3,4}, {4,5,6,4}, {7,8,9,3}};// or{1,2,3,4,5,6,7,8,9}
    // rows -> 3, 0-2
    // column -> 4, 0-3
    for(int i = 0; i<3; i++) // for rows
    {
        for(int j = 0; j<4; j++)// for columns
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
