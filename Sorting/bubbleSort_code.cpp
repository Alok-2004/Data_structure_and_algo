#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> nums(5);
	for(int i = 0; i<5; i++)
	{
		cin>>nums[i];
	}
	
	int  n = 5;
	// Bubble sort
	/*
	for(int i = 0; i<n-1; i++)
	{
		// Traversing
		for(int j = 0; j<n-1-i; j++) // here j<n-1 will also work but will take more time
		{
			if(nums[j] > nums[j+1])
			{
				swap(nums[j], nums[j+1]); // Swap is inbuilt function
			}
		}
	}
	*/
	
	//Better Bubble sort 
	
	bool flag = true;
	for(int i = 0; i<n-1; i++)
	{
		// Traversing
		for(int j = 0; j<n-1-i; j++) // here j<n-1 will also work but will take more time
		{
			if(nums[j] > nums[j+1])
			{
				swap(nums[j], nums[j+1]); // Swap is inbuilt function
				flag = false;
			}
		if(flag == true) break;// This means swap didnt happen and the array id sorted
		}
	}
	
	for(int i = 0; i<5; i++)
	{
		cout<<nums[i]<<" ";
	}
	return 0;
}
