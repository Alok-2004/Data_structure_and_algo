#include<iostream>
#include<vector>

using namespace std;

int main()
{
    	
	int  n = 5;
    int nums[n];
	for(int i = 0; i<n; i++)
	{
		cin>>nums[i];
	}

    cout<<"Original array: ";
    for(int i = 0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    for(int i = 1; i<n; i++)
    {
        int j = i;
        while(j>0 && nums[j] < nums[j-1])
        {
            swap(nums[j], nums[j-1]);
            j--;
        }
    }

    cout<<"Sorted array: ";
    for(int i = 0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}