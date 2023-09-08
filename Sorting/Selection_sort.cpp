#include<iostream>
#include<climits>
#include<vector>
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

	for(int ele : nums)
	{
		cout<<ele<<" ";
	}

	//insertion sort
	for(int i = 0; i<n; i++)
	{
		int min = INT_MAX;
		int mindx = -1;
		for(int j = i; j<n; j++)
		{
			if(nums[j] < min)
			{
				min = nums[j];
				mindx = j;
			}
		}
		swap(nums[i], nums[mindx]);
	}
	
	for(int ele : nums)
	{
		cout<<ele<<" ";
	}
}
